#ifndef OSUREQUEST_H
#define OSUREQUEST_H

#include <QMainWindow>
#include <QMessageBox>

#include <QJsonValue>
#include <QJsonValueRef>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include <QUrl>
#include <QUrlQuery>

#include <QEventLoop>

#include <QStringList>

class OsuRequest : public QMainWindow
{
    Q_OBJECT
public:
    explicit OsuRequest();

    void getSearchUsers(const QString &keyword, QStringList *users);

    QString getMatchID(const QString &roomName);

    QJsonDocument getUserJson();

    QJsonDocument getMatchJson(const QString &roomID);

    QString getUserInfo();

    QString getMatchInfo();

    bool isPlayerExist(const QString &username);

protected:

private:
    const QString m_clientId;

    const QString m_clientSecret;

    const QString m_apiUrl;

    const QUrl m_tokenUrl;

    QString m_token;

    QString m_userInfo;

    QString m_matchInfo;

    QJsonDocument m_userJson;

    QJsonDocument m_matchJson;
};

#endif // OSUREQUEST_H
