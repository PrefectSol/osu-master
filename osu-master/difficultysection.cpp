#include "difficultysection.h"

void DifficultySection::parse(std::vector<std::string> &lines)
{
    this->loadAttributes(lines);

    this->hpDrainRate = this->getAttribute("HPDrainRate");
    this->circleSize = this->getAttribute("CircleSize");
    this->overallDifficulty = this->getAttribute("OverallDifficulty");
    this->approachRate = this->getAttribute("ApproachRate");
    this->sliderMultiplier = this->getAttribute("SliderMultiplier");
    this->sliderTickRate = this->getAttribute("SliderTickRate");
}
