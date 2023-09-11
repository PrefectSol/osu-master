#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QApplication>

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

#endif // !SETTINGS_HPP
