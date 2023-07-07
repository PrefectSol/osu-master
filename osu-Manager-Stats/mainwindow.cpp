#include "mainwindow.h"
#include "settings.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_isChoosePlayer(false)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    ui->jsonViewer->hide();

    dataHandler = new DataHandler(QDir::currentPath() + m_settings::saveFolder, ui);
    dataHandler->loadData();
    dataHandler->getIsChooseUsername(&m_isChoosePlayer);

    playerSearch = new PlayerSearchDialog(&m_osuParser, this);
    playerSearch->setWindowModality(Qt::ApplicationModal);
    playerSearch->setWindowFlags(Qt::Window);
}

MainWindow::~MainWindow()
{
    dataHandler->saveData();

    delete ui;
    delete dataHandler;
    delete playerSearch;
}

void MainWindow::on_goChoosePage_pressed()
{
    ui->contentViewer->setCurrentIndex(0);
}

void MainWindow::on_goOverviewButton_pressed()
{
    if (m_isChoosePlayer)
    {
        ui->contentViewer->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::warning(nullptr, "Overview", "The player is not choosed");
    }
}

void MainWindow::on_goSettingsPage_pressed()
{
    ui->contentViewer->setCurrentIndex(2);
}

void MainWindow::loadAvatar(QPixmap *pixmap)
{
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(m_avatarUrl)));

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray imageData = reply->readAll();
        pixmap->loadFromData(imageData);
    }

    reply->deleteLater();
}

QString MainWindow::getSearchPlayer(bool *isOk)
{
    playerSearch->reset();
    playerSearch->exec();

    *isOk = playerSearch->getIsOk();

    return playerSearch->getUsername();
}

void MainWindow::on_addButton_pressed()
{
    const QString messageTitle = "Add new player...";

    QTableWidget *table = ui->userTable;
    QModelIndex currentIndex = table->currentIndex();

    if (currentIndex == QModelIndex())
    {
        QMessageBox::warning(nullptr, messageTitle, "The player is not selected");

        return;
    }

    bool isOk;
    QString username;

    if (ui->useSearchCheckBox->isChecked())
    {
        username = getSearchPlayer(&isOk);
    }
    else
    {
        username = QInputDialog::getText(nullptr, messageTitle, "Enter a nickname:", QLineEdit::Normal, "username", &isOk);
    }

    if (!isOk)
    {
        return;
    }

    if (username.isEmpty() || !m_osuParser.isPlayerExist(username))
    {
        QMessageBox::warning(nullptr, messageTitle, "Couldn't find a player");

        return;
    }

    const QJsonDocument userJson = m_osuParser.getUserJson();

    m_avatarUrl = userJson["avatar_url"].toString().replace("\\/", "/");
    m_username = userJson["username"].toString();

    const QString userInfo = m_osuParser.getUserInfo();
    ui->jsonViewer->setText(userInfo);
    dataHandler->usersInsert(m_username, userInfo);

    const int pixmapSize = m_settings::pixmapSize;

    QWidget *player = new QWidget();
    QLabel *usernameLabel = new QLabel(m_username);

    QPixmap pixmap;
    loadAvatar(&pixmap);

    QLabel *imageLabel = new QLabel();
    imageLabel->setPixmap(pixmap.scaled(pixmapSize, pixmapSize, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

    QVBoxLayout *layout = new QVBoxLayout(player);
    layout->addWidget(usernameLabel, 0, Qt::AlignHCenter | Qt::AlignTop);
    layout->addWidget(imageLabel, 0, Qt::AlignHCenter | Qt::AlignVCenter);

    table->setCellWidget(currentIndex.row(), currentIndex.column(), player);
}

void MainWindow::on_rowsSpinBox_valueChanged(int rows)
{
    ui->userTable->setRowCount(rows);
}

void MainWindow::on_colsSpinBox_valueChanged(int columns)
{
    ui->userTable->setColumnCount(columns);
}

QString MainWindow::getUsernameFromCell(int row, int column)
{
    QWidget *widget = ui->userTable->cellWidget(row, column);
    if (widget)
    {
        QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(widget->layout());
        if (layout)
        {
            const QLabel *usernameLabel = qobject_cast<QLabel*>(layout->itemAt(0)->widget());

            return usernameLabel->text();
        }
    }

    return QString();
}

void MainWindow::on_clearButton_pressed()
{
    QTableWidget *table = ui->userTable;
    QModelIndex currentIndex = table->currentIndex();

    if (currentIndex == QModelIndex())
    {
        QMessageBox::warning(nullptr, "Remove player...", "The player is not selected");

        return;
    }

    const int row = currentIndex.row();
    const int column = currentIndex.column();

    table->setCellWidget(row, column, nullptr);

    const QString username = getUsernameFromCell(row, column);
    if (!username.isEmpty())
    {
        dataHandler->usersRemove(username);
    }

    ui->jsonViewer->clear();
}

void MainWindow::on_chooseButton_pressed()
{
    QTableWidget *table = ui->userTable;
    QModelIndex currentIndex = table->currentIndex();

    if (currentIndex == QModelIndex())
    {
        QMessageBox::warning(nullptr, "Choose a player...", "The player is not selected");
        return;
    }

    const int row = currentIndex.row();
    const int column = currentIndex.column();

    QWidget *widget = table->cellWidget(row, column);
    if (widget)
    {
        QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(widget->layout());
        if (layout)
        {
            const QLabel *usernameLabel = qobject_cast<QLabel*>(layout->itemAt(0)->widget());
            const QLabel *imageLabel = qobject_cast<QLabel*>(layout->itemAt(1)->widget());

            QLabel *uiUsername = ui->chooseUsername;
            QLabel *uiImage = ui->chooseImage;

            uiUsername->setText(usernameLabel->text());
            uiUsername->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

            uiImage->setPixmap(imageLabel->pixmap());
            uiImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

            m_isChoosePlayer = true;

            return;
        }
    }

    QMessageBox::warning(nullptr, "Choose a player...", "Selected error");
}

void MainWindow::on_viewJsonCheckBox_stateChanged(int state)
{
    QTextBrowser *json = ui->jsonViewer;

    if (state == Qt::Unchecked)
    {
        json->hide();
    }
    else
    {
        json->show();
    }
}

void MainWindow::on_userTable_cellClicked(int row, int column)
{
    const QTableWidget *table = ui->userTable;

    QWidget *widget = table->cellWidget(row, column);
    if (widget)
    {
        QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(widget->layout());
        if (layout)
        {
            const QLabel *usernameLabel = qobject_cast<QLabel*>(layout->itemAt(0)->widget());
            const QString username = usernameLabel->text();

            const QString json = dataHandler->getUsersValue(username);
            ui->jsonViewer->setText(json);

            return;
        }
    }

    ui->jsonViewer->clear();
}

void MainWindow::on_removeDataButton_pressed()
{
    dataHandler->deleteData();
}



