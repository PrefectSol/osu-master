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

#include "osurequest.h"
#include "addplayerdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_8_clicked();

    void on_rowsSpinBox_8_valueChanged(int rows);

    void on_colsSpinBox_8_valueChanged(int columns);

    void on_clearButton_8_clicked();

    void on_chooseButton_8_clicked();

    void on_viewJsonCheckBox_8_stateChanged(int arg1);

    void on_userTable_8_cellClicked(int row, int column);

    void on_removeData_pressed();

private:
    void loadAvatar(QPixmap *pixmap);

    void saveData();

    void loadData();

    QString getSearchPlayer(bool *isOk);

    QString getDirectPlayer(bool *isOk);

    QString getUsernameFromCell(int row, int column);

    Ui::MainWindow *ui;

    addPlayerDialog *addDialog;

    OsuRequest m_osuParser;

    QString m_avatarUrl;

    QString m_username;

    QString m_saveDataFolderPath;

    QString m_saveDataFilePath;

    bool m_isChoosePlayer;
};
#endif // MAINWINDOW_H
