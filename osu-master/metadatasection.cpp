#include "metadatasection.h"

void MetadataSection::parse(std::vector<std::string> &lines)
{
    this->loadAttributes(lines);

    this->title = this->getAttribute("Title");
    this->titleUnicode = this->getAttribute("TitleUnicode");
    this->artist = this->getAttribute("Artist");
    this->artistUnicode = this->getAttribute("ArtistUnicode");
    this->creator = this->getAttribute("Creator");
    this->version = this->getAttribute("Version");
    this->source = this->getAttribute("Source");
    this->beatmapID = this->getAttribute("BeatmapID");
    this->beatmapSetID = this->getAttribute("BeatmapSetID");
}
