#include "latestblogpostfetcher.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QProcess>
#include <iostream>

LatestBlogPostFetcher::LatestBlogPostFetcher(QObject *parent) : QObject(parent)
{
    requestLatestBlogPost();
    m_timer.start(std::chrono::seconds(5));
    connect(&m_timer, &QTimer::timeout, [this](){
       requestLatestBlogPost();
    });
}

void LatestBlogPostFetcher::requestLatestBlogPost()
{
    auto reply = m_accessManager.get(m_request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if(!hasNetworkReplyError(reply))
        {
            QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
            QJsonObject result = document.object().value("result").toObject();
            if(!(result.value("_id") == m_latestPost.value("_id") && result.value("_rev") == m_latestPost.value("_rev")))
            {
                m_latestPost = result;
                QProcess::execute("cmd /c cls");
                QDateTime createdAt = QDateTime::fromString(result.value("_createdAt").toString(), Qt::ISODate).toLocalTime();
                qDebug().noquote() << "Publisert:" << createdAt.toString();
                qDebug().noquote() << "";
                qDebug().noquote() << "Tittel:" << m_latestPost.value("title").toString();
                qDebug().noquote() << "";
                qDebug().noquote() << "-----------Text:-----------";
                for(const auto &item : m_latestPost.value("body").toArray()) {
                    for(const auto &children : item.toObject().value("children").toArray())
                        qDebug().noquote() << children.toObject().value("text").toString();
                }
                qDebug().noquote() << "---------------------------";
            }
//            else
//                qDebug() << "no change";
        }
        reply->deleteLater();
    });
}

bool LatestBlogPostFetcher::hasNetworkReplyError(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "Status" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() << "- Network Reply Error -" << reply->errorString();
        return true;
    }
    return false;

}


