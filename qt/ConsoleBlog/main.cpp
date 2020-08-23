#include "latestblogpostfetcher.h"

#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LatestBlogPostFetcher blogFetcher;

    return a.exec();
}
