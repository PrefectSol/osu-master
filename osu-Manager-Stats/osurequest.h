#ifndef OSUREQUEST_H
#define OSUREQUEST_H

#include <QMainWindow>

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

    QJsonDocument getUserJson();

    QString getUserInfo();

    bool isPlayerExist(const QString &username);

protected:

private:
    const QString m_clientId;

    const QString m_clientSecret;

    const QString m_apiUrl;

    const QUrl m_tokenUrl;

    QString m_token;

    QString m_userInfo;

    QJsonDocument m_userJson;
};

#endif // OSUREQUEST_H
