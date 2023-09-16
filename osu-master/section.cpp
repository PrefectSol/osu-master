#include "section.h"
#include "utilities.h"

std::string Section::getAttribute(std::string key)
{
    return this->m_sectionMap[key].size() ? this->m_sectionMap[key] : "N/A";
}

void Section::loadAttributes(const std::vector<std::string> &lines)
{
    for (const std::string &line : lines)
    {
        if (line.find(":") == std::string::npos)
        {
            continue;
        }

        std::vector<std::string> splitLine = Utilities::split(line, ':');
        if (splitLine.size() > 1)
        {
            this->insertAttribute(splitLine[0], Utilities::trim(splitLine[1]));
        }
    }
}

void Section::insertAttribute(std::string key, std::string value)
{
    this->m_sectionMap[key] = value;
}
