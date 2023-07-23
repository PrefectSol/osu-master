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

    QJsonDocument getTopScores(int userId);

    int getUserId();

    void setUserId(int userId);

    int getPlayCount();

    void setPlayCount(int playCount);

    float getPpAvg();

    void setPpAvg(int avgPp);

    void initPpAvg();

    float getCsAvg();

    void setCsAvg(int avgCs);

    void initCspAvg();

    float getAccAvg();

    void setAccAvg(int avgAcc);

    void initAccAvg();

    float getArAvg();

    void setArAvg(int avgAr);

    void initArAvg();

    float getBpmAvg();

    void setBpmAvg(int avgBpm);

    void initBpmAvg();

    void initStats();

    QString getUserInfo();

    QString getMatchInfo();

    bool isPlayerExist(const QString &username);

    bool initUserJson(const QString &username);

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

    QJsonDocument m_topScoresJson;

    int m_userId;

    float avgPP, avgCs, avgAcc, avgAr, avgBpm;

    int m_playCount;
};

#endif // OSUREQUEST_H
