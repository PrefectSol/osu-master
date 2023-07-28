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

    void loadData(bool *isChooseUser, int *userId, int *playCount,
                float *cs, float *pp, float *ar, float *acc, float *bpm, float *length);

    void saveData(bool isChooseUser, int userId, int playCount, float cs, float pp, float ar, float acc, float bpm, float length);

    void deleteData();

    void usersRemove(const QString &key);

    void usersInsert(const QString &key, const QString &value);

    QString getUsersValue(const QString &key);

    void topScoresRemove(const QString &key);

    void topScoresInsert(const QString &key, const QString &value);

    QString getTopScoresValue(const QString &key);

private:
    const QString m_folderPath;

    const QString m_filePath;

    Ui::MainWindow *m_ui;

    QMap<QString, QString> m_users;

    QMap<QString, QString> m_topScores;

    bool m_isChooseUsername;

protected:
};

#endif // DATAHANDLER_H
