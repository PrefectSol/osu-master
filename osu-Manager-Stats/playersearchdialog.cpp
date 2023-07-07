#include "playersearchdialog.h"
#include "ui_playersearchdialog.h"

PlayerSearchDialog::PlayerSearchDialog(OsuRequest *parser, QWidget *parent)
  : QDialog(parent),
    ui(new Ui::PlayerSearchDialog),
    m_osuParser(parser),
    m_username(QString()),
    m_isOk(false)
{
    ui->setupUi(this);
}

PlayerSearchDialog::~PlayerSearchDialog()
{
    delete ui;
}

void PlayerSearchDialog::on_username_textEdited(const QString &username)
{
    QCompleter *completer = new QCompleter(this);

    QStringList users;
    m_osuParser->getSearchUsers(username, &users);

    completer->setModel(new QStringListModel(users, completer));
    ui->username->setCompleter(completer);
}

void PlayerSearchDialog::on_closeButton_pressed()
{
    m_isOk = false;
    PlayerSearchDialog::close();
}

void PlayerSearchDialog::on_addButton_pressed()
{
    m_username = ui->username->text();
    m_isOk = true;
    PlayerSearchDialog::close();
}

void PlayerSearchDialog::reset()
{
    m_username = QString();
    m_isOk = false;
}

QString PlayerSearchDialog::getUsername()
{
    return m_username;
}

bool PlayerSearchDialog::getIsOk()
{
    return m_isOk;
}
