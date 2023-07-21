#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QMainWindow>

#include <QFile>
#include <QDir>

#include "ui.h"

class DataHandler
{
public:
    DataHandler(const QString &folderPath, Ui::MainWindow *ui);

    void loadData();

    void saveData();

    void deleteData();

    void getIsChooseUsername(bool *isChooseUsername);

    void usersRemove(const QString &key);

    void usersInsert(const QString &key, const QString &value);

    QString getUsersValue(const QString &key);

private:
    const QString m_folderPath;

    const QString m_filePath;

    Ui::MainWindow *m_ui;

    QMap<QString, QString> m_users;

    bool m_isChooseUsername;

protected:
};

#endif // DATAHANDLER_H
