#include "osurequest.h"
#include "settings.hpp"

OsuRequest::OsuRequest() : m_clientId("23205"), m_clientSecret("JBzsoPDOaIA0wdG2fiB5nfjy3rMbRa8Liy8ZYfzc"),
    m_apiUrl("https://osu.ppy.sh/api/v2"), m_tokenUrl("https://osu.ppy.sh/oauth/token")
{
    QNetworkAccessManager manager;

    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);

    QUrlQuery postData;
    postData.addQueryItem("client_id", m_clientId);
    postData.addQueryItem("client_secret", m_clientSecret);
    postData.addQueryItem("grant_type", "client_credentials");
    postData.addQueryItem("scope", "public");

    QNetworkRequest request(m_tokenUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkReply *reply = manager.post(request, postData.query().toUtf8());
    loop.exec();

    QByteArray buffer = reply->readAll();
    QJsonDocument jsonDoc(QJsonDocument::fromJson(buffer));
    QJsonObject json = jsonDoc.object();

    m_token = json["access_token"].toString();

    reply->deleteLater();
}

bool OsuRequest::isPlayerExist(const QString &username)
{
    QUrl url(m_apiUrl + "/users/" + username);

    QUrlQuery query;
    query.addQueryItem("mode", "osu");
    query.addQueryItem("limit", "1");
    url.setQuery(query.query());

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Accept", "application/json");
    request.setRawHeader("Authorization", ("Bearer " + m_token).toUtf8());

    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();

    m_userInfo = QString(reply->readAll());
    QJsonDocument jsonDocument = QJsonDocument::fromJson(m_userInfo.toUtf8());

    reply->deleteLater();

    if (jsonDocument["error"].isNull())
    {
        return false;
    }

    m_userJson = jsonDocument;

    return true;
}

void OsuRequest::getSearchUsers(const QString &keyword, QStringList *users)
{
    QUrl url(m_apiUrl + "/search");

    QUrlQuery query;
    query.addQueryItem("mode", "user");
    query.addQueryItem("query", keyword);
    query.addQueryItem("page", "1");

    url.setQuery(query.query());

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Accept", "application/json");
    request.setRawHeader("Authorization", ("Bearer " + m_token).toUtf8());

    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();

    const QString response = QString(reply->readAll());
    QJsonDocument jsonDocument = QJsonDocument::fromJson(response.toUtf8());

    reply->deleteLater();

    const int pageSize = m_settings::searchPageSize;
    const int total = jsonDocument["user"]["total"].toInt();
    const int size = total - pageSize >= 0 ? pageSize : total;

    for(int i = 0; i < size; i++)
    {
        (*users) << jsonDocument["user"]["data"][i]["username"].toString();
    }
}

QString OsuRequest::getMatchID(const QString &roomName)
{
    QUrl url(m_apiUrl + "/matches");

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Accept", "application/json");
    request.setRawHeader("Authorization", ("Bearer " + m_token).toUtf8());

    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString response = QString(reply->readAll());
    QJsonDocument matchJson = QJsonDocument::fromJson(response.toUtf8());

    reply->deleteLater();

    const int limit = matchJson["params"]["limit"].toInt();

    for(int i = 0; i < limit; i++)
    {
        const QString name = matchJson["matches"][i]["name"].toString();
        if (name == roomName)
        {
            return QString::number(matchJson["matches"][i]["id"].toInt());
        }
    }

    return QString();
}

QJsonDocument OsuRequest::getMatchJson(const QString &roomID)
{
    QUrl url(m_apiUrl + "/matches/" + roomID);

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Accept", "application/json");
    request.setRawHeader("Authorization", ("Bearer " + m_token).toUtf8());

    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();

    m_matchInfo = QString(reply->readAll());
    m_matchJson = QJsonDocument::fromJson(m_matchInfo.toUtf8());

    reply->deleteLater();

    return m_matchJson;
}

QString OsuRequest::getMatchInfo()
{
    return m_matchInfo;
}

QString OsuRequest::getUserInfo()
{
    return m_userInfo;
}

QJsonDocument OsuRequest::getUserJson()
{
    return m_userJson;
}


