#ifndef METADATA_SECTION_H
#define METADATA_SECTION_H

#include "section.h"

class MetadataSection : public Section
{
public:
    void parse(std::vector<std::string> &lines) override;

    std::string title;
    std::string titleUnicode;
    std::string artist;
    std::string artistUnicode;
    std::string creator;
    std::string version;
    std::string source;
    std::string beatmapID;
    std::string beatmapSetID;
};

#endif // !METADATA_SECTION_H
