#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QApplication>
#include <QColor>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace settings
{
    inline bool isSaveData = false;

    inline bool isViewJson = false;
};
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace m_settings
{
    inline const QString dataFolder = "/appdata";

    inline const QString dataFile = "/data.dat";

    constexpr inline const int pixmapSize = 100;

    constexpr inline const int searchPageSize = 20;

    constexpr inline const int playLimit = 50;

    constexpr inline const int tableSize = 16;
};
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace m_graphics
{
    constexpr inline const QColor penColor(45, 45, 45, 255);
    constexpr inline const QColor polygonColor(190, 190, 190, 255);
    constexpr inline const QColor pointColor(30, 30, 30, 175);

    constexpr inline const int polygonSize = 100;
    constexpr inline const int polygonWidth = 4;

    constexpr inline const int streakWidth = 5;
    constexpr inline const int streakOrientCount = 5;

    constexpr inline const float statsFactor = 1.0f / 15.5f;

};
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace special
{
    const inline QString tableModeAdd = "➕";

    const inline QString tableModeRemove = "➖";

    const inline QString buttonActiveStyle = "QPushButton { background-color: #bcbdbb; }";

    const inline QString buttonInactiveStyle = "QPushButton { background-color: #ff3333; }";
};
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace congif
{
    const QSettings congifuration(":/congif/config.ini", QSettings::IniFormat);
};
QT_END_NAMESPACE

#endif // !SETTINGS_HPP
