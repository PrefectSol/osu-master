#ifndef HIT_OBJECT_H
#define HIT_OBJECT_H

#include <cstdint>
#include <cmath>
#include <vector>

enum class HitObjectType : std::int32_t
{
    HIT_CIRCLE = 1 << 0,
    SLIDER = 1 << 1,
    SPINNER = 1 << 3,
};

enum class HitSoundType : std::int32_t
{
    NORMAL = 0,
    WHISTLE = 1,
    FINISH = 2,
    CLAP = 3
};

typedef struct HitObject
{
    std::int32_t x = 0;
    std::int32_t y = 0;
    std::int32_t time = 0;
    HitObjectType type = HitObjectType::HIT_CIRCLE;
    HitSoundType hitSound = HitSoundType::NORMAL;
    char curveType = 'B';
    std::vector<std::pair<std::int32_t, std::int32_t>> curvePoints = {};
    std::int32_t repeats = 0;
    std::double_t pixelLength = 0.0;
} HitObject;

#endif // !HIT_OBJECT_H
