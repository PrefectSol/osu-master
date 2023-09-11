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

#include <QPalette>
#include <QVector2D>
#include <QVector>
#include <QPoint>

#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>
#include <QList>

#include "datahandler.h"
#include "osurequest.h"
#include "ui.h"

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

    void loadUrlImage(QPixmap *pixmap, const QUrl &url);

    void setTableMode();

    void setTableUsers();

    void setChooseUser();

    void setUserTable(int row, int column, const QString &username, const QPixmap &avatar);

    void waitCellOperation(int row, int column);

    void initOverviewImages();

    void initOverview();

    void initUserStats();

    void initOverviewGraphics();

    void drawStatsPolygon();

    QString getUserJsonFromUsername(const QString &username);

    Ui::MainWindow *m_ui;

    DataHandler *m_dataHandler;

    QGraphicsScene *m_statsScene;

    OsuRequest m_osuParser;

    DataHandler::AppPersistentData m_appPersistentData;

    DataHandler::UserPersistentData m_userPersistentData;

    DataHandler::ArrayPersistentData m_arrayPersistentData;

    QList<QFuture<void>> m_tableThreads;

    int m_aimValue, m_staminaValue, m_speedValue, m_accuracyValue;
};

#endif // MAINWINDOW_H
