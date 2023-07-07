#ifndef PLAYERSEARCHDIALOG_H
#define PLAYERSEARCHDIALOG_H

#include <QDialog>
#include <QCompleter>
#include <QStringListModel>
#include <QtConcurrent/QtConcurrent>

#include "osurequest.h"
#include "ui.h"

class PlayerSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerSearchDialog(OsuRequest *parser, QWidget *parent = nullptr);

    ~PlayerSearchDialog();

    void reset();

    QString getUsername();

    bool getIsOk();

private slots:
    void on_username_textEdited(const QString &username);

    void on_closeButton_pressed();

    void on_addButton_pressed();

    void on_username_textChanged(const QString &arg1);

private:
    Ui::PlayerSearchDialog *ui;

    OsuRequest *m_osuParser;

    QCompleter *m_completer;

    QString m_username;

    bool m_isOk;
};

#endif // PLAYERSEARCHDIALOG_H
