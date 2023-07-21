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

    m_completer = new QCompleter(this);
    ui->username->setCompleter(m_completer);
}

PlayerSearchDialog::~PlayerSearchDialog()
{
    delete ui;
    delete m_completer;
}

void PlayerSearchDialog::on_username_textEdited(const QString &username)
{
//    QStringList users;
//    m_osuParser->getSearchUsers(username, &users);

//    m_completer->setModel(new QStringListModel(users, m_completer));
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
    m_username = QString("");
    ui->username->setText(m_username);
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

void PlayerSearchDialog::on_username_textChanged(const QString &username)
{
    QStringList users;
    m_osuParser->getSearchUsers(username, &users);

    m_completer->setModel(new QStringListModel(users, m_completer));
}

