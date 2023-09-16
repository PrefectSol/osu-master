#ifndef GENERAL_SECTION_H
#define GENERAL_SECTION_H

#include "section.h"

class GeneralSection : public Section
{
public:
    void parse(std::vector<std::string> &lines) override;

    std::string audioFilename;
    std::string audioLeadIn;
    std::string previewTime;
    std::string countdown;
    std::string sampleSet;
    std::string stackLeniency;
    std::string mode;
    std::string letterboxInBreaks;
    std::string storyFireInFront;
    std::string useSkinSprites;
    std::string alwaysShowPlayfield;
    std::string overlayPosition;
    std::string skinPreference;
    std::string epilepsyWarning;
    std::string countdownOffset;
    std::string specialStyle;
    std::string widescreenStoryboard;
    std::string samplesMatchPlaybackRate;
};

#endif // !GENERAL_SECTION_H
