#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QApplication>

QT_BEGIN_NAMESPACE
namespace settings
{
    inline bool isViewJson = false;

    inline bool isSearcher = false;
};
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace m_settings
{
    inline const QString saveFolder = "/appdata";

    inline const QString saveFile = "/data.dat";

    inline const QString endPoint = "-----------------END-----------------";

    inline const int pixmapSize = 100;

    inline const int searchPageSize = 20;
};
QT_END_NAMESPACE

#endif // SETTINGS_HPP
