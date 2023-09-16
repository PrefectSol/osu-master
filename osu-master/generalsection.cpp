#include "generalsection.h"

void GeneralSection::parse(std::vector<std::string> &lines)
{
    this->loadAttributes(lines);

    this->audioFilename = this->getAttribute("AudioFilename");
    this->audioLeadIn = this->getAttribute("AudioLeadIn");
    this->previewTime = this->getAttribute("PreviewTime");
    this->countdown = this->getAttribute("Countdown");
    this->sampleSet = this->getAttribute("SampleSet");
    this->stackLeniency = this->getAttribute("StackLeniency");
    this->mode = this->getAttribute("Mode");
    this->letterboxInBreaks = this->getAttribute("LetterboxInBreaks");
    this->storyFireInFront = this->getAttribute("StoryFireInFront");
    this->useSkinSprites = this->getAttribute("UseSkinSprites");
    this->alwaysShowPlayfield = this->getAttribute("AlwaysShowPlayfield");
    this->overlayPosition = this->getAttribute("OverlayPosition");
    this->skinPreference = this->getAttribute("SkinPreference");
    this->epilepsyWarning = this->getAttribute("EpilepsyWarning");
    this->countdownOffset = this->getAttribute("CountdownOffset");
    this->specialStyle = this->getAttribute("SpecialStyle");
    this->widescreenStoryboard = this->getAttribute("WidescreenStoryboard");
    this->samplesMatchPlaybackRate = this->getAttribute("SamplesMatchPlaybackRate");
}
