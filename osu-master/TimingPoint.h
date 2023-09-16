#ifndef TIMING_POINT_H
#define TIMING_POINT_H

#include <cstdint>
#include <cmath>

typedef struct TimingPoint
{
    std::int32_t time;
    std::float_t beatLength;
    std::int32_t meter;
    std::int32_t sampleSet;
    std::int32_t sampleIndex;
    std::int32_t volume;
    std::int32_t uninherited;
    std::int32_t effects;
} TimingPoint;

#endif // !TIMING_POINT_H
