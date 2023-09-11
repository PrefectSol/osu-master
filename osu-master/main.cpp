#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QtNetwork>
#include <QEventLoop>
#include <QTimer>

#include "mainwindow.h"

bool isOnline()
{
    const QNetworkRequest request(QUrl("http://www.google.com"));

    QNetworkAccessManager manager;
    const QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    QTimer timeoutTimer;

    QAbstractSocket::connect(&timeoutTimer, SIGNAL(timeout()), &loop, SLOT(quit()));
    QAbstractSocket::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));

    timeoutTimer.setSingleShot(true);
    timeoutTimer.start(3000);

    loop.exec();

    return reply->bytesAvailable();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/Assets/icon.png"));

    QFile file(":/Style/style.qss");
    file.open(QFile::ReadOnly);

    const QString styleSheet { QLatin1String(file.readAll()) };
    app.setStyleSheet(styleSheet);

    file.close();

    MainWindow window;
    window.show();

    if (!isOnline())
    {
        QMessageBox::warning(nullptr, "Connection is not availiable", "Some functions may not be available");
    }

    return app.exec();
}
