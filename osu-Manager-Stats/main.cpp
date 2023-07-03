#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setWindowIcon(QIcon(":/Images/icon.png"));

    MainWindow window;
    window.show();

    return app.exec();
}
