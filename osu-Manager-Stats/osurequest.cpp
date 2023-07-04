#include "osurequest.h"

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

QString OsuRequest::getToken()
{
    return m_token;
}

bool OsuRequest::isPlayerExist(QString username)
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

QString OsuRequest::getUserInfo()
{
    return m_userInfo;
}

QJsonDocument OsuRequest::getUserJson()
{
    return m_userJson;
}
