#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_ui = new Ui::MainWindow;
    m_ui->setupUi(this);

    m_appPersistentData.users.resize(m_settings::tableSize);
    for (int i = 0; i < m_settings::tableSize; i++)
    {
        m_appPersistentData.users[i].resize(m_settings::tableSize);
    }

    m_dataHandler = new DataHandler(QDir::currentPath() + m_settings::dataFolder);
    m_dataHandler->loadData(&m_appPersistentData, &m_userPersistentData);

    setStyleSheets();
    initialize();
}

MainWindow::~MainWindow()
{
    settings::isSaveData = m_ui->saveDataCheckBox->isChecked();
    settings::isViewJson = m_ui->viewJsonCheckBox->isChecked();

    m_appPersistentData.usersTableRowCount = m_ui->verticalSlider->value();
    m_appPersistentData.usersTableColumnCount = m_ui->horizontalSlider->value();

    m_dataHandler->saveData(m_appPersistentData, m_userPersistentData);

    delete m_ui;
    delete m_dataHandler;
}

void MainWindow::setStyleSheets()
{
    m_ui->jsonViewer->setStyleSheet("QTextBrowser { color: #ffffff; }");
}

void MainWindow::initialize()
{
    m_ui->saveDataCheckBox->setChecked(settings::isSaveData);
    m_ui->verticalSlider->setValue(m_appPersistentData.usersTableRowCount);
    m_ui->horizontalSlider->setValue(m_appPersistentData.usersTableColumnCount);

    on_goChoosePage_pressed();
    setTableMode();
    setTableUsers();

    if (!settings::isViewJson)
    {
        m_ui->jsonViewer->hide();
    }
    else
    {
        m_ui->viewJsonCheckBox->setChecked(true);
    }
}

void MainWindow::on_goChoosePage_pressed()
{
    m_ui->contentViewer->setCurrentIndex(0);
    m_ui->goChoosePage->setStyleSheet(Special::buttonActiveStyle);
    m_ui->goOverviewPage->setStyleSheet(Special::buttonInactiveStyle);
    m_ui->goSettingsPage->setStyleSheet(Special::buttonInactiveStyle);
}

void MainWindow::on_goOverviewPage_pressed()
{
    if (!m_appPersistentData.isChooseUser)
    {
        QMessageBox::warning(nullptr, "Overview", "The player is not choosed");
        return;
    }

    const int playCount = m_osuParser.getPlayCount();
    if (playCount >= m_settings::playLimit)
    {
        m_ui->contentViewer->setCurrentIndex(1);
        m_ui->goChoosePage->setStyleSheet(Special::buttonInactiveStyle);
        m_ui->goOverviewPage->setStyleSheet(Special::buttonActiveStyle);
        m_ui->goSettingsPage->setStyleSheet(Special::buttonInactiveStyle);
    }
    else
    {
        QMessageBox::warning(nullptr, "Overview", "Insufficient number of maps played");
    }
}

void MainWindow::on_goSettingsPage_pressed()
{
    m_ui->contentViewer->setCurrentIndex(2);
    m_ui->goChoosePage->setStyleSheet(Special::buttonInactiveStyle);
    m_ui->goOverviewPage->setStyleSheet(Special::buttonInactiveStyle);
    m_ui->goSettingsPage->setStyleSheet(Special::buttonActiveStyle);
}

void MainWindow::on_removeDataButton_pressed()
{
    m_dataHandler->deleteDataFile();
}

//void MainWindow::initStats()
//{
//    const float cs = m_osuParser.getCsAvg();
//    const float pp = m_osuParser.getPpAvg();
//    const float ar = m_osuParser.getArAvg();
//    const float acc = m_osuParser.getAccAvg();
//    const float bpm = m_osuParser.getBpmAvg();
//    const float length = qSqrt(m_osuParser.getLengthAvg());

//    aimValue = (ar * qPow(cs, 0.1) / qPow(6, 0.1) / qPow(ar + cs, 0.1) * pp / (ar + cs + pp) * 100) +
//                (1.25 * qPow((cs + pp + ar + acc) / 4, 1.3));

//    speedValue = (ar * qPow(ar, 0.1) / qPow(6, 0.1) / qPow(2 * ar, 0.1) * pp / (2 * ar + pp) * 100) +
//                (1.25 * qPow((cs + pp + ar + acc) / 4, 1.3));

//    accuracyValue = (ar * qPow(acc, 0.1) / qPow(6, 0.1) / qPow(ar + acc, 0.1) * pp / (ar + acc + pp) * 100) +
//                (1.25 * qPow((cs + pp + ar + acc) / 4, 1.3));

//    staminaValue = (ar * qPow(length, 0.1) / qPow(6, 0.1) / qPow(ar + bpm, 0.1) * pp / (ar + bpm + length + pp) * 100) +
//                (1.25 * qPow((bpm + length + pp + ar + acc) / 5, 1.3));

//    ui->aimValueLabel->setText(QString::number(aimValue));
//    ui->speedValueLabel->setText(QString::number(speedValue));
//    ui->accuracyValueLabel->setText(QString::number(accuracyValue));
//    ui->staminaValueLabel->setText(QString::number(staminaValue));
//}

//void MainWindow::initOverview()
//{
//    initStats();
//    initpngs();
//  //  ui->graphicsView->setStyleSheet("background-color:rgba(0, 0, 0, 0); border: none; ");
//    scene = new QGraphicsScene();
//    ui->graphicsView->setScene(scene);

//    //ui->jsonViewer->setText(m_osuParser.getTopScoresInfo());

//    QColor colorQPen(45, 45, 45, 255);
//    QColor colorPol(190, 190, 190, 255);
//    QColor colorPoint(30, 30, 30, 175);

//    QPolygon mainpol;
//    mainpol << QPoint(0,100) << QPoint(100,0) << QPoint(0,-100) << QPoint(-100,0);
//    scene->addPolygon(mainpol,QPen(colorQPen,4),QBrush(colorPol));

//    const int minValue = 100;
//    const float normalize = 15.5f;

//    const int aimV = int((float)aimValue / normalize);
//    const int staminaV = int((float)staminaValue / normalize);
//    const int speedV = int((float)speedValue / normalize);
//    const int accuracyV = int((float)accuracyValue / normalize);

//    aimPoint = new QPoint(0, -std::min(minValue, aimV));
//    staminaPoint = new QPoint(0, std::min(minValue, staminaV));
//    speedPoint = new QPoint(std::min(minValue, speedV), 0);
//    accuracyPoint = new QPoint(-std::min(minValue, accuracyV), 0);

//    scene->addLine(-100,0,100,0);
//    scene->addLine(0,-100,0,100);
//    for(int i = 0;i<9;i++)
//    {
//        scene->addLine(100-20*(i+1),-5,100-20*(i+1),5);
//    }
//    for(int i = 0;i<9;i++)
//    {
//        scene->addLine(-5,100-20*(i+1),5,100-20*(i+1));
//    }

//    QPolygon statspol;
//    statspol << *aimPoint << *speedPoint << *staminaPoint << *accuracyPoint;
//    scene->addPolygon(statspol,QPen(colorPoint,3),QBrush(colorPoint));

//    const double accur = m_osuParser.getaccuracy();
//    const double roundedAccuracy = int(accur * 100.0f) / 100.0f;

//    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
//    ui->graphicsView->setRenderHint(QPainter::TextAntialiasing);

//    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    ui->usernamelabel_2->setText(ui->chooseUsername->text());
//    ui->picturelabel_2->setPixmap(ui->chooseImage->pixmap());
//    ui->playcountlabel->setText(QString::number(m_osuParser.getPlayCount()));
//    ui->globalranklabel->setText("#"+QString::number(m_osuParser.getGlobalRank()));
//    ui->PPlabel->setText(QString::number(m_osuParser.getPpCount())+"pp");
//    ui->countrylabel->setText("#"+QString::number(m_osuParser.getcountryRank()));
//    ui->accuracylabel->setText(QString::number(roundedAccuracy)+"%");

////    ui->MainPlayerStats->setStyleSheet("QGroupBox { border: 2px solid grey; border-radius: 12px; background-color: rgba(215, 215, 215, 168); }");
////    ui->StatsCountbox->setStyleSheet("QGroupBox { border: 2px solid grey; border-radius: 12px; background-color: rgba(215, 215, 215, 168); }");
////    ui->graphicbox->setStyleSheet("QGroupBox { border: 2px solid grey; border-radius: 12px; background-color: rgba(215, 215, 215, 168); }");
////    ui->contentViewer->setStyleSheet("QStackWidget { background-color: rgba(255, 255, 255, 0); }");


////    //roundedPixmap.setMask(roundedPixmap.createHeuristicMask());
////    ui->chooseImage->setStyleSheet("QLabel { border: 2px solid grey; border-radius: 12px; }");

//    QPixmap countryPixmap;
//    const QString countryCode = m_osuParser.getCountryCode().toLower();
//    const QUrl countryUrl("https://worldflags.net/assets/flaggor/flags/4x3/" + countryCode + ".svg");
//    loadUrlImage(countryUrl, &countryPixmap);
//    if (countryPixmap.isNull())
//    {
//        ui->usercountrylabel->setAlignment(Qt::AlignCenter);
//        ui->usercountrylabel->setText(countryCode);
//    }
//    else
//    {
//        QPixmap scaledPixmapCountry = countryPixmap.scaled(ui->label_41->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//        ui->usercountrylabel->setAlignment(Qt::AlignCenter);
//        ui->usercountrylabel->setPixmap(scaledPixmapCountry);
//    }
//}

//void MainWindow::initpngs()
//{
//    QPixmap pixmapsSS(":/Images/ranking-XH.png");
//    QPixmap scaledPixmapsSS = pixmapsSS.scaled(ui->label_37->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    ui->label_37->setAlignment(Qt::AlignCenter);
//    ui->label_37->setPixmap(scaledPixmapsSS);

//    QPixmap pixmapSS(":/Images/ranking-X.png");
//    QPixmap scaledPixmapSS = pixmapSS.scaled(ui->label_38->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    ui->label_38->setAlignment(Qt::AlignCenter);
//    ui->label_38->setPixmap(scaledPixmapSS);

//    QPixmap pixmapsS(":/Images/ranking-SH.png");
//    QPixmap scaledPixmapsS = pixmapsS.scaled(ui->label_39->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    ui->label_39->setAlignment(Qt::AlignCenter);
//    ui->label_39->setPixmap(scaledPixmapsS);

//    QPixmap pixmapS(":/Images/ranking-S.png");
//    QPixmap scaledPixmapS = pixmapS.scaled(ui->label_40->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    ui->label_40->setAlignment(Qt::AlignCenter);
//    ui->label_40->setPixmap(scaledPixmapS);

//    QPixmap pixmapA(":/Images/ranking-A.png");
//    QPixmap scaledPixmapA = pixmapA.scaled(ui->label_41->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    ui->label_41->setAlignment(Qt::AlignCenter);
//    ui->label_41->setPixmap(scaledPixmapA);
//}

//void MainWindow::on_goChoosePage_pressed()
//{
//    ui->contentViewer->setCurrentIndex(0);
//}

//void MainWindow::on_goRecentButton_pressed()
//{
//    const int playCount = m_osuParser.getPlayCount();
//    if (playCount < 50)
//    {
//        QMessageBox::warning(nullptr, "Recent plays", "Insufficient number of maps played");
//        return;
//    }

//    if (m_isChoosePlayer)
//    {
//        ui->contentViewer->setCurrentIndex(2);
//    }
//    else
//    {
//        QMessageBox::warning(nullptr, "Recent plays", "The player is not choosed");
//    }
//}

//void MainWindow::on_goBitmapLoaderButton_pressed()
//{
//    ui->contentViewer->setCurrentIndex(6);
//}

//void MainWindow::on_setFolderButton_pressed()
//{
//    const QString folderPath = QFileDialog::getExistingDirectory(nullptr, "Choose a songs folder", "", QFileDialog::ShowDirsOnly);

//    if (folderPath.isEmpty())
//    {
//        return;
//    }

//    ui->songsFolderPath->setText(folderPath);
//}

//void MainWindow::on_startDownloaderButton_pressed()
//{
////    const QString roomName = ui->roomName->text();
////    const QString roomID = ui->roomID->text();

////    if (roomName.isEmpty() && roomID.isEmpty())
////    {
////        QMessageBox::warning(nullptr, "Bitmap downloader", "The fields is empty");
////        return;
////    }

////    QString matchID;
////    if (!roomID.isEmpty())
////    {
////        matchID = roomID;
////    }
////    else
////    {
////        matchID = m_osuParser.getMatchID(roomName);
////        if (matchID.isEmpty())
////        {
////            QMessageBox::warning(nullptr, "Bitmap downloader", "Couldn't find a room (errors may occur when the number of rooms is >50). Try using id search");
////            return;
////        }
////    }

////    QJsonDocument matchJson = m_osuParser.getMatchJson(matchID);
////    if (matchJson.isEmpty() || matchJson["error"].isNull())
////    {
////        QMessageBox::warning(nullptr, "Bitmap downloader", "Couldn't find a room");
////        return;
////    }

////    ui->roomJsonViewer->setText(m_osuParser.getMatchInfo());


//}

void MainWindow::loadUrlImage(QPixmap *pixmap, const QUrl &url)
{
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(QNetworkRequest(url));

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

void MainWindow::setTableMode()
{
    if (m_appPersistentData.isTableModeAdd)
    {
        m_ui->tableModeButton->setText(Special::tableModeAdd);
    }
    else
    {
        m_ui->tableModeButton->setText(Special::tableModeRemove);
    }
}

void MainWindow::setTableUsers()
{
    if (!settings::isSaveData)
    {
        return;
    }

    for (int i = 0; i < m_settings::tableSize; i++)
    {
        for (int j = 0; j < m_settings::tableSize; j++)
        {
            const QString username = m_appPersistentData.users[i][j].username;
            if (!username.isEmpty())
            {
                const QPixmap avatar = m_appPersistentData.users[i][j].image;
                setUserTable(i, j, username, avatar);
            }
        }
    }
}

void MainWindow::setUserTable(int row, int column, const QString &username, const QPixmap &avatar)
{
    QWidget *player = new QWidget();
    QLabel *usernameLabel = new QLabel(username);

    QLabel *imageLabel = new QLabel();
    imageLabel->setPixmap(avatar.scaled(m_settings::pixmapSize, m_settings::pixmapSize, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

    QVBoxLayout *layout = new QVBoxLayout(player);
    layout->addWidget(usernameLabel, 0, Qt::AlignHCenter | Qt::AlignTop);
    layout->addWidget(imageLabel, 0, Qt::AlignHCenter | Qt::AlignVCenter);

    QFont font = usernameLabel->font();
    font.setWeight(QFont::Bold);
    usernameLabel->setFont(font);

    m_ui->userTable->setCellWidget(row, column, player);
}

QString MainWindow::getUserJsonFromUsername(const QString &username)
{
    for (int i = 0; i < m_settings::tableSize; i++)
    {
        for (int j = 0; j < m_settings::tableSize; j++)
        {
            const QString cellUsername = m_appPersistentData.users[i][j].username;
            if (cellUsername == username)
            {
                return m_appPersistentData.users[i][j].userInfo;
            }
        }
    }

    return QString();
}

void MainWindow::addCell(int row, int column)
{
    bool isOk;
    const QString input = QInputDialog::getText(nullptr, "Add a new player...", "Enter a nickname:", QLineEdit::Normal, "username", &isOk);
    if (!isOk)
    {
        return;
    }

    if (input.isEmpty() || !m_osuParser.setPlayer(input))
    {
        QMessageBox::warning(nullptr, "Add a new player...", "Couldn't find a player");
        return;
    }

    const QString username = m_osuParser.getUsername();
    const QString userInfo = m_osuParser.getUserInfo();
    const QString avatarUrl = m_osuParser.getAvatarUrl();

    m_ui->jsonViewer->setText(userInfo);

    QPixmap avatar;
    loadUrlImage(&avatar, avatarUrl);

    m_appPersistentData.users[row][column].username = username;
    m_appPersistentData.users[row][column].userInfo = userInfo;
    m_appPersistentData.users[row][column].image = avatar;

    setUserTable(row, column, username, avatar);
}

void MainWindow::clearCell(int row, int column)
{
    m_appPersistentData.users[row][column].username = QString();
    m_ui->userTable->setCellWidget(row, column, nullptr);
    m_ui->jsonViewer->clear();
}

void MainWindow::chooseCell(int row, int column)
{
    const QWidget *widget = m_ui->userTable->cellWidget(row, column);
    const QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(widget->layout());

    const QLabel *usernameLabel = qobject_cast<QLabel*>(layout->itemAt(0)->widget());
    const QLabel *imageLabel = qobject_cast<QLabel*>(layout->itemAt(1)->widget());

    QLabel *uiUsername = m_ui->chooseUsername;
    QLabel *uiImage = m_ui->chooseImage;

    uiUsername->setText(usernameLabel->text());
    uiUsername->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    uiImage->setPixmap(imageLabel->pixmap());
    uiImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    m_appPersistentData.isChooseUser = true;
}

void MainWindow::on_viewJsonCheckBox_stateChanged(int state)
{
    if (state == Qt::Unchecked)
    {
        m_ui->jsonViewer->hide();
    }
    else
    {
        m_ui->jsonViewer->show();
    }
}

void MainWindow::on_userTable_cellClicked(int row, int column)
{
    const QTableWidget *table = m_ui->userTable;

    const QWidget *widget = table->cellWidget(row, column);
    if (widget)
    {
        QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(widget->layout());
        if (layout)
        {
            const QLabel *usernameLabel = qobject_cast<QLabel*>(layout->itemAt(0)->widget());
            const QString username = usernameLabel->text();

            m_ui->jsonViewer->setText(getUserJsonFromUsername(username));

            return;
        }
    }

    m_ui->jsonViewer->clear();
}

void MainWindow::on_userTable_cellDoubleClicked(int row, int column)
{
    const QWidget *widget = m_ui->userTable->cellWidget(row, column);
    if (m_appPersistentData.isTableModeAdd)
    {
        if (widget == nullptr)
        {
            addCell(row, column);
        }
        else
        {
            chooseCell(row,column);
        }
    }
    else
    {
        clearCell(row, column);
    }
}

void MainWindow::loadUserScores()
{
    m_osuParser.getTopScores(m_osuParser.getUserId());
    m_osuParser.initStats();

  //  m_appPersistentData.usersScoresJson.insert(m_osuParser.getUsername(), m_osuParser.getTopScoresInfo());
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    m_ui->userTable->setColumnCount(value);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    m_ui->userTable->setRowCount(value);
}

void MainWindow::on_tableModeButton_pressed()
{
    m_appPersistentData.isTableModeAdd = !m_appPersistentData.isTableModeAdd;

    setTableMode();
}
