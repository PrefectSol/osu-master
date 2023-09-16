#include "cursorhandler.h"
#include <Windows.h>

CursorHandler::CursorHandler()
    : m_currentX(-1), m_currentY(-1)
{
    update();
}

void CursorHandler::update()
{
    POINT pos;
    GetCursorPos(&pos);

    m_currentX = pos.x;
    m_currentY = pos.y;
}

void CursorHandler::moveToPoint(int x, int y, int time, int circleRadius)
{
    int deltaX = x - m_currentX;
    int deltaY = y - m_currentY;

    int distance = sqrt(deltaX * deltaX + deltaY * deltaY);

    for (; time > 0 && distance > circleRadius; time--)
    {
        m_currentX += deltaX / time;
        m_currentY += deltaY / time;

        SetCursorPos(m_currentX, m_currentY);
        Sleep(1);

        update();

        deltaX = x - m_currentX;
        deltaY = y - m_currentY;

        distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    }
}

std::vector<std::pair<int, int>> getCirclePoints(const std::vector<std::pair<int, int>> &points, int precision)
{
    std::vector<std::pair<int, int>> circlePoints;

    const int p1x = points[0].first;
    const int p1y = points[0].second;

    const int p2x = points[1].first;
    const int p2y = points[1].second;

    const int p3x = points[2].first;
    const int p3y = points[2].second;

    const int xCenter = ((p2y - p1y) * (p3x * p3x - p1x * p1x + p3y * p3y - p1y * p1y) -
                         (p3y - p1y) * (p2x * p2x - p1x * p1x + p2y * p2y - p1y * p1y)) /
                        (2 * ((p2x - p1x) * (p3y - p1y) - (p3x - p1x) * (p2y - p1y)));

    const int yCenter = ((p3x - p1x) * (p2x * p2x - p1x * p1x + p2y * p2y - p1y * p1y) -
                         (p2x - p1x) * (p3x * p3x - p1x * p1x + p3y * p3y - p1y * p1y)) /
                        (2 * ((p2x - p1x) * (p3y - p1y) - (p3x - p1x) * (p2y - p1y)));

    const int radius = sqrt((p1x - xCenter) * (p1x - xCenter) + (p1y - yCenter) * (p1y - yCenter));
    const double angleIncrement = 2.0 * M_PI / precision;

    for (int i = 0; i < precision; i++)
    {
        const double angle = i * angleIncrement;

        const int x = xCenter + radius * cos(angle);
        const int y = yCenter + radius * sin(angle);

        circlePoints.push_back({ x, y });
    }

    return circlePoints;
}

void CursorHandler::moveToCurve(int x, int y, int time, int circleRadius, int repeats, int repeatDuration,
                                const std::vector<std::pair<int, int>> &curvePoints, bool isRoundType)
{
    std::vector<std::pair<int, int>> slider = curvePoints;

    if (isRoundType)
    {
        slider = getCirclePoints(curvePoints, repeatDuration);
    }

    const int pointsCount = slider.size();
    const int slideTime = repeatDuration / pointsCount;

    moveToPoint(x, y, time, circleRadius);

    for (int i = 0; i < repeats; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 1; j < pointsCount; j++)
            {
                moveToPoint(slider[j].first, slider[j].second, slideTime, circleRadius);
            }
        }
        else
        {
            for (int j = pointsCount - 2; j >= 0; j--)
            {
                moveToPoint(slider[j].first, slider[j].second, slideTime, circleRadius);
            }
        }
    }
}

void CursorHandler::getPosition(int *x, int *y)
{
    POINT pos;
    GetCursorPos(&pos);

    *x = pos.x;
    *y = pos.y;
}

