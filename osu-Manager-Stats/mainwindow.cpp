#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "settings.hpp"

QMap<QString, QString> m_users;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), addDialog(new addPlayerDialog(&m_osuParser, this)), m_isChoosePlayer(false)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    m_saveDataFolderPath = QDir::currentPath() + "/appdata";
    m_saveDataFilePath = m_saveDataFolderPath + "/data.dat";

    loadData();

    if (!ui->viewJsonCheckBox_8->isChecked())
    {
        ui->jsonViewer_8->hide();
    }

    connect(ui->goChoosePage, &QPushButton::clicked, [=]()
    {
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->goOverviewButton, &QPushButton::clicked, [=]()
    {
        if (m_isChoosePlayer)
        {
            ui->stackedWidget->setCurrentIndex(1);
        }
        else
        {
            QMessageBox::warning(nullptr, "Overview", "The player is not choosed");
        }
    });

    connect(ui->goSettingsPage, &QPushButton::clicked, [=]()
    {
        ui->stackedWidget->setCurrentIndex(2);
    });
}

MainWindow::~MainWindow()
{
    saveData();

    delete ui;
    delete addDialog;
}

void MainWindow::saveData()
{
    QDir().mkdir(m_saveDataFolderPath);

    QFile file(m_saveDataFilePath);
    file.open(QIODevice::WriteOnly);

    QDataStream out(&file);

    const bool isSaveData = ui->saveDataCB->isChecked();
    out << isSaveData;

    if (!isSaveData)
    {
        file.close();

        return;
    }

    out << ui->viewJsonCheckBox_8->isChecked();
    out << ui->searcherCB->isChecked();

    QTableWidget *table = ui->userTable_8;

    const int rows = table->rowCount();
    out << rows;

    const int columns = table->columnCount();
    out << columns;

    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            QWidget *widget = table->cellWidget(row, column);
            if (widget)
            {
                QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(widget->layout());
                if (layout)
                {
                    QLabel *usernameLabel = qobject_cast<QLabel*>(layout->itemAt(0)->widget());
                    QLabel *imageLabel = qobject_cast<QLabel*>(layout->itemAt(1)->widget());

                    const QString username = usernameLabel->text();

                    out << username;
                    out << imageLabel->pixmap();
                    out << m_users.value(username);
                    out << row;
                    out << column;
                }
            }
        }
    }

    out << settings::endPoint;
    out << ui->chooseUsername->text();
    out << ui->chooseAvatar->pixmap();

    file.close();
}

void MainWindow::loadData()
{
    QFile file(m_saveDataFilePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    QDataStream in(&file);

    bool isSaveData;
    in >> isSaveData;

    if (!isSaveData)
    {
        file.close();
        return;
    }

    ui->saveDataCB->setChecked(isSaveData);

    in >> settings::isViewJson;
    ui->viewJsonCheckBox_8->setChecked(settings::isViewJson);

    in >> settings::isSearcher;
    ui->searcherCB->setChecked(settings::isSearcher);

    int row, column;
    in >> row;
    in >> column;

    ui->userTable_8->setRowCount(row);
    ui->rowsSpinBox_8->setValue(row);
    ui->userTable_8->setColumnCount(column);
    ui->colsSpinBox_8->setValue(column);

    QString user, json;
    QPixmap avatar;
    int r, c;

    in >> user;

    while (user != settings::endPoint)
    {
        in >> avatar;
        in >> json;
        in >> r;
        in >> c;

        m_users.insert(user, json);

        const size_t pixmapSizes = 100;

        QLabel *usernameLabel = new QLabel();
        usernameLabel->setText(user);

        QLabel *imageLabel = new QLabel();
        imageLabel->setPixmap(avatar.scaled(pixmapSizes, pixmapSizes, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

        QWidget *player = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(player);
        layout->addWidget(usernameLabel, 0, Qt::AlignHCenter | Qt::AlignTop);
        layout->addWidget(imageLabel, 0, Qt::AlignHCenter | Qt::AlignVCenter);

        ui->userTable_8->setCellWidget(r, c, player);

        in >> user;
    }

    QString chooseUsername;
    QPixmap chooseAvatar;

    in >> chooseUsername;
    in >> chooseAvatar;

    if (!chooseUsername.isEmpty())
    {
        m_isChoosePlayer = true;
    }

    ui->chooseUsername->setText(chooseUsername);
    ui->chooseUsername->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    ui->chooseAvatar->setPixmap(chooseAvatar);
    ui->chooseAvatar->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    file.close();
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
    addDialog->setWindowModality(Qt::ApplicationModal);
    addDialog->setWindowFlags(Qt::Window);

    addDialog->exec();
    *isOk = addDialog->getIsOk();
    return addDialog->getUsername();
}

QString MainWindow::getDirectPlayer(bool *isOk)
{
    return QInputDialog::getText(nullptr, "Add new player...", "Enter a nickname:", QLineEdit::Normal, "username", isOk);
}

void MainWindow::on_addButton_8_clicked()
{
    const QString messageTitle = "Add new player...";

    QTableWidget *table = ui->userTable_8;
    QModelIndex currentIndex = table->currentIndex();

    if (currentIndex == QModelIndex())
    {
        QMessageBox::warning(nullptr, messageTitle, "The player is not selected");
        return;
    }
    bool isOk;
    QString username;
    if (ui->searcherCB->isChecked())
    {
        username = getSearchPlayer(&isOk);
    }
    else
    {
        username = QInputDialog::getText(nullptr, "Add new player...", "Enter a nickname:", QLineEdit::Normal, "username", &isOk);
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

    QJsonDocument userJson = m_osuParser.getUserJson();

    m_avatarUrl = userJson["avatar_url"].toString().replace("\\/", "/");
    m_username = userJson["username"].toString();

    const QString userInfo = m_osuParser.getUserInfo();
    ui->jsonViewer_8->setText(userInfo);
    m_users.insert(m_username, userInfo);

    const size_t pixmapSizes = 100;

    QWidget *player = new QWidget();
    QLabel *usernameLabel = new QLabel(m_username);
    QPixmap pixmap;
    loadAvatar(&pixmap);

    QLabel *imageLabel = new QLabel();
    imageLabel->setPixmap(pixmap.scaled(pixmapSizes, pixmapSizes, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

    QVBoxLayout *layout = new QVBoxLayout(player);
    layout->addWidget(usernameLabel, 0, Qt::AlignHCenter | Qt::AlignTop);
    layout->addWidget(imageLabel, 0, Qt::AlignHCenter | Qt::AlignVCenter);

    table->setCellWidget(currentIndex.row(), currentIndex.column(), player);
}

void MainWindow::on_rowsSpinBox_8_valueChanged(int rows)
{
    ui->userTable_8->setRowCount(rows);
}

void MainWindow::on_colsSpinBox_8_valueChanged(int columns)
{
    ui->userTable_8->setColumnCount(columns);
}

QString MainWindow::getUsernameFromCell(int row, int column)
{
    QWidget *widget = ui->userTable_8->cellWidget(row, column);
    if (widget)
    {
        QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(widget->layout());
        if (layout)
        {
            QLabel *usernameLabel = qobject_cast<QLabel*>(layout->itemAt(0)->widget());

            return usernameLabel->text();
        }
    }

    return QString();
}

void MainWindow::on_clearButton_8_clicked()
{
    QTableWidget *table = ui->userTable_8;
    QModelIndex currentIndex = table->currentIndex();

    if (currentIndex == QModelIndex())
    {
        QMessageBox::warning(nullptr, "Remove player...", "The player is not selected");
    }
    else
    {
        const int row = currentIndex.row();
        const int column = currentIndex.column();

        table->setCellWidget(row, column, nullptr);

        const QString username = getUsernameFromCell(row, column);
        if (!username.isEmpty())
        {
            m_users.remove(username);
        }

        ui->jsonViewer_8->setText("");
    }
}

void MainWindow::on_chooseButton_8_clicked()
{
    QTableWidget *table = ui->userTable_8;
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
            QLabel *usernameLabel = qobject_cast<QLabel*>(layout->itemAt(0)->widget());
            QLabel *imageLabel = qobject_cast<QLabel*>(layout->itemAt(1)->widget());

            ui->chooseUsername->setText(usernameLabel->text());
            ui->chooseUsername->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

            ui->chooseAvatar->setPixmap(imageLabel->pixmap());
            ui->chooseAvatar->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

            m_isChoosePlayer = true;

            return;
        }
    }

    QMessageBox::warning(nullptr, "Choose a player...", "Selected error");
}

void MainWindow::on_viewJsonCheckBox_8_stateChanged(int)
{
    if (!ui->viewJsonCheckBox_8->isChecked())
    {
        ui->jsonViewer_8->hide();
    }
    else
    {
        ui->jsonViewer_8->show();
    }
}

void MainWindow::on_userTable_8_cellClicked(int row, int column)
{
    QTableWidget *table = ui->userTable_8;

    QWidget *widget = table->cellWidget(row, column);
    if (widget)
    {
        QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(widget->layout());
        if (layout)
        {
            QLabel *usernameLabel = qobject_cast<QLabel*>(layout->itemAt(0)->widget());
            QString username = usernameLabel->text();

            ui->jsonViewer_8->setText(m_users.value(username));

            return;
        }
    }

    ui->jsonViewer_8->setText("");
}

void MainWindow::on_removeData_pressed()
{
    QDir folderDir(m_saveDataFolderPath);
    if (folderDir.exists())
    {
        folderDir.removeRecursively();
    }
}

