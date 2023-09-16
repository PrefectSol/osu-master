#ifndef DIFFICULTY_SECTION_H
#define DIFFICULTY_SECTION_H

#include <string>
#include <vector>

#include "section.h"

class DifficultySection : public Section
{
public:
    void parse(std::vector<std::string> &lines) override;

    std::string hpDrainRate;
    std::string circleSize;
    std::string overallDifficulty;
    std::string approachRate;
    std::string sliderMultiplier;
    std::string sliderTickRate;
};

#endif // !DIFFICULTY_SECTION_H
