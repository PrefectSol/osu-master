/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QWidget *buttonPanel;
    QVBoxLayout *verticalLayout;
    QPushButton *goChoosePage;
    QWidget *playerViewer;
    QVBoxLayout *verticalLayout_3;
    QLabel *chooseUsername;
    QLabel *chooseImage;
    QSpacerItem *verticalSpacer;
    QPushButton *goOverviewButton;
    QPushButton *goRecentButton;
    QPushButton *visualizerButton;
    QPushButton *topButton;
    QPushButton *goDuelButton;
    QPushButton *goBitmapLoaderButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *goSettingsPage;
    QPushButton *goOtherToolsButton;
    QStackedWidget *contentViewer;
    QWidget *choosePage;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *chooseButton;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *clearButton;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_16;
    QSpinBox *rowsSpinBox;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_17;
    QSpinBox *colsSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *viewJsonCheckBox;
    QTableWidget *userTable;
    QTextBrowser *jsonViewer;
    QWidget *overviewPage_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *usernamelabel_2;
    QLabel *globalranklabel;
    QLabel *ranklabel;
    QLabel *picturelabel_2;
    QGraphicsView *graphicsView;
    QWidget *recentPage;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QWidget *visualizerPage;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QWidget *topPage;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QWidget *duelPage;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QWidget *bitmapDownloaderPage;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QLineEdit *roomName;
    QLabel *label_24;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_25;
    QLineEdit *roomID;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *startDownloaderButton;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_22;
    QLabel *label_23;
    QTextBrowser *roomJsonViewer;
    QWidget *settingsPage;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QCheckBox *saveDataCheckBox;
    QPushButton *removeDataButton;
    QCheckBox *useSearchCheckBox;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_10;
    QTextBrowser *songsFolderPath;
    QPushButton *setFolderButton;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_19;
    QLabel *label_18;
    QSpacerItem *verticalSpacer_4;
    QWidget *otherPage;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(961, 652);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        buttonPanel = new QWidget(centralwidget);
        buttonPanel->setObjectName("buttonPanel");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonPanel->sizePolicy().hasHeightForWidth());
        buttonPanel->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(buttonPanel);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        goChoosePage = new QPushButton(buttonPanel);
        goChoosePage->setObjectName("goChoosePage");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(goChoosePage->sizePolicy().hasHeightForWidth());
        goChoosePage->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(goChoosePage);

        playerViewer = new QWidget(buttonPanel);
        playerViewer->setObjectName("playerViewer");
        sizePolicy.setHeightForWidth(playerViewer->sizePolicy().hasHeightForWidth());
        playerViewer->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(playerViewer);
        verticalLayout_3->setObjectName("verticalLayout_3");
        chooseUsername = new QLabel(playerViewer);
        chooseUsername->setObjectName("chooseUsername");
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        chooseUsername->setFont(font);

        verticalLayout_3->addWidget(chooseUsername);

        chooseImage = new QLabel(playerViewer);
        chooseImage->setObjectName("chooseImage");
        chooseImage->setMinimumSize(QSize(110, 110));

        verticalLayout_3->addWidget(chooseImage);


        verticalLayout->addWidget(playerViewer);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        goOverviewButton = new QPushButton(buttonPanel);
        goOverviewButton->setObjectName("goOverviewButton");
        sizePolicy1.setHeightForWidth(goOverviewButton->sizePolicy().hasHeightForWidth());
        goOverviewButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(goOverviewButton);

        goRecentButton = new QPushButton(buttonPanel);
        goRecentButton->setObjectName("goRecentButton");
        sizePolicy1.setHeightForWidth(goRecentButton->sizePolicy().hasHeightForWidth());
        goRecentButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(goRecentButton);

        visualizerButton = new QPushButton(buttonPanel);
        visualizerButton->setObjectName("visualizerButton");
        sizePolicy1.setHeightForWidth(visualizerButton->sizePolicy().hasHeightForWidth());
        visualizerButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(visualizerButton);

        topButton = new QPushButton(buttonPanel);
        topButton->setObjectName("topButton");
        sizePolicy1.setHeightForWidth(topButton->sizePolicy().hasHeightForWidth());
        topButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(topButton);

        goDuelButton = new QPushButton(buttonPanel);
        goDuelButton->setObjectName("goDuelButton");
        sizePolicy1.setHeightForWidth(goDuelButton->sizePolicy().hasHeightForWidth());
        goDuelButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(goDuelButton);

        goBitmapLoaderButton = new QPushButton(buttonPanel);
        goBitmapLoaderButton->setObjectName("goBitmapLoaderButton");
        sizePolicy1.setHeightForWidth(goBitmapLoaderButton->sizePolicy().hasHeightForWidth());
        goBitmapLoaderButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(goBitmapLoaderButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        goSettingsPage = new QPushButton(buttonPanel);
        goSettingsPage->setObjectName("goSettingsPage");
        sizePolicy1.setHeightForWidth(goSettingsPage->sizePolicy().hasHeightForWidth());
        goSettingsPage->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(goSettingsPage);

        goOtherToolsButton = new QPushButton(buttonPanel);
        goOtherToolsButton->setObjectName("goOtherToolsButton");
        sizePolicy1.setHeightForWidth(goOtherToolsButton->sizePolicy().hasHeightForWidth());
        goOtherToolsButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(goOtherToolsButton);


        formLayout->setWidget(0, QFormLayout::LabelRole, buttonPanel);

        contentViewer = new QStackedWidget(centralwidget);
        contentViewer->setObjectName("contentViewer");
        choosePage = new QWidget();
        choosePage->setObjectName("choosePage");
        gridLayout_8 = new QGridLayout(choosePage);
        gridLayout_8->setObjectName("gridLayout_8");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        chooseButton = new QPushButton(choosePage);
        chooseButton->setObjectName("chooseButton");

        horizontalLayout_2->addWidget(chooseButton);

        addButton = new QPushButton(choosePage);
        addButton->setObjectName("addButton");

        horizontalLayout_2->addWidget(addButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        clearButton = new QPushButton(choosePage);
        clearButton->setObjectName("clearButton");

        horizontalLayout_2->addWidget(clearButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_16 = new QLabel(choosePage);
        label_16->setObjectName("label_16");

        horizontalLayout_4->addWidget(label_16);

        rowsSpinBox = new QSpinBox(choosePage);
        rowsSpinBox->setObjectName("rowsSpinBox");
        rowsSpinBox->setMinimum(0);
        rowsSpinBox->setMaximum(10);
        rowsSpinBox->setValue(0);

        horizontalLayout_4->addWidget(rowsSpinBox);


        horizontalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName("horizontalLayout_32");
        label_17 = new QLabel(choosePage);
        label_17->setObjectName("label_17");

        horizontalLayout_32->addWidget(label_17);

        colsSpinBox = new QSpinBox(choosePage);
        colsSpinBox->setObjectName("colsSpinBox");
        colsSpinBox->setMaximum(20);

        horizontalLayout_32->addWidget(colsSpinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_3);


        horizontalLayout_3->addLayout(horizontalLayout_32);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout_8->addLayout(verticalLayout_2, 0, 0, 1, 1);

        viewJsonCheckBox = new QCheckBox(choosePage);
        viewJsonCheckBox->setObjectName("viewJsonCheckBox");

        gridLayout_8->addWidget(viewJsonCheckBox, 0, 1, 1, 1);

        userTable = new QTableWidget(choosePage);
        userTable->setObjectName("userTable");
        userTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        userTable->setSelectionMode(QAbstractItemView::SingleSelection);
        userTable->setRowCount(0);
        userTable->setColumnCount(0);
        userTable->horizontalHeader()->setVisible(false);
        userTable->horizontalHeader()->setCascadingSectionResizes(true);
        userTable->horizontalHeader()->setMinimumSectionSize(130);
        userTable->horizontalHeader()->setDefaultSectionSize(130);
        userTable->verticalHeader()->setVisible(false);
        userTable->verticalHeader()->setCascadingSectionResizes(true);
        userTable->verticalHeader()->setMinimumSectionSize(150);
        userTable->verticalHeader()->setDefaultSectionSize(150);

        gridLayout_8->addWidget(userTable, 1, 0, 1, 1);

        jsonViewer = new QTextBrowser(choosePage);
        jsonViewer->setObjectName("jsonViewer");
        sizePolicy1.setHeightForWidth(jsonViewer->sizePolicy().hasHeightForWidth());
        jsonViewer->setSizePolicy(sizePolicy1);
        jsonViewer->setMinimumSize(QSize(30, 0));
        jsonViewer->setMaximumSize(QSize(500, 16777215));

        gridLayout_8->addWidget(jsonViewer, 1, 1, 1, 1);

        contentViewer->addWidget(choosePage);
        overviewPage_2 = new QWidget();
        overviewPage_2->setObjectName("overviewPage_2");
        layoutWidget = new QWidget(overviewPage_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(480, 150, 203, 134));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        usernamelabel_2 = new QLabel(layoutWidget);
        usernamelabel_2->setObjectName("usernamelabel_2");
        usernamelabel_2->setFont(font);

        gridLayout_2->addWidget(usernamelabel_2, 0, 1, 1, 1);

        globalranklabel = new QLabel(layoutWidget);
        globalranklabel->setObjectName("globalranklabel");

        gridLayout_2->addWidget(globalranklabel, 1, 1, 1, 1);

        ranklabel = new QLabel(layoutWidget);
        ranklabel->setObjectName("ranklabel");

        gridLayout_2->addWidget(ranklabel, 1, 2, 1, 1);

        picturelabel_2 = new QLabel(layoutWidget);
        picturelabel_2->setObjectName("picturelabel_2");
        picturelabel_2->setMinimumSize(QSize(110, 110));

        gridLayout_2->addWidget(picturelabel_2, 0, 0, 2, 1);

        graphicsView = new QGraphicsView(overviewPage_2);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(100, 130, 256, 192));
        contentViewer->addWidget(overviewPage_2);
        recentPage = new QWidget();
        recentPage->setObjectName("recentPage");
        horizontalLayout_6 = new QHBoxLayout(recentPage);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_2 = new QLabel(recentPage);
        label_2->setObjectName("label_2");

        horizontalLayout_6->addWidget(label_2);

        contentViewer->addWidget(recentPage);
        visualizerPage = new QWidget();
        visualizerPage->setObjectName("visualizerPage");
        verticalLayout_6 = new QVBoxLayout(visualizerPage);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_3 = new QLabel(visualizerPage);
        label_3->setObjectName("label_3");

        verticalLayout_6->addWidget(label_3);

        contentViewer->addWidget(visualizerPage);
        topPage = new QWidget();
        topPage->setObjectName("topPage");
        horizontalLayout_7 = new QHBoxLayout(topPage);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_4 = new QLabel(topPage);
        label_4->setObjectName("label_4");

        horizontalLayout_7->addWidget(label_4);

        contentViewer->addWidget(topPage);
        duelPage = new QWidget();
        duelPage->setObjectName("duelPage");
        horizontalLayout_8 = new QHBoxLayout(duelPage);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_5 = new QLabel(duelPage);
        label_5->setObjectName("label_5");

        horizontalLayout_8->addWidget(label_5);

        contentViewer->addWidget(duelPage);
        bitmapDownloaderPage = new QWidget();
        bitmapDownloaderPage->setObjectName("bitmapDownloaderPage");
        verticalLayout_11 = new QVBoxLayout(bitmapDownloaderPage);
        verticalLayout_11->setObjectName("verticalLayout_11");
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_8);

        label_10 = new QLabel(bitmapDownloaderPage);
        label_10->setObjectName("label_10");
        QFont font1;
        font1.setPointSize(13);
        label_10->setFont(font1);

        horizontalLayout_14->addWidget(label_10);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_9);


        verticalLayout_11->addLayout(horizontalLayout_14);

        label_21 = new QLabel(bitmapDownloaderPage);
        label_21->setObjectName("label_21");

        verticalLayout_11->addWidget(label_21);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_6 = new QLabel(bitmapDownloaderPage);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_6);

        roomName = new QLineEdit(bitmapDownloaderPage);
        roomName->setObjectName("roomName");

        verticalLayout_5->addWidget(roomName);


        horizontalLayout_15->addLayout(verticalLayout_5);

        label_24 = new QLabel(bitmapDownloaderPage);
        label_24->setObjectName("label_24");

        horizontalLayout_15->addWidget(label_24);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_25 = new QLabel(bitmapDownloaderPage);
        label_25->setObjectName("label_25");
        label_25->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_25);

        roomID = new QLineEdit(bitmapDownloaderPage);
        roomID->setObjectName("roomID");

        verticalLayout_10->addWidget(roomID);


        horizontalLayout_15->addLayout(verticalLayout_10);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_11);


        verticalLayout_11->addLayout(horizontalLayout_15);

        label_15 = new QLabel(bitmapDownloaderPage);
        label_15->setObjectName("label_15");

        verticalLayout_11->addWidget(label_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_9 = new QLabel(bitmapDownloaderPage);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_8->addWidget(label_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        startDownloaderButton = new QPushButton(bitmapDownloaderPage);
        startDownloaderButton->setObjectName("startDownloaderButton");

        horizontalLayout_11->addWidget(startDownloaderButton);


        verticalLayout_8->addLayout(horizontalLayout_11);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        pushButton_2 = new QPushButton(bitmapDownloaderPage);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_9->addWidget(pushButton_2);


        verticalLayout_8->addLayout(horizontalLayout_9);


        horizontalLayout_16->addLayout(verticalLayout_8);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_13);


        verticalLayout_11->addLayout(horizontalLayout_16);

        label_20 = new QLabel(bitmapDownloaderPage);
        label_20->setObjectName("label_20");

        verticalLayout_11->addWidget(label_20);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_11 = new QLabel(bitmapDownloaderPage);
        label_11->setObjectName("label_11");

        horizontalLayout_12->addWidget(label_11);

        label_12 = new QLabel(bitmapDownloaderPage);
        label_12->setObjectName("label_12");

        horizontalLayout_12->addWidget(label_12);


        verticalLayout_9->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_13 = new QLabel(bitmapDownloaderPage);
        label_13->setObjectName("label_13");

        horizontalLayout_13->addWidget(label_13);

        label_14 = new QLabel(bitmapDownloaderPage);
        label_14->setObjectName("label_14");

        horizontalLayout_13->addWidget(label_14);


        verticalLayout_9->addLayout(horizontalLayout_13);


        horizontalLayout_17->addLayout(verticalLayout_9);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_15);


        verticalLayout_11->addLayout(horizontalLayout_17);

        label_22 = new QLabel(bitmapDownloaderPage);
        label_22->setObjectName("label_22");

        verticalLayout_11->addWidget(label_22);

        label_23 = new QLabel(bitmapDownloaderPage);
        label_23->setObjectName("label_23");

        verticalLayout_11->addWidget(label_23);

        roomJsonViewer = new QTextBrowser(bitmapDownloaderPage);
        roomJsonViewer->setObjectName("roomJsonViewer");

        verticalLayout_11->addWidget(roomJsonViewer);

        contentViewer->addWidget(bitmapDownloaderPage);
        settingsPage = new QWidget();
        settingsPage->setObjectName("settingsPage");
        gridLayout = new QGridLayout(settingsPage);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        saveDataCheckBox = new QCheckBox(settingsPage);
        saveDataCheckBox->setObjectName("saveDataCheckBox");

        horizontalLayout->addWidget(saveDataCheckBox);

        removeDataButton = new QPushButton(settingsPage);
        removeDataButton->setObjectName("removeDataButton");

        horizontalLayout->addWidget(removeDataButton);


        verticalLayout_4->addLayout(horizontalLayout);

        useSearchCheckBox = new QCheckBox(settingsPage);
        useSearchCheckBox->setObjectName("useSearchCheckBox");

        verticalLayout_4->addWidget(useSearchCheckBox);

        label_8 = new QLabel(settingsPage);
        label_8->setObjectName("label_8");

        verticalLayout_4->addWidget(label_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        songsFolderPath = new QTextBrowser(settingsPage);
        songsFolderPath->setObjectName("songsFolderPath");
        songsFolderPath->setMaximumSize(QSize(16777214, 40));
        songsFolderPath->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        songsFolderPath->setLineWrapMode(QTextEdit::NoWrap);

        horizontalLayout_10->addWidget(songsFolderPath);

        setFolderButton = new QPushButton(settingsPage);
        setFolderButton->setObjectName("setFolderButton");

        horizontalLayout_10->addWidget(setFolderButton);


        verticalLayout_4->addLayout(horizontalLayout_10);

        verticalSpacer_3 = new QSpacerItem(20, 338, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 4, 3);

        horizontalSpacer = new QSpacerItem(348, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_19 = new QLabel(settingsPage);
        label_19->setObjectName("label_19");

        gridLayout->addWidget(label_19, 1, 2, 1, 1);

        label_18 = new QLabel(settingsPage);
        label_18->setObjectName("label_18");

        gridLayout->addWidget(label_18, 2, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 111, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 4, 1, 1, 1);

        contentViewer->addWidget(settingsPage);
        otherPage = new QWidget();
        otherPage->setObjectName("otherPage");
        verticalLayout_7 = new QVBoxLayout(otherPage);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_7 = new QLabel(otherPage);
        label_7->setObjectName("label_7");

        verticalLayout_7->addWidget(label_7);

        contentViewer->addWidget(otherPage);

        formLayout->setWidget(0, QFormLayout::FieldRole, contentViewer);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        contentViewer->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "osu! master", nullptr));
        goChoosePage->setText(QCoreApplication::translate("MainWindow", "Choose a player...", nullptr));
        chooseUsername->setText(QString());
        chooseImage->setText(QString());
        goOverviewButton->setText(QCoreApplication::translate("MainWindow", "Overview", nullptr));
        goRecentButton->setText(QCoreApplication::translate("MainWindow", "Recent plays", nullptr));
        visualizerButton->setText(QCoreApplication::translate("MainWindow", "Visualizer", nullptr));
        topButton->setText(QCoreApplication::translate("MainWindow", "Top", nullptr));
        goDuelButton->setText(QCoreApplication::translate("MainWindow", "Duel", nullptr));
        goBitmapLoaderButton->setText(QCoreApplication::translate("MainWindow", "Bitmap loader", nullptr));
        goSettingsPage->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        goOtherToolsButton->setText(QCoreApplication::translate("MainWindow", "Other tools", nullptr));
        chooseButton->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add new player", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear player", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Rows:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Columns:", nullptr));
        viewJsonCheckBox->setText(QCoreApplication::translate("MainWindow", "View Json", nullptr));
        usernamelabel_2->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        globalranklabel->setText(QCoreApplication::translate("MainWindow", "globalrank", nullptr));
        ranklabel->setText(QCoreApplication::translate("MainWindow", "rank", nullptr));
        picturelabel_2->setText(QCoreApplication::translate("MainWindow", "pic", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "RECENT PLAYS", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "VISUALIZER", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TOP", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "DUEL", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Auto bitmap downloader", nullptr));
        label_21->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Enter the name of the multiplayer room:", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "OR", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Enter the ID of the multiplayer room: (priority)", nullptr));
        label_15->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Downloader Menu", nullptr));
        startDownloaderButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        label_20->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        label_12->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Current bitmap:", nullptr));
        label_14->setText(QString());
        label_22->setText(QString());
        label_23->setText(QCoreApplication::translate("MainWindow", "Room json:", nullptr));
        saveDataCheckBox->setText(QCoreApplication::translate("MainWindow", "Save application data", nullptr));
        removeDataButton->setText(QCoreApplication::translate("MainWindow", "Remove data folder", nullptr));
        useSearchCheckBox->setText(QCoreApplication::translate("MainWindow", "Use player search", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Path to osu! maps:", nullptr));
        setFolderButton->setText(QCoreApplication::translate("MainWindow", "Set folder", nullptr));
        label_19->setText(QString());
        label_18->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "OTHER TOOLS (links) to drivers, pp counters, overlays and etc...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
