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

    void setUserVariables(const QJsonDocument &jsonDocument);

    void setUserJson(const QString &json);

    void setTopScoresJson(const QString &json);

    QString getTopScoresInfo();

    int getUserId();

    void setUserId(int userId);

    int getPlayCount();

    void setPlayCount(int playCount);

    float getPpAvg();

    void setPpAvg(float avgPp);

    void initPpAvg();

    float getCsAvg();

    void setCsAvg(float avgCs);

    void initCspAvg();

    float getAccAvg();

    void setAccAvg(float avgAcc);

    void initAccAvg();

    float getArAvg();

    void setArAvg(float avgAr);

    void initArAvg();

    float getBpmAvg();

    void setBpmAvg(float avgBpm);

    void initBpmAvg();

    float getLengthAvg();

    void setLengthAvg(float avgLength);

    void initLengthAvg();

    void initStats();

    QString getUserInfo();

    QString getMatchInfo();

    bool isPlayerExist(const QString &username);

    bool initUserJson(const QString &username);

signals:
    void topScoreFinished();

protected:

private:
    const QString m_clientId;

    const QString m_clientSecret;

    const QString m_apiUrl;

    const QUrl m_tokenUrl;

    QString m_token;

    QString m_userInfo;

    QString m_matchInfo;

    QString m_topScoresInfo;

    QJsonDocument m_userJson;

    QJsonDocument m_matchJson;

    QJsonDocument m_topScoresJson;

    int m_userId;

    float avgPP, avgCs, avgAcc, avgAr, avgBpm, avgLength;

    int m_playCount;
};

#endif // OSUREQUEST_H
