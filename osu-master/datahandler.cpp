#include "datahandler.h"
#include "settings.hpp"

DataHandler::DataHandler(const QString &folderPath)
    : m_folderPath(folderPath), m_filePath(folderPath + m_settings::dataFile) {}

void DataHandler::loadData(DataHandler::AppPersistentData *appData, DataHandler::UserPersistentData *userData)
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

    file.close();
}

void DataHandler::saveData(const DataHandler::AppPersistentData &appData, const DataHandler::UserPersistentData &userData)
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
