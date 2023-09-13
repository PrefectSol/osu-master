#include "osurequest.h"
#include "settings.hpp"
#include "datahandler.h"

OsuRequest::OsuRequest() : m_clientId(DataHandler::getClientId()), m_clientSecret(DataHandler::getClientSecret()),
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

bool OsuRequest::setPlayer(const QString &username)
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

    setUserVariables(jsonDocument);

    return true;
}

void OsuRequest::setUserVariables(const QJsonDocument &jsonDocument)
{
    m_user.avatarUrl = jsonDocument["avatar_url"].toString().replace("\\/", "/");
    m_user.username = jsonDocument["username"].toString();
    m_user.countryCode = jsonDocument["country_code"].toString();
    m_user.userId = jsonDocument["id"].toInt();
    m_user.playCount = jsonDocument["statistics"]["play_count"].toInt();
    m_user.globalRank = jsonDocument["statistics"]["global_rank"].toInt();
    m_user.ppCount = jsonDocument["statistics"]["pp"].toDouble();
    m_user.countryRank = jsonDocument["statistics"]["country_rank"].toInt();
    m_user.accuracy = jsonDocument["statistics"]["hit_accuracy"].toDouble();

    m_userJson = jsonDocument;
}

QJsonDocument OsuRequest::getUserScores(int userId)
{
    QUrl url(m_apiUrl + "/users/" + QString::number(userId) + "/scores/best");
    QUrlQuery query;
    query.addQueryItem("limit", QString::number(m_settings::playLimit));
    query.addQueryItem("mode", "osu");

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

    m_userScoresInfo = QString(reply->readAll());
    m_userScoresJson = QJsonDocument::fromJson(m_userScoresInfo.toUtf8());

    reply->deleteLater();

    emit userScoresFinished();

    return m_userScoresJson;
}

QString OsuRequest::getUserScoresInfo()
{
    return m_userScoresInfo;
}

void OsuRequest::calculateAvr()
{
    for(int i = 0; i < m_settings::playLimit; i++)
    {
        m_user.avgBpm += m_userScoresJson[i]["beatmap"]["bpm"].toDouble();
        m_user.avgAr += m_userScoresJson[i]["beatmap"]["ar"].toDouble();
        m_user.avgAcc += m_userScoresJson[i]["accuracy"].toDouble() * 100.0f;
        m_user.avgCs += m_userScoresJson[i]["beatmap"]["cs"].toDouble();
        m_user.avgPP += m_userScoresJson[i]["weight"]["pp"].toDouble();
        m_user.avgLength += m_userScoresJson[i]["beatmap"]["count_circles"].toDouble() +
                            m_userScoresJson[i]["beatmap"]["count_sliders"].toDouble() +
                            m_userScoresJson[i]["beatmap"]["count_spinners"].toDouble();
    }

    m_user.avgBpm /= m_settings::playLimit;
    m_user.avgAr /= m_settings::playLimit;
    m_user.avgCs /= m_settings::playLimit;
    m_user.avgAcc /= m_settings::playLimit;
    m_user.avgPP /= m_settings::playLimit;
    m_user.avgLength /= m_settings::playLimit;
}

void OsuRequest::setUserJson(const QString &json)
{
    const QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8());
    m_userInfo = json;

    setUserVariables(jsonDocument);
}

void OsuRequest::setUserScoresJson(const QString &json)
{
    m_userScoresJson = QJsonDocument::fromJson(json.toUtf8());
    m_userScoresInfo = json;

    calculateAvr();
}

QString OsuRequest::getUserInfo()
{
    return m_userInfo;
}

QString OsuRequest::getAvatarUrl() const
{
    return m_user.avatarUrl;
}

void OsuRequest::setAvatarUrl(const QString &newAvatarUrl)
{
    m_user.avatarUrl = newAvatarUrl;
}

QString OsuRequest::getUsername() const
{
    return m_user.username;
}

void OsuRequest::setUsername(const QString &newUsername)
{
    m_user.username = newUsername;
}

QString OsuRequest::getCountryCode() const
{
    return m_user.countryCode;
}

void OsuRequest::setCountryCode(const QString &newCountryCode)
{
    m_user.countryCode = newCountryCode;
}

int OsuRequest::getUserId() const
{
    return m_user.userId;
}

void OsuRequest::setUserId(int newUserId)
{
    m_user.userId = newUserId;
}

int OsuRequest::getPlayCount() const
{
    return m_user.playCount;
}

void OsuRequest::setPlayCount(int newPlayCount)
{
    m_user.playCount = newPlayCount;
}

int OsuRequest::getGlobalRank() const
{
    return m_user.globalRank;
}

void OsuRequest::setGlobalRank(int newGlobalRank)
{
    m_user.globalRank = newGlobalRank;
}

int OsuRequest::getCountryRank() const
{
    return m_user.countryRank;
}

void OsuRequest::setCountryRank(int newCountryRank)
{
    m_user.countryRank = newCountryRank;
}

int OsuRequest::getPpCount() const
{
    return m_user.ppCount;
}

void OsuRequest::setPpCount(int newPpCount)
{
    m_user.ppCount = newPpCount;
}

float OsuRequest::getAccuracy() const
{
    return m_user.accuracy;
}

void OsuRequest::setAccuracy(float newAccuracy)
{
    m_user.accuracy = newAccuracy;
}

int OsuRequest::getAvgPP() const
{
    return m_user.avgPP;
}

void OsuRequest::setAvgPP(int newAvgPP)
{
    m_user.avgPP = newAvgPP;
}

float OsuRequest::getAvgCs() const
{
    return m_user.avgAr;
}

void OsuRequest::setAvgCs(float newAvgCs)
{
    m_user.avgCs = newAvgCs;
}

float OsuRequest::getAvgAcc() const
{
    return m_user.avgAcc;
}

void OsuRequest::setAvgAcc(float newAvgAcc)
{
    m_user.avgAcc = newAvgAcc;
}

float OsuRequest::getAvgAr() const
{
    return m_user.avgAr;
}

void OsuRequest::setAvgAr(float newAvgAr)
{
    m_user.avgAr = newAvgAr;
}

float OsuRequest::getAvgBpm() const
{
    return m_user.avgBpm;
}

void OsuRequest::setAvgBpm(float newAvgBpm)
{
    m_user.avgBpm = newAvgBpm;
}

float OsuRequest::getAvgLength() const
{
    return m_user.avgLength;
}

void OsuRequest::setAvgLength(float newAvgLength)
{
    m_user.avgLength = newAvgLength;
}
