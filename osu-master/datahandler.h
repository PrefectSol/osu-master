#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QVector>
#include <QPixmap>

class DataHandler
{
public:
    typedef struct UserPersistentData
    {
    public:
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
        QString countryCode;
    } UserPersistentData;

    typedef struct UserTableData
    {
        QString username;
        QString userInfo;
        QString userScoresInfo;
        QPixmap image;
    public:
    } UserTableData;

    typedef struct AppPersistentData
    {
    public:
        bool isChooseUser = false;
        bool isTableModeAdd = true;
        int usersTableRowCount = 0;
        int usersTableColumnCount = 0;
        QVector<QVector<UserTableData>> users;
    } AppPersistentData;

    DataHandler(const QString &folderPath);

    void loadData(DataHandler::AppPersistentData *appData, DataHandler::UserPersistentData *userData);

    void saveData(const DataHandler::AppPersistentData &appData, const DataHandler::UserPersistentData &userData);

    void deleteDataFile();

private:
    const QString m_folderPath;

    const QString m_filePath;

protected:
};

#endif // DATAHANDLER_H
