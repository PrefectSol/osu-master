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

    bool setPlayer(const QString &username);

    void setUserVariables(const QJsonDocument &jsonDocument);

    QString getUserInfo();

    QJsonDocument getUserScores(int userId);

    QString getUserScoresInfo();

    void calculateAvr();

    void setUserJson(const QString &json);

    void setUserScoresJson(const QString &json);

    QString getAvatarUrl() const;
    void setAvatarUrl(const QString &newAvatarUrl);

    QString getUsername() const;
    void setUsername(const QString &newUsername);

    QString getCountryCode() const;
    void setCountryCode(const QString &newCountryCode);

    int getUserId() const;
    void setUserId(int newUserId);

    int getPlayCount() const;
    void setPlayCount(int newPlayCount);

    int getGlobalRank() const;
    void setGlobalRank(int newGlobalRank);

    int getCountryRank() const;
    void setCountryRank(int newCountryRank);

    int getPpCount() const;
    void setPpCount(int newPpCount);

    float getAccuracy() const;
    void setAccuracy(float newAccuracy);

    int getAvgPP() const;
    void setAvgPP(int newAvgPP);

    float getAvgAcc() const;
    void setAvgAcc(float newAvgAcc);

    float getAvgCs() const;
    void setAvgCs(float newAvgCs);

    float getAvgAr() const;
    void setAvgAr(float newAvgAr);

    float getAvgBpm() const;
    void setAvgBpm(float newAvgBpm);

    float getAvgLength() const;
    void setAvgLength(float newAvgLength);

signals:
    void userScoresFinished();

private:
    typedef struct UserField
    {
    public:
        QString avatarUrl = "";
        QString username = "";
        QString countryCode = "";
        int userId = 0;
        int playCount = 0;
        int globalRank = 0;
        int countryRank = 0;
        int ppCount = 0;
        float accuracy = 0.0f;
        float avgPP = 0.0f;
        float avgCs = 0.0f;
        float avgAcc = 0.0f;
        float avgAr = 0.0f;
        float avgBpm = 0.0f;
        float avgLength = 0.0f;
    } UserField;

    const QString m_clientId;

    const QString m_clientSecret;

    const QString m_apiUrl;

    const QUrl m_tokenUrl;

    QString m_token;

    QString m_userInfo;

    QString m_userScoresInfo;

    QJsonDocument m_userJson;

    QJsonDocument m_userScoresJson;

    UserField m_user;

protected:
};

#endif // OSUREQUEST_H
