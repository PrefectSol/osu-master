#ifndef EDITOR_SECTION_H
#define EDITOR_SECTION_H

#include "section.h"

class EditorSection : public Section
{
public:
    void parse(std::vector<std::string> &lines) override;

    std::string distanceSpacing;
    std::string beatDivisor;
    std::string gridSize;
    std::string timelineZoom;
};

#endif // !EDITOR_SECTION_H
