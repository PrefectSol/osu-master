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

#include <future>

#include "datahandler.h"
#include "osurequest.h"
#include "playersearchdialog.h"
#include "ui.h"
#include <QLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    QJsonDocument m_userJson;

private slots:
    void on_addButton_pressed();

    void on_rowsSpinBox_valueChanged(int rows);

    void on_colsSpinBox_valueChanged(int columns);

    void on_clearButton_pressed();

    void on_chooseButton_pressed();

    void on_viewJsonCheckBox_stateChanged(int state);

    void on_userTable_cellClicked(int row, int column);

    void on_goChoosePage_pressed();

    void on_goSettingsPage_pressed();

    void on_goOverviewButton_pressed();

    void on_removeDataButton_pressed();

    void on_goRecentButton_pressed();

    void on_goBitmapLoaderButton_pressed();

    void on_goOtherToolsButton_pressed();

    void on_setFolderButton_pressed();

    void on_startDownloaderButton_pressed();

    void on_userTable_cellDoubleClicked(int row, int column);

private:
    void loadUrlImage(const QUrl &url, QPixmap *pixmap);

    void loadAvatar(QPixmap *pixmap);

    QString getSearchPlayer(bool *isOk);

    QString getUsernameFromCell(int row, int column);

    void initOverview();

    void initStats();

    Ui::MainWindow *ui;

    DataHandler *dataHandler;

    PlayerSearchDialog *playerSearch;

    OsuRequest m_osuParser;

    QString m_avatarUrl;

    QString m_username;

    bool m_isChoosePlayer;

    QString m_userInfo;

    QGraphicsScene *scene;

    QPoint *aimPoint, *staminaPoint, *speedPoint, *accuracyPoint;

    int aimValue, staminaValue, speedValue, accuracyValue;

    void initpngs();

    void loadTopScores();
};
#endif // MAINWINDOW_H
