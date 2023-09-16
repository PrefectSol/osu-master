#ifndef CURSOR_HANDLER_H
#define CURSOR_HANDLER_H

#define _USE_MATH_DEFINES

#pragma comment (lib, "user32.lib")

#include <iostream>
#include <cmath>
#include <vector>

class CursorHandler
{
public:
    CursorHandler();

    void moveToPoint(int x, int y, int time, int circleRadius);

    void moveToCurve(int x, int y, int time, int circleRadius, int repeats, int repeatDuration,
                     const std::vector<std::pair<int, int>> &curvePoints, bool isRoundType);

    void getPosition(int *x, int *y);

    void update();

private:
    int m_currentX, m_currentY;

protected:
};

#endif // !CURSOR_HANDLER_H
