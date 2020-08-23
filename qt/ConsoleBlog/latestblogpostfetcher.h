#ifndef LATESTBLOGPOSTFETCHER_H
#define LATESTBLOGPOSTFETCHER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QTimer>
#include <QNetworkReply>
#include <QJsonObject>

class LatestBlogPostFetcher : public QObject
{
    Q_OBJECT
public:
    explicit LatestBlogPostFetcher(QObject *parent = nullptr);

signals:

private slots:
    void requestLatestBlogPost();

private:
    int value = 0;
    bool hasNetworkReplyError(QNetworkReply *reply);
    QNetworkAccessManager m_accessManager;
    QJsonObject m_latestPost;
    const QNetworkRequest m_request = QNetworkRequest(QUrl(R"(https://i3bvxjrc.api.sanity.io/v1/data/query/production?query=*[_type == "post"] | order(_createdAt desc) [0])"));
    QTimer m_timer;

};

#endif // LATESTBLOGPOSTFETCHER_H
