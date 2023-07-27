#include "mainwindow.h"
#include "settings.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_isChoosePlayer(false),
    aimValue(0), staminaValue(0), speedValue(0), accuracyValue(0)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    ui->jsonViewer->hide();

    dataHandler = new DataHandler(QDir::currentPath() + m_settings::saveFolder, ui);

    int userId = -1;
    int playCount = -1;
    dataHandler->loadData(&m_userJson, &m_isChoosePlayer, &userId, &playCount);

    m_osuParser.setUserId(userId);
    m_osuParser.setPlayCount(playCount);

    playerSearch = new PlayerSearchDialog(&m_osuParser, this);
    playerSearch->setWindowModality(Qt::ApplicationModal);
    playerSearch->setWindowFlags(Qt::Window);

    ui->contentViewer->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    dataHandler->saveData(m_isChoosePlayer, m_osuParser.getUserId(), m_osuParser.getPlayCount());

    delete ui;
    delete dataHandler;
    delete playerSearch;
}

void MainWindow::initStats()
{
    m_osuParser.getTopScores(m_osuParser.getUserId());
    m_osuParser.initStats();

    const float cs = m_osuParser.getCsAvg();
    const float pp = m_osuParser.getPpAvg();
    const float ar = m_osuParser.getArAvg();
    const float acc = m_osuParser.getAccAvg();
    const float bpm = m_osuParser.getBpmAvg();
    const float length = qSqrt(m_osuParser.getLengthAvg());

    aimValue = (ar * qPow(cs, 0.1) / qPow(6, 0.1) / qPow(ar + cs, 0.1) * pp / (ar + cs + pp) * 100) +
                (1.25 * qPow((cs + pp + ar + acc) / 4, 1.3));

    speedValue = (ar * qPow(ar, 0.1) / qPow(6, 0.1) / qPow(2 * ar, 0.1) * pp / (2 * ar + pp) * 100) +
                (1.25 * qPow((cs + pp + ar + acc) / 4, 1.3));

    accuracyValue = (ar * qPow(acc, 0.1) / qPow(6, 0.1) / qPow(ar + acc, 0.1) * pp / (ar + acc + pp) * 100) +
                (1.25 * qPow((cs + pp + ar + acc) / 4, 1.3));

    staminaValue = (ar * qPow(length, 0.1) / qPow(6, 0.1) / qPow(ar + bpm, 0.1) * pp / (ar + bpm + length + pp) * 100) +
                (1.25 * qPow((bpm + length + pp + ar + acc) / 5, 1.3));

    ui->aimValueLabel->setText(QString::number(aimValue));
    ui->speedValueLabel->setText(QString::number(speedValue));
    ui->accuracyValueLabel->setText(QString::number(accuracyValue));
    ui->staminaValueLabel->setText(QString::number(staminaValue));
}

void MainWindow::initOverview()
{
    initStats();
    initRankspng();
    ui->graphicsView->setStyleSheet("background-color:rgba(0, 0, 0, 0); border: none; ");
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    QColor colorQPen(45, 45, 45, 255);
    QColor colorPol(190, 190, 190, 255);
    QColor colorPoint(30, 30, 30, 175);

    QPolygon mainpol;
    mainpol << QPoint(0,100) << QPoint(100,0) << QPoint(0,-100) << QPoint(-100,0);
    scene->addPolygon(mainpol,QPen(colorQPen,4),QBrush(colorPol));

    const int minValue = 100;
    const float normalize = 15.5f;

    const int aimV = int((float)aimValue / normalize);
    const int staminaV = int((float)staminaValue / normalize);
    const int speedV = int((float)speedValue / normalize);
    const int accuracyV = int((float)accuracyValue / normalize);

    aimPoint = new QPoint(0, -std::min(minValue, aimV));
    staminaPoint = new QPoint(0, std::min(minValue, staminaV));
    speedPoint = new QPoint(std::min(minValue, speedV), 0);
    accuracyPoint = new QPoint(-std::min(minValue, accuracyV), 0);

    scene->addLine(-100,0,100,0);
    scene->addLine(0,-100,0,100);
    for(int i = 0;i<9;i++)
    {
        scene->addLine(100-20*(i+1),-5,100-20*(i+1),5);
    }
    for(int i = 0;i<9;i++)
    {
        scene->addLine(-5,100-20*(i+1),5,100-20*(i+1));
    }

    QPolygon statspol;
    statspol << *aimPoint << *speedPoint << *staminaPoint << *accuracyPoint;
    scene->addPolygon(statspol,QPen(colorPoint,3),QBrush(colorPoint));

    QPixmap pixmapplanet(":/Images/earth.png");
    QPixmap scaledPixmapplanet = pixmapplanet.scaled(ui->countrylabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->countrylabel->setAlignment(Qt::AlignCenter);
    ui->countrylabel->setPixmap(scaledPixmapplanet);

    //QGroupBox* groupBox = new QGroupBox("ProfileLayout");
    //groupBox->setStyleSheet("border: 1px solid black; background-color: green;");
    //groupBox->setLayout(/* ваш код компоновки заголовка */);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setRenderHint(QPainter::TextAntialiasing);

    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->usernamelabel_2->setText(ui->chooseUsername->text());
    ui->picturelabel_2->setPixmap(ui->chooseImage->pixmap());
    ui->playcountlabel->setText(QString::number(m_osuParser.getPlayCount()));

}

void MainWindow::initRankspng()
{
    QPixmap pixmapsSS(":/Images/ranking-XH.png");
    QPixmap scaledPixmapsSS = pixmapsSS.scaled(ui->label_37->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_37->setAlignment(Qt::AlignCenter);
    ui->label_37->setPixmap(scaledPixmapsSS);

    QPixmap pixmapSS(":/Images/ranking-X.png");
    QPixmap scaledPixmapSS = pixmapSS.scaled(ui->label_38->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_38->setAlignment(Qt::AlignCenter);
    ui->label_38->setPixmap(scaledPixmapSS);

    QPixmap pixmapsS(":/Images/ranking-SH.png");
    QPixmap scaledPixmapsS = pixmapsS.scaled(ui->label_39->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_39->setAlignment(Qt::AlignCenter);
    ui->label_39->setPixmap(scaledPixmapsS);

    QPixmap pixmapS(":/Images/ranking-S.png");
    QPixmap scaledPixmapS = pixmapS.scaled(ui->label_40->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_40->setAlignment(Qt::AlignCenter);
    ui->label_40->setPixmap(scaledPixmapS);

    QPixmap pixmapA(":/Images/ranking-A.png");
    QPixmap scaledPixmapA = pixmapA.scaled(ui->label_41->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_41->setAlignment(Qt::AlignCenter);
    ui->label_41->setPixmap(scaledPixmapA);
}

void MainWindow::on_goChoosePage_pressed()
{
    ui->contentViewer->setCurrentIndex(0);
}

void MainWindow::on_goRecentButton_pressed()
{
    const int playCount = m_osuParser.getPlayCount();
    if (playCount < 50)
    {
        QMessageBox::warning(nullptr, "Recent plays", "Insufficient number of maps played");
        return;
    }

    if (m_isChoosePlayer)
    {
        ui->contentViewer->setCurrentIndex(2);
    }
    else
    {
        QMessageBox::warning(nullptr, "Recent plays", "The player is not choosed");
    }
}

void MainWindow::on_goBitmapLoaderButton_pressed()
{
    ui->contentViewer->setCurrentIndex(6);
}

void MainWindow::on_setFolderButton_pressed()
{
    const QString folderPath = QFileDialog::getExistingDirectory(nullptr, "Choose a songs folder", "", QFileDialog::ShowDirsOnly);

    if (folderPath.isEmpty())
    {
        return;
    }

    ui->songsFolderPath->setText(folderPath);
}

void MainWindow::on_startDownloaderButton_pressed()
{
    const QString roomName = ui->roomName->text();
    const QString roomID = ui->roomID->text();

    if (roomName.isEmpty() && roomID.isEmpty())
    {
        QMessageBox::warning(nullptr, "Bitmap downloader", "The fields is empty");
        return;
    }

    QString matchID;
    if (!roomID.isEmpty())
    {
        matchID = roomID;
    }
    else
    {
        matchID = m_osuParser.getMatchID(roomName);
        if (matchID.isEmpty())
        {
            QMessageBox::warning(nullptr, "Bitmap downloader", "Couldn't find a room (errors may occur when the number of rooms is >50). Try using id search");
            return;
        }
    }

    QJsonDocument matchJson = m_osuParser.getMatchJson(matchID);
    if (matchJson.isEmpty() || matchJson["error"].isNull())
    {
        QMessageBox::warning(nullptr, "Bitmap downloader", "Couldn't find a room");
        return;
    }

    ui->roomJsonViewer->setText(m_osuParser.getMatchInfo());
}

void MainWindow::on_goOverviewButton_pressed()
{
    if (!m_isChoosePlayer)
    {
        QMessageBox::warning(nullptr, "Overview", "The player is not choosed");
        return;
    }

    const int playCount = m_osuParser.getPlayCount();
    if (playCount >= m_settings::playLimit)
    {
        initOverview();
        ui->contentViewer->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::warning(nullptr, "Overview", "Insufficient number of maps played");
    }

}

void MainWindow::on_goOtherToolsButton_pressed()
{
    ui->contentViewer->setCurrentIndex(8);
}

void MainWindow::on_goSettingsPage_pressed()
{
    ui->contentViewer->setCurrentIndex(7);
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

    m_userJson = m_osuParser.getUserJson();

    m_avatarUrl = m_userJson["avatar_url"].toString().replace("\\/", "/");
    m_username = m_userJson["username"].toString();

    m_userInfo = m_osuParser.getUserInfo();
    ui->jsonViewer->setText(m_userInfo);
    dataHandler->usersInsert(m_username, m_userInfo);

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

            QString jsonString = dataHandler->getUsersValue(usernameLabel->text());
            QJsonDocument json = QJsonDocument::fromJson(jsonString.toUtf8());

            const int userId = json["id"].toInt();
            m_osuParser.setUserId(userId);

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


void MainWindow::on_userTable_cellDoubleClicked(int, int)
{
    on_chooseButton_pressed();
}

