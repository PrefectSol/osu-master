#include <QApplication>
#include <QMessageBox>
#include <QtNetwork>
#include <QEventLoop>
#include <QTimer>

#include "mainwindow.h"

bool isOnline()
{
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("http://www.google.com"));
    QNetworkReply *reply = manager.get(request);
    QEventLoop loop;
    QTimer timeoutTimer;

    QAbstractSocket::connect(&timeoutTimer, SIGNAL(timeout()), &loop, SLOT(quit()));
    QAbstractSocket::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));

    timeoutTimer.setSingleShot(true);
    timeoutTimer.start(3000);

    loop.exec();

    bool isOnline = false;

    if (reply->bytesAvailable())
    {
        isOnline = true;
    }

    return isOnline;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setWindowIcon(QIcon(":/Images/icon.png"));

    MainWindow window;

    window.show();

    if (!isOnline())
    {
        QMessageBox::warning(nullptr, "Connection is not availiable", "Connection is not availiable");
    }

    return app.exec();
}
