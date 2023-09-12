#include "datahandler.h"
#include "settings.hpp"

QDataStream &operator<<(QDataStream &writer, const DataHandler::ArrayPersistentData &arrayPersistentData)
{
    for (int i = 0; i < m_settings::tableSize; i++)
    {
        for (int j = 0; j < m_settings::tableSize; j++)
        {
            writer << arrayPersistentData.users[i][j].username;
            writer << arrayPersistentData.users[i][j].image;
            writer << arrayPersistentData.users[i][j].userInfo;
            writer << arrayPersistentData.users[i][j].userScoresInfo;
        }
    }

    writer << arrayPersistentData.chooseUser.username;
    writer << arrayPersistentData.chooseUser.image;
    writer << arrayPersistentData.chooseUser.userInfo;
    writer << arrayPersistentData.chooseUser.userScoresInfo;

    return writer;
}

QDataStream &operator>>(QDataStream &reader, DataHandler::ArrayPersistentData &arrayPersistentData)
{
    for (int i = 0; i < m_settings::tableSize; i++)
    {
        for (int j = 0; j < m_settings::tableSize; j++)
        {
            reader >> arrayPersistentData.users[i][j].username;
            reader >> arrayPersistentData.users[i][j].image;
            reader >> arrayPersistentData.users[i][j].userInfo;
            reader >> arrayPersistentData.users[i][j].userScoresInfo;
        }
    }

    reader >> arrayPersistentData.chooseUser.username;
    reader >> arrayPersistentData.chooseUser.image;
    reader >> arrayPersistentData.chooseUser.userInfo;
    reader >> arrayPersistentData.chooseUser.userScoresInfo;

    return reader;
}

DataHandler::DataHandler(const QString &folderPath)
    : m_folderPath(folderPath), m_filePath(folderPath + m_settings::dataFile) {}

void DataHandler::loadData(DataHandler::AppPersistentData *appData,
                           DataHandler::UserPersistentData *userData,
                           DataHandler::ArrayPersistentData *arrayData)
{
    QFile file(m_filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    QDataStream reader(&file);

    reader >> settings::isSaveData;
    if (!settings::isSaveData)
    {
        file.close();
        return;
    }

    reader >> settings::isViewJson;

    reader.readRawData(reinterpret_cast<char*>(appData), sizeof(DataHandler::AppPersistentData));
    reader.readRawData(reinterpret_cast<char*>(userData), sizeof(DataHandler::UserPersistentData));

    reader >> *arrayData;

    file.close();
}

void DataHandler::saveData(const DataHandler::AppPersistentData &appData,
                           const DataHandler::UserPersistentData &userData,
                           const DataHandler::ArrayPersistentData &arrayData)
{
    QDir().mkdir(m_folderPath);

    QFile file(m_filePath);
    file.open(QIODevice::WriteOnly);

    QDataStream writer(&file);

    writer << settings::isSaveData;
    if (!settings::isSaveData)
    {
        file.close();
        return;
    }

    writer << settings::isViewJson;

    writer.writeRawData(reinterpret_cast<const char*>(&appData), sizeof(DataHandler::AppPersistentData));
    writer.writeRawData(reinterpret_cast<const char*>(&userData), sizeof(DataHandler::UserPersistentData));

    writer << arrayData;

    file.close();
}

void DataHandler::deleteDataFile()
{
    QDir folderDir(m_folderPath);
    if (folderDir.exists())
    {
        folderDir.removeRecursively();
    }
}

QString DataHandler::getOsuSecret()
{
    return congif::congifuration.value("Credentials/clientSecret").toString();
}

QString DataHandler::getOsuId()
{
    return congif::congifuration.value("Credentials/clientId").toString();
}
