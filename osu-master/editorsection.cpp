#include "editorsection.h"

void EditorSection::parse(std::vector<std::string> &lines)
{
    this->loadAttributes(lines);

    this->distanceSpacing = this->getAttribute("DistanceSpacing");
    this->beatDivisor = this->getAttribute("BeatDivisor");
    this->gridSize = this->getAttribute("GridSize");
    this->timelineZoom = this->getAttribute("TimelineZoom");
}
