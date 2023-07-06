#ifndef ADDPLAYERDIALOG_H
#define ADDPLAYERDIALOG_H

#include <QDialog>
#include <QCompleter>
#include <QStringListModel>

#include "osurequest.h"

namespace Ui {
class addPlayerDialog;
}

class addPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addPlayerDialog(OsuRequest *parser, QWidget *parent = nullptr);
    ~addPlayerDialog();

    QString getUsername();

    bool getIsOk();

private slots:
    void on_closeButton_pressed();

    void on_addButton_pressed();

    void on_username_textEdited(const QString &username);

private:
    Ui::addPlayerDialog *ui;

    QString m_username;

    OsuRequest *m_osuRequest;

    bool m_isOk;
};

#endif // ADDPLAYERDIALOG_H
