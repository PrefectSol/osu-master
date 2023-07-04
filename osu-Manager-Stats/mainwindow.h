#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <QJsonDocument>
#include <QTextBrowser>

#include "osurequest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_rowsSpinBox_valueChanged(int rows);

    void on_colsSpinBox_valueChanged(int columns);

    void on_clearButton_clicked();

    void on_chooseButton_clicked();

    void on_viewJsonCheckBox_stateChanged(int arg1);

    void on_userTable_cellClicked(int row, int column);

private:
    void loadAvatar(QPixmap *pixmap);

    QString getUsernameFromCell(int row, int column);

    Ui::MainWindow *ui;

    OsuRequest m_osuParser;

    QString m_avatarUrl;

    QString m_username;
};
#endif // MAINWINDOW_H
