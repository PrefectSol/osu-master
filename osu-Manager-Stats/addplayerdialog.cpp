#include "addplayerdialog.h"
#include "ui_addplayerdialog.h"

addPlayerDialog::addPlayerDialog(OsuRequest *parser, QWidget *parent) :
    QDialog(parent), ui(new Ui::addPlayerDialog), m_osuRequest(parser)
{
    ui->setupUi(this);
}

addPlayerDialog::~addPlayerDialog()
{
    delete ui;
}

QString addPlayerDialog::getUsername()
{
    return m_username;
}

bool addPlayerDialog::getIsOk()
{
    return m_isOk;
}

void addPlayerDialog::on_closeButton_pressed()
{
    m_isOk = false;
    addPlayerDialog::close();
}

void addPlayerDialog::on_addButton_pressed()
{
    m_username = ui->username->text();
    m_isOk = true;
    addPlayerDialog::close();
}

void addPlayerDialog::on_username_textEdited(const QString &username)
{
    QStringList users;

    m_osuRequest->getSearchUsers(username, &users);

    QCompleter *completer = new QCompleter(this);
    completer->setModel(new QStringListModel(users, completer));
    ui->username->setCompleter(completer);
}

