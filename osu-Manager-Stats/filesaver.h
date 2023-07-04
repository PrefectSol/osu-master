#ifndef FILESAVER_H
#define FILESAVER_H

#include <QMap>
#include <QJsonDocument>
#include <QFile>

class FileSaver
{
public:
    FileSaver();

    static QMap<QString, QString> users;
};

#endif // FILESAVER_H
