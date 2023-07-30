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

    setUserVariables(jsonDocument);

    return true;
}

void OsuRequest::setUserVariables(const QJsonDocument &jsonDocument)
{
    m_userId = jsonDocument["id"].toInt();
    m_playCount = jsonDocument["statistics"]["play_count"].toInt();
    m_globalRank = jsonDocument["statistics"]["global_rank"].toInt();
    m_ppCount = jsonDocument["statistics"]["pp"].toDouble();
    m_countryRank = jsonDocument["statistics"]["country_rank"].toInt();
    m_accuracy = jsonDocument["statistics"]["hit_accuracy"].toDouble();
    m_countryCode = jsonDocument["country_code"].toString();

    m_userJson = jsonDocument;
}

void OsuRequest::setUserJson(const QString &json)
{
    const QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8());
    m_userInfo = json;
    setUserVariables(jsonDocument);
}

void OsuRequest::setTopScoresJson(const QString &json)
{
    const QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8());
    m_topScoresJson = jsonDocument;
    m_topScoresInfo = json;
    initStats();
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

bool OsuRequest::initUserJson(const QString &username)
{
    return isPlayerExist(username);
}

QJsonDocument OsuRequest::getTopScores(int userId)
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

    m_topScoresInfo = QString(reply->readAll());
    m_topScoresJson = QJsonDocument::fromJson(m_topScoresInfo.toUtf8());

    reply->deleteLater();

    emit topScoreFinished();

    return m_topScoresJson;
}

QString OsuRequest::getTopScoresInfo()
{
    return m_topScoresInfo;
}

void OsuRequest::setUserId(int userId)
{
    m_userId = userId;
}

int OsuRequest::getUserId()
{
    return m_userId;
}

void OsuRequest::setPlayCount(int playCount)
{
    m_playCount = playCount;
}

int OsuRequest::getPlayCount()
{
    return m_playCount;
}

float OsuRequest::getPpAvg()
{
    return avgPP;
}

void OsuRequest::setPpAvg(float avgPp)
{
    avgPP = avgPp;
}

void OsuRequest::initPpAvg()
{
    avgPP = 0;
    for(int i = 0; i < m_settings::playLimit; i++)
    {
        avgPP += m_topScoresJson[i]["weight"]["pp"].toDouble();
    }

    avgPP /= m_settings::playLimit;
}

float OsuRequest::getCsAvg()
{
    return avgCs;
}

void OsuRequest::setCsAvg(float avgCs)
{
    this->avgCs = avgCs;
}

void OsuRequest::initCspAvg()
{
    avgCs = 0;
    for(int i = 0; i < m_settings::playLimit; i++)
    {
        avgCs += m_topScoresJson[i]["beatmap"]["cs"].toDouble();
    }

    avgCs /= m_settings::playLimit;
}

float OsuRequest::getAccAvg()
{
    return avgAcc;
}

void OsuRequest::setAccAvg(float avgAcc)
{
    this->avgAcc = avgAcc;
}

void OsuRequest::initAccAvg()
{
    avgAcc = 0;
    for(int i = 0; i < m_settings::playLimit; i++)
    {
        avgAcc += m_topScoresJson[i]["accuracy"].toDouble() * 100;
    }

    avgAcc /= m_settings::playLimit;
}

float OsuRequest::getArAvg()
{
    return avgAr;
}

void OsuRequest::setArAvg(float avgAr)
{
    this->avgAr = avgAr;
}

void OsuRequest::initArAvg()
{
    avgAr = 0;
    for(int i = 0; i < m_settings::playLimit; i++)
    {
        avgAr += m_topScoresJson[i]["beatmap"]["ar"].toDouble();
    }

    avgAr /= m_settings::playLimit;
}

float OsuRequest::getBpmAvg()
{
    return avgBpm;
}

void OsuRequest::setBpmAvg(float avgBpm)
{
    this->avgBpm = avgBpm;
}

void OsuRequest::initBpmAvg()
{
    avgBpm = 0;
    for(int i = 0; i < m_settings::playLimit; i++)
    {
        avgBpm += m_topScoresJson[i]["beatmap"]["bpm"].toDouble();
    }

    avgBpm /= m_settings::playLimit;
}

void OsuRequest::initStats()
{
    const int limit = m_settings::playLimit;
    avgAcc = avgAr = avgBpm = avgCs = avgPP = avgLength = 0;

    for(int i = 0; i < limit; i++)
    {
        avgBpm += m_topScoresJson[i]["beatmap"]["bpm"].toDouble();
        avgAr += m_topScoresJson[i]["beatmap"]["ar"].toDouble();
        avgAcc += m_topScoresJson[i]["accuracy"].toDouble() * 100;
        avgCs += m_topScoresJson[i]["beatmap"]["cs"].toDouble();
        avgPP += m_topScoresJson[i]["weight"]["pp"].toDouble();
        avgLength += m_topScoresJson[i]["beatmap"]["count_circles"].toDouble() +  m_topScoresJson[i]["beatmap"]["count_sliders"].toDouble() +  m_topScoresJson[i]["beatmap"]["count_spinners"].toDouble();
    }

    avgBpm /= limit;
    avgAr /= limit;
    avgCs /= limit;
    avgAcc /= limit;
    avgPP /= limit;
    avgLength /= limit;
}

float OsuRequest::getLengthAvg()
{
    return avgLength;
}

void OsuRequest::setLengthAvg(float avgLength)
{
    this->avgLength = avgLength;
}

void OsuRequest::initLengthAvg()
{
    avgLength = 0;
    for(int i = 0; i < m_settings::playLimit; i++)
    {
        avgLength += m_topScoresJson[i]["beatmap"]["count_circles"].toDouble() +  m_topScoresJson[i]["beatmap"]["count_sliders"].toDouble() +  m_topScoresJson[i]["beatmap"]["count_spinners"].toDouble();
    }

    avgLength /= m_settings::playLimit;
}


int OsuRequest::getGlobalRank()
{
    return m_globalRank;
}

void OsuRequest::setGlobalRank(int globalrank)
{
    m_globalRank = globalrank;
}

double OsuRequest::getPpCount()
{
    return m_ppCount;
}

void OsuRequest::setPpCount(double ppCount)
{
    m_ppCount = ppCount;
}

int OsuRequest::getcountryRank()
{
    return m_countryRank;
}

void OsuRequest::setcountryRank(int countryRank)
{
    m_countryRank = countryRank;
}

double OsuRequest::getaccuracy()
{
    return m_accuracy;
}

void OsuRequest::setaccuracy(double accuracy)
{
    m_accuracy = accuracy;
}

QString OsuRequest::getCountryCode()
{
    return m_countryCode;
}

void OsuRequest::setCountryCode(const QString &countryCode)
{
    m_countryCode = countryCode;
}
