#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QVector>
#include <QPixmap>

#include "settings.hpp"

class DataHandler
{
private:
    typedef struct UserData
    {
    public:
        QString username = "";
        QString userInfo = "";
        QString userScoresInfo = "";
        QPixmap image = QPixmap();
    } UserData;

public:
    typedef struct UserPersistentData
    {
    public:
        bool isChooseUser = false;
        int userId = -1;
        int playCount = -1;
        int globalrank = -1;
        int countryRank = -1;
        int pp = -1;
        float accuracy = -1.0f;
        float avrCs = -1.0f;
        float avrPp = -1.0f;
        float avrAr = -1.0f;
        float avrAccuracy = -1.0f;
        float avrBpm = -1.0f;
        float avrLength = -1.0f;
        QString countryCode = "";
    } UserPersistentData;

    typedef struct AppPersistentData
    {
    public:
        bool isTableModeAdd = true;
        int usersTableRowCount = 0;
        int usersTableColumnCount = 0;
    } AppPersistentData;

    typedef struct ArrayPersistentData
    {
    public:
        QVector<QVector<UserData>> users =
                QVector<QVector<UserData>>(m_settings::tableSize, QVector<UserData>(m_settings::tableSize));

        UserData chooseUser = UserData();
    } ArrayPersistentData;

    DataHandler(const QString &folderPath);

    void loadData(DataHandler::AppPersistentData *appData,
                  DataHandler::UserPersistentData *userData,
                  DataHandler::ArrayPersistentData *arrayData);

    void saveData(const DataHandler::AppPersistentData &appData,
                  const DataHandler::UserPersistentData &userData,
                  const DataHandler::ArrayPersistentData &arrayData);

    void deleteDataFile();

    static QString getClientSecret();

    static QString getClientId();

private:
    const QString m_folderPath;

    const QString m_filePath;

protected:
};

#endif // DATAHANDLER_H
