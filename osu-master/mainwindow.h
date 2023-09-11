#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QInputDialog>
#include <QMessageBox>

#include <QJsonDocument>
#include <QTextBrowser>
#include <QProcess>

#include <QFileDialog>
#include <QFile>

#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QtMath>
#include <QGroupBox>
#include <QLayout>

#include <future>
#include <QPalette>
#include <QVector2D>
#include <QPoint>

#include "datahandler.h"
#include "osurequest.h"
#include "ui.h"

namespace Special
{
    const inline QString tableModeAdd = "➕";

    const inline QString tableModeRemove = "➖";

    const inline QString buttonActiveStyle = "QPushButton { background-color: #bcbdbb; }";

    const inline QString buttonInactiveStyle = "QPushButton { background-color: #ff3333; }";
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_viewJsonCheckBox_stateChanged(int state);

    void on_userTable_cellClicked(int row, int column);

    void on_goChoosePage_pressed();

    void on_goOverviewPage_pressed();

    void on_goSettingsPage_pressed();

    void on_removeDataButton_pressed();

    void on_userTable_cellDoubleClicked(int row, int column);

    void on_verticalSlider_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_tableModeButton_pressed();

private:
    void initialize();

    void setStyleSheets();

    void addCell(int row, int column);

    void chooseCell(int row, int column);

    void clearCell(int row, int column);

    void loadUserScores();

    void loadUrlImage(QPixmap *pixmap, const QUrl &url);

    void setTableMode();

    void setTableUsers();

    void setUserTable(int row, int column, const QString &username, const QPixmap &avatar);

    QString getUserJsonFromUsername(const QString &username);

//    void initOverview();

//    void initStats();

    Ui::MainWindow *m_ui;

    DataHandler *m_dataHandler;

    DataHandler::AppPersistentData m_appPersistentData;

    DataHandler::UserPersistentData m_userPersistentData;

    OsuRequest m_osuParser;

    std::future<void> m_future1;

//    QString m_userInfo;

//    QGraphicsScene *scene;

//    QPoint *aimPoint, *staminaPoint, *speedPoint, *accuracyPoint;

//    int aimValue, staminaValue, speedValue, accuracyValue;

//    void initpngs();
};

#endif // MAINWINDOW_H
