#ifndef OSU_DECODER_H
#define OSU_DECODER_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <map>
#include <vector>
#include <Windows.h>

#include "generalsection.h"
#include "metadatasection.h"
#include "editorsection.h"
#include "difficultysection.h"
#include "TimingPoint.h"
#include "HitObject.h"

class OsuDecoder
{
public:
    enum ResultCode
    {
        success = 0,

        invalidFileExtension = 2,
        invalidFilePath
    };

    OsuDecoder(const char *mapPath);

    OsuDecoder::ResultCode getStatus();

    GeneralSection general;

    MetadataSection metadata;

    EditorSection editor;

    DifficultySection difficulty;

    std::vector<TimingPoint> timingPoints;

    std::vector<HitObject> hitObjects;

private:
    const char *m_osuExtension;

    OsuDecoder::ResultCode m_status;

    std::ifstream m_mapFile;

    std::map<std::string, std::vector<std::string>> m_sections;

    bool isCorrectExtension(const char *path, const char *extension);

    OsuDecoder::ResultCode decode();

protected:
};

#endif // !OSU_DECODER_H
