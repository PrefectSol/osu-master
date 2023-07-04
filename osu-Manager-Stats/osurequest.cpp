#include "osurequest.h"

OsuRequest::OsuRequest() : m_clientId("23205"), m_clientSecret("JBzsoPDOaIA0wdG2fiB5nfjy3rMbRa8Liy8ZYfzc"),
    m_apiUrl("https://osu.ppy.sh/api/v2"), m_tokenUrl("https://osu.ppy.sh/oauth/token")
{
#ifdef FAST_TOKEN
    m_token = "eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJhdWQiOiIyMzIwNSIsImp0aSI6IjY2NzJmY2MzMmIwZGJhYjA0MWZlMzY3OGMwNmY0YTVjNGZlMDViZTZjNTA0YTgwODQ4YjU4Zjc2ZmNlNzgxOTcyMGU0OWYxNDM2MmE2OTA1IiwiaWF0IjoxNjg4NDczMTc0LjY4NDYyNCwibmJmIjoxNjg4NDczMTc0LjY4NDYyNiwiZXhwIjoxNjg4NTU5NTc0LjY3NzQ0OCwic3ViIjoiIiwic2NvcGVzIjpbInB1YmxpYyJdfQ.S4K7JCJ0c7AKaECQdBeHAt7Qiu4-HorwqtX1IW6eCA7ICk9SdWYWvNdb6ExTlXhW6zX7Ys-l33ZmjjKNVwD_F3IAdn_FixFQfwPrjhavFmElYk42fEUGYLzcftT8TOeE1Mrq9vqPGtoCoQ8i1wmq-8ygiKDZdhD8_xAsc_8QsCTLzYbv159v8xjwpM5Nhs6ayHjawBFwNfwc-VMzk8c_obfKS0joxnbIErNEv_3soId72IJJx5iseHuGI416BJR_Fdm0H6iSCvGV_GdsxVJ0wJMlxIOvi906w8cvrtpb1yx225yk9H2RRCNLdRIfKNJ02mRHWYGl4oBKgWotLyyHjdgH6x_w8flfkTojXljLY9aSZ3sZEJlMcDL4mn3K3-FWRhRW5nEPBdlHqBgSFTvp-2unK1vClv4ewRtU51zZYyeSCpdlgE5ppJ1IwfV8FUR43cbxNvUz_Ec4gts-eYOkpG6gmEbXdai0dvTZ80vGnw3wG3GROeNeTH3yDL2wNXGnCWL-4EjcHyVn5j-k3IbVf6YSAQwt-ng7LiKYT320C7aS9GOZrjIuIDmI_Ab4HCeGo3OeXepHUSWAZP0gys8pwBob9vnlImoAvM4Oxtc8K-DhiFbnCT70PzIoRcPUBjGKPmSWEZ9L12Q2YKURp4LhFq_LUhsS07TLBkCN8Crhx3s";
#else
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
#endif
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
