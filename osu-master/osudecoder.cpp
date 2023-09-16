#include "osudecoder.h"
#include "utilities.h"

OsuDecoder::OsuDecoder(const char *mapPath)
    : m_osuExtension(".osu"), m_status(OsuDecoder::ResultCode()), m_mapFile()
{
    if (!isCorrectExtension(mapPath, m_osuExtension))
    {
        m_status = OsuDecoder::ResultCode::invalidFileExtension;

        return;
    }

    m_mapFile = std::ifstream(mapPath, std::ios::binary);

    if (!m_mapFile.is_open() || !m_mapFile.good())
    {
        m_status = OsuDecoder::ResultCode::invalidFilePath;

        return;
    }

    m_status = decode();
}

OsuDecoder::ResultCode OsuDecoder::getStatus()
{
    return m_status;
}

bool OsuDecoder::isCorrectExtension(const char *path, const char *extension)
{
    const std::filesystem::path file(path);

    return !file.extension().compare(extension);
}

OsuDecoder::ResultCode OsuDecoder::decode()
{
    std::string currentLine = "N/A";

    std::getline(m_mapFile, currentLine);
    while (std::getline(m_mapFile, currentLine))
    {
        currentLine = Utilities::trim(currentLine);
        static std::string currentSection = "General";

        if (currentLine.find("[") != std::string::npos && currentLine.find("]") != std::string::npos)
        {
            currentSection = Utilities::split(Utilities::split(currentLine, '[')[1], ']')[0];
        }

        if (currentLine.size() < 3 || currentLine.find("Unicode") != std::string::npos || currentLine.find(currentSection) != std::string::npos)
        {
            continue;
        }

        this->m_sections[currentSection].push_back(currentLine);
    }

    this->general.parse(this->m_sections["General"]);
    this->metadata.parse(this->m_sections["Metadata"]);
    this->editor.parse(this->m_sections["Editor"]);
    this->difficulty.parse(this->m_sections["Difficulty"]);

    for (std::string objectString : this->m_sections["HitObjects"])
    {
        const std::vector<std::string> splitObject = Utilities::split(objectString, ',');

        HitObject object;
        object.x = std::stoi(splitObject[0]);
        object.y = std::stoi(splitObject[1]);
        object.time = std::stoi(splitObject[2]);
        object.type = HitObjectType(std::stoi(splitObject[3]));
        object.hitSound = HitSoundType(std::stoi(splitObject[4]));

        switch (object.type)
        {
        case HitObjectType::SLIDER:
            std::vector<std::string> splitCurvePoints = Utilities::split(splitObject[5], '|');
            splitCurvePoints.erase(splitCurvePoints.begin());

            object.curveType = splitObject[5][0];

            for (std::string pointString : splitCurvePoints)
            {
                const std::vector<std::string> splitPoint = Utilities::split(pointString, ':');
                object.curvePoints.push_back({ std::stoi(splitPoint[0]), std::stoi(splitPoint[1]) });
            }
        }

        this->hitObjects.push_back(object);
    }

    for (std::string pointString : this->m_sections["TimingPoints"])
    {
        const std::vector<std::string> splitPoint = Utilities::split(pointString, ',');

        TimingPoint point;
        point.time = std::stoi(splitPoint[0]);
        point.beatLength = std::stof(splitPoint[1]);
        point.meter = std::stoi(splitPoint[2]);
        point.sampleSet = std::stoi(splitPoint[3]);
        point.sampleIndex = std::stoi(splitPoint[4]);
        point.volume = std::stoi(splitPoint[5]);
        point.uninherited = std::stoi(splitPoint[6]);
        point.effects = std::stoi(splitPoint[7]);

        this->timingPoints.push_back(point);
    }

    return OsuDecoder::ResultCode::success;
}
