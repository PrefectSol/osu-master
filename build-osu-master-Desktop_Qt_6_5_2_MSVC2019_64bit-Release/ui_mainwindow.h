/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
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
    QPushButton *goOverviewPage;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QSpacerItem *verticalSpacer_2;
    QPushButton *goSettingsPage;
    QStackedWidget *contentViewer;
    QWidget *choosePage;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *viewJsonCheckBox;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_16;
    QPushButton *tableModeButton;
    QSpacerItem *horizontalSpacer_2;
    QSlider *horizontalSlider;
    QTableWidget *userTable;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_8;
    QSlider *verticalSlider;
    QTextBrowser *jsonViewer;
    QWidget *overviewPage;
    QGridLayout *gridLayout_4;
    QLabel *label_44;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_12;
    QFormLayout *formLayout_2;
    QGroupBox *MainPlayerStats;
    QGridLayout *gridLayout_2;
    QLabel *playcountlabel;
    QLabel *label_43;
    QLabel *label_33;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *picturelabel_2;
    QLabel *countrylabel;
    QSpacerItem *verticalSpacer_7;
    QLabel *globalranklabel;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_37;
    QLabel *sSSlabel;
    QLabel *label_38;
    QLabel *SSlabel;
    QLabel *label_39;
    QLabel *sSlabel;
    QLabel *label_40;
    QLabel *Slabel;
    QLabel *label_41;
    QLabel *Alabel;
    QLabel *accuracylabel;
    QLabel *PPlabel;
    QHBoxLayout *horizontalLayout_22;
    QLabel *usercountrylabel;
    QLabel *usernamelabel_2;
    QLabel *label_34;
    QGroupBox *StatsCountbox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_29;
    QLabel *aimValueLabel;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_30;
    QLabel *accuracyValueLabel;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_31;
    QLabel *speedValueLabel;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_32;
    QLabel *staminaValueLabel;
    QGroupBox *graphicbox;
    QGridLayout *gridLayout_3;
    QLabel *label_27;
    QLabel *label;
    QLabel *label_28;
    QGraphicsView *graphicsView;
    QLabel *label_26;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QWidget *settingsPage;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QCheckBox *saveDataCheckBox;
    QPushButton *removeDataButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_19;
    QLabel *label_18;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(845, 681);
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
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        goChoosePage = new QPushButton(buttonPanel);
        goChoosePage->setObjectName("goChoosePage");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(goChoosePage->sizePolicy().hasHeightForWidth());
        goChoosePage->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setStyleStrategy(QFont::PreferAntialias);
        goChoosePage->setFont(font);

        verticalLayout->addWidget(goChoosePage);

        playerViewer = new QWidget(buttonPanel);
        playerViewer->setObjectName("playerViewer");
        sizePolicy.setHeightForWidth(playerViewer->sizePolicy().hasHeightForWidth());
        playerViewer->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(playerViewer);
        verticalLayout_3->setObjectName("verticalLayout_3");
        chooseUsername = new QLabel(playerViewer);
        chooseUsername->setObjectName("chooseUsername");
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStyleStrategy(QFont::PreferAntialias);
        chooseUsername->setFont(font1);

        verticalLayout_3->addWidget(chooseUsername);

        chooseImage = new QLabel(playerViewer);
        chooseImage->setObjectName("chooseImage");
        chooseImage->setMinimumSize(QSize(110, 110));

        verticalLayout_3->addWidget(chooseImage);


        verticalLayout->addWidget(playerViewer);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        goOverviewPage = new QPushButton(buttonPanel);
        goOverviewPage->setObjectName("goOverviewPage");
        sizePolicy1.setHeightForWidth(goOverviewPage->sizePolicy().hasHeightForWidth());
        goOverviewPage->setSizePolicy(sizePolicy1);
        goOverviewPage->setFont(font);

        verticalLayout->addWidget(goOverviewPage);

        pushButton = new QPushButton(buttonPanel);
        pushButton->setObjectName("pushButton");
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(buttonPanel);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(buttonPanel);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(buttonPanel);
        pushButton_5->setObjectName("pushButton_5");
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(buttonPanel);
        pushButton_6->setObjectName("pushButton_6");
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(buttonPanel);
        pushButton_7->setObjectName("pushButton_7");
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        goSettingsPage = new QPushButton(buttonPanel);
        goSettingsPage->setObjectName("goSettingsPage");
        sizePolicy1.setHeightForWidth(goSettingsPage->sizePolicy().hasHeightForWidth());
        goSettingsPage->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setStyleStrategy(QFont::PreferAntialias);
        goSettingsPage->setFont(font2);

        verticalLayout->addWidget(goSettingsPage);


        formLayout->setWidget(0, QFormLayout::LabelRole, buttonPanel);

        contentViewer = new QStackedWidget(centralwidget);
        contentViewer->setObjectName("contentViewer");
        contentViewer->setStyleSheet(QString::fromUtf8(""));
        contentViewer->setFrameShape(QFrame::NoFrame);
        contentViewer->setFrameShadow(QFrame::Plain);
        contentViewer->setLineWidth(0);
        contentViewer->setMidLineWidth(0);
        choosePage = new QWidget();
        choosePage->setObjectName("choosePage");
        gridLayout_7 = new QGridLayout(choosePage);
        gridLayout_7->setObjectName("gridLayout_7");
        horizontalSpacer_3 = new QSpacerItem(571, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        viewJsonCheckBox = new QCheckBox(choosePage);
        viewJsonCheckBox->setObjectName("viewJsonCheckBox");
        QFont font3;
        font3.setPointSize(9);
        font3.setStyleStrategy(QFont::PreferAntialias);
        viewJsonCheckBox->setFont(font3);

        gridLayout_7->addWidget(viewJsonCheckBox, 0, 1, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName("gridLayout_6");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_16 = new QLabel(choosePage);
        label_16->setObjectName("label_16");
        QFont font4;
        font4.setBold(true);
        label_16->setFont(font4);

        horizontalLayout_2->addWidget(label_16);

        tableModeButton = new QPushButton(choosePage);
        tableModeButton->setObjectName("tableModeButton");
        QFont font5;
        font5.setBold(false);
        font5.setStyleStrategy(QFont::PreferAntialias);
        tableModeButton->setFont(font5);

        horizontalLayout_2->addWidget(tableModeButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalSlider = new QSlider(choosePage);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setMaximum(16);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedControls(true);

        horizontalLayout_2->addWidget(horizontalSlider);


        gridLayout_6->addLayout(horizontalLayout_2, 1, 0, 1, 1);

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

        gridLayout_6->addWidget(userTable, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);

        verticalSlider = new QSlider(choosePage);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setMaximum(16);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setInvertedAppearance(true);
        verticalSlider->setInvertedControls(true);

        verticalLayout_2->addWidget(verticalSlider);


        gridLayout_6->addLayout(verticalLayout_2, 0, 1, 1, 1);

        jsonViewer = new QTextBrowser(choosePage);
        jsonViewer->setObjectName("jsonViewer");
        sizePolicy1.setHeightForWidth(jsonViewer->sizePolicy().hasHeightForWidth());
        jsonViewer->setSizePolicy(sizePolicy1);
        jsonViewer->setMinimumSize(QSize(30, 0));
        jsonViewer->setMaximumSize(QSize(500, 16777215));

        gridLayout_6->addWidget(jsonViewer, 0, 2, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 1, 0, 1, 2);

        contentViewer->addWidget(choosePage);
        overviewPage = new QWidget();
        overviewPage->setObjectName("overviewPage");
        gridLayout_4 = new QGridLayout(overviewPage);
        gridLayout_4->setObjectName("gridLayout_4");
        label_44 = new QLabel(overviewPage);
        label_44->setObjectName("label_44");

        gridLayout_4->addWidget(label_44, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_5, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(186, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 1, 1, 1, 1);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        MainPlayerStats = new QGroupBox(overviewPage);
        MainPlayerStats->setObjectName("MainPlayerStats");
        QFont font6;
        font6.setBold(false);
        MainPlayerStats->setFont(font6);
        MainPlayerStats->setAlignment(Qt::AlignCenter);
        MainPlayerStats->setFlat(false);
        MainPlayerStats->setCheckable(false);
        gridLayout_2 = new QGridLayout(MainPlayerStats);
        gridLayout_2->setObjectName("gridLayout_2");
        playcountlabel = new QLabel(MainPlayerStats);
        playcountlabel->setObjectName("playcountlabel");
        playcountlabel->setFont(font5);
        playcountlabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(playcountlabel, 6, 1, 1, 1);

        label_43 = new QLabel(MainPlayerStats);
        label_43->setObjectName("label_43");
        label_43->setFont(font4);
        label_43->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_43, 5, 0, 1, 1);

        label_33 = new QLabel(MainPlayerStats);
        label_33->setObjectName("label_33");
        QFont font7;
        font7.setBold(true);
        font7.setStyleStrategy(QFont::PreferAntialias);
        label_33->setFont(font7);
        label_33->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_33, 6, 0, 1, 1);

        label_35 = new QLabel(MainPlayerStats);
        label_35->setObjectName("label_35");
        label_35->setFont(font7);
        label_35->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_35, 1, 0, 1, 1);

        label_36 = new QLabel(MainPlayerStats);
        label_36->setObjectName("label_36");
        label_36->setFont(font7);
        label_36->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_36, 2, 0, 1, 1);

        picturelabel_2 = new QLabel(MainPlayerStats);
        picturelabel_2->setObjectName("picturelabel_2");
        picturelabel_2->setMinimumSize(QSize(100, 100));
        picturelabel_2->setSizeIncrement(QSize(0, 0));
        picturelabel_2->setFrameShape(QFrame::NoFrame);
        picturelabel_2->setFrameShadow(QFrame::Plain);
        picturelabel_2->setLineWidth(3);
        picturelabel_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(picturelabel_2, 0, 0, 1, 1);

        countrylabel = new QLabel(MainPlayerStats);
        countrylabel->setObjectName("countrylabel");
        countrylabel->setFont(font5);
        countrylabel->setScaledContents(true);
        countrylabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(countrylabel, 2, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer_7, 7, 0, 1, 1);

        globalranklabel = new QLabel(MainPlayerStats);
        globalranklabel->setObjectName("globalranklabel");
        globalranklabel->setFont(font5);
        globalranklabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(globalranklabel, 1, 1, 1, 1);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        label_37 = new QLabel(MainPlayerStats);
        label_37->setObjectName("label_37");
        label_37->setMinimumSize(QSize(20, 20));
        label_37->setMaximumSize(QSize(20, 20));
        label_37->setFont(font7);
        label_37->setScaledContents(true);
        label_37->setAlignment(Qt::AlignCenter);
        label_37->setWordWrap(false);
        label_37->setOpenExternalLinks(false);

        horizontalLayout_21->addWidget(label_37);

        sSSlabel = new QLabel(MainPlayerStats);
        sSSlabel->setObjectName("sSSlabel");
        sSSlabel->setMaximumSize(QSize(30, 20));
        sSSlabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(sSSlabel);

        label_38 = new QLabel(MainPlayerStats);
        label_38->setObjectName("label_38");
        label_38->setMinimumSize(QSize(20, 20));
        label_38->setMaximumSize(QSize(20, 20));
        label_38->setFont(font7);
        label_38->setScaledContents(true);
        label_38->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(label_38);

        SSlabel = new QLabel(MainPlayerStats);
        SSlabel->setObjectName("SSlabel");
        SSlabel->setMaximumSize(QSize(30, 20));
        SSlabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(SSlabel);

        label_39 = new QLabel(MainPlayerStats);
        label_39->setObjectName("label_39");
        label_39->setMinimumSize(QSize(20, 20));
        label_39->setMaximumSize(QSize(20, 20));
        label_39->setFont(font7);
        label_39->setScaledContents(true);
        label_39->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(label_39);

        sSlabel = new QLabel(MainPlayerStats);
        sSlabel->setObjectName("sSlabel");
        sSlabel->setMaximumSize(QSize(30, 20));
        sSlabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(sSlabel);

        label_40 = new QLabel(MainPlayerStats);
        label_40->setObjectName("label_40");
        label_40->setMinimumSize(QSize(20, 20));
        label_40->setMaximumSize(QSize(20, 20));
        label_40->setFont(font7);
        label_40->setScaledContents(true);
        label_40->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(label_40);

        Slabel = new QLabel(MainPlayerStats);
        Slabel->setObjectName("Slabel");
        Slabel->setMaximumSize(QSize(30, 20));
        Slabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(Slabel);

        label_41 = new QLabel(MainPlayerStats);
        label_41->setObjectName("label_41");
        label_41->setMinimumSize(QSize(20, 20));
        label_41->setMaximumSize(QSize(20, 20));
        label_41->setFont(font7);
        label_41->setScaledContents(true);
        label_41->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(label_41);

        Alabel = new QLabel(MainPlayerStats);
        Alabel->setObjectName("Alabel");
        Alabel->setMaximumSize(QSize(30, 20));
        Alabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(Alabel);


        gridLayout_2->addLayout(horizontalLayout_21, 8, 0, 1, 2);

        accuracylabel = new QLabel(MainPlayerStats);
        accuracylabel->setObjectName("accuracylabel");
        accuracylabel->setEnabled(true);
        accuracylabel->setFont(font5);
        accuracylabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(accuracylabel, 5, 1, 1, 1);

        PPlabel = new QLabel(MainPlayerStats);
        PPlabel->setObjectName("PPlabel");
        PPlabel->setFont(font5);
        PPlabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(PPlabel, 3, 1, 1, 1);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        usercountrylabel = new QLabel(MainPlayerStats);
        usercountrylabel->setObjectName("usercountrylabel");
        usercountrylabel->setMaximumSize(QSize(20, 20));
        usercountrylabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(usercountrylabel);

        usernamelabel_2 = new QLabel(MainPlayerStats);
        usernamelabel_2->setObjectName("usernamelabel_2");
        usernamelabel_2->setMinimumSize(QSize(0, 0));
        QFont font8;
        font8.setBold(true);
        font8.setItalic(false);
        font8.setUnderline(true);
        font8.setStyleStrategy(QFont::PreferAntialias);
        usernamelabel_2->setFont(font8);
        usernamelabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_22->addWidget(usernamelabel_2);


        gridLayout_2->addLayout(horizontalLayout_22, 0, 1, 1, 1);

        label_34 = new QLabel(MainPlayerStats);
        label_34->setObjectName("label_34");
        label_34->setFont(font7);
        label_34->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_34, 3, 0, 1, 1);


        formLayout_2->setWidget(0, QFormLayout::LabelRole, MainPlayerStats);

        StatsCountbox = new QGroupBox(overviewPage);
        StatsCountbox->setObjectName("StatsCountbox");
        verticalLayout_7 = new QVBoxLayout(StatsCountbox);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_29 = new QLabel(StatsCountbox);
        label_29->setObjectName("label_29");
        label_29->setFont(font7);
        label_29->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_29);

        aimValueLabel = new QLabel(StatsCountbox);
        aimValueLabel->setObjectName("aimValueLabel");
        aimValueLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(aimValueLabel);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_30 = new QLabel(StatsCountbox);
        label_30->setObjectName("label_30");
        label_30->setFont(font7);
        label_30->setAlignment(Qt::AlignCenter);

        horizontalLayout_18->addWidget(label_30);

        accuracyValueLabel = new QLabel(StatsCountbox);
        accuracyValueLabel->setObjectName("accuracyValueLabel");
        accuracyValueLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_18->addWidget(accuracyValueLabel);


        verticalLayout_7->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        label_31 = new QLabel(StatsCountbox);
        label_31->setObjectName("label_31");
        label_31->setFont(font7);
        label_31->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(label_31);

        speedValueLabel = new QLabel(StatsCountbox);
        speedValueLabel->setObjectName("speedValueLabel");
        speedValueLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(speedValueLabel);


        verticalLayout_7->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        label_32 = new QLabel(StatsCountbox);
        label_32->setObjectName("label_32");
        label_32->setFont(font7);
        label_32->setAlignment(Qt::AlignCenter);

        horizontalLayout_20->addWidget(label_32);

        staminaValueLabel = new QLabel(StatsCountbox);
        staminaValueLabel->setObjectName("staminaValueLabel");
        staminaValueLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_20->addWidget(staminaValueLabel);


        verticalLayout_7->addLayout(horizontalLayout_20);


        formLayout_2->setWidget(0, QFormLayout::FieldRole, StatsCountbox);


        verticalLayout_12->addLayout(formLayout_2);

        graphicbox = new QGroupBox(overviewPage);
        graphicbox->setObjectName("graphicbox");
        gridLayout_3 = new QGridLayout(graphicbox);
        gridLayout_3->setObjectName("gridLayout_3");
        label_27 = new QLabel(graphicbox);
        label_27->setObjectName("label_27");
        QFont font9;
        font9.setStyleStrategy(QFont::PreferAntialias);
        label_27->setFont(font9);
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_27, 0, 1, 1, 1);

        label = new QLabel(graphicbox);
        label->setObjectName("label");
        label->setFont(font9);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        label_28 = new QLabel(graphicbox);
        label_28->setObjectName("label_28");
        label_28->setFont(font9);
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_28, 1, 2, 1, 1);

        graphicsView = new QGraphicsView(graphicbox);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setMinimumSize(QSize(250, 250));

        gridLayout_3->addWidget(graphicsView, 1, 1, 1, 1);

        label_26 = new QLabel(graphicbox);
        label_26->setObjectName("label_26");
        label_26->setFont(font9);
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_26, 2, 1, 1, 1);


        verticalLayout_12->addWidget(graphicbox);


        gridLayout_4->addLayout(verticalLayout_12, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(185, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 1, 3, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_6, 2, 2, 1, 1);

        contentViewer->addWidget(overviewPage);
        settingsPage = new QWidget();
        settingsPage->setObjectName("settingsPage");
        gridLayout = new QGridLayout(settingsPage);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_2 = new QLabel(settingsPage);
        label_2->setObjectName("label_2");
        QFont font10;
        font10.setPointSize(13);
        label_2->setFont(font10);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        saveDataCheckBox = new QCheckBox(settingsPage);
        saveDataCheckBox->setObjectName("saveDataCheckBox");
        QFont font11;
        font11.setPointSize(9);
        saveDataCheckBox->setFont(font11);

        horizontalLayout->addWidget(saveDataCheckBox);

        removeDataButton = new QPushButton(settingsPage);
        removeDataButton->setObjectName("removeDataButton");
        removeDataButton->setFont(font11);

        horizontalLayout->addWidget(removeDataButton);


        verticalLayout_4->addLayout(horizontalLayout);

        checkBox = new QCheckBox(settingsPage);
        checkBox->setObjectName("checkBox");

        verticalLayout_4->addWidget(checkBox);

        checkBox_2 = new QCheckBox(settingsPage);
        checkBox_2->setObjectName("checkBox_2");

        verticalLayout_4->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(settingsPage);
        checkBox_3->setObjectName("checkBox_3");

        verticalLayout_4->addWidget(checkBox_3);


        verticalLayout_5->addLayout(verticalLayout_4);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 2, 3);

        horizontalSpacer = new QSpacerItem(386, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_19 = new QLabel(settingsPage);
        label_19->setObjectName("label_19");

        gridLayout->addWidget(label_19, 1, 2, 1, 1);

        label_18 = new QLabel(settingsPage);
        label_18->setObjectName("label_18");

        gridLayout->addWidget(label_18, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(170, 493, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 3, 0, 1, 2);

        contentViewer->addWidget(settingsPage);

        formLayout->setWidget(0, QFormLayout::FieldRole, contentViewer);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        contentViewer->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "osu! master", nullptr));
        goChoosePage->setText(QCoreApplication::translate("MainWindow", "Choose a player...", nullptr));
        chooseUsername->setText(QString());
        chooseImage->setText(QString());
        goOverviewPage->setText(QCoreApplication::translate("MainWindow", "Overview", nullptr));
        pushButton->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Lobby: Host", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Lobby: Connect", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Aim Assist", nullptr));
        goSettingsPage->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        viewJsonCheckBox->setText(QCoreApplication::translate("MainWindow", "View Json", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "MODE:", nullptr));
        tableModeButton->setText(QCoreApplication::translate("MainWindow", "\342\236\225", nullptr));
        label_44->setText(QString());
        MainPlayerStats->setTitle(QString());
        playcountlabel->setText(QString());
        label_43->setText(QCoreApplication::translate("MainWindow", "Accuracy:", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Playcount:", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Rank:", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Country Rank:", nullptr));
        picturelabel_2->setText(QCoreApplication::translate("MainWindow", "Avatar", nullptr));
        countrylabel->setText(QString());
        globalranklabel->setText(QString());
        label_37->setText(QString());
        sSSlabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_38->setText(QString());
        SSlabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_39->setText(QString());
        sSlabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_40->setText(QString());
        Slabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_41->setText(QString());
        Alabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        accuracylabel->setText(QString());
        PPlabel->setText(QString());
        usercountrylabel->setText(QString());
        usernamelabel_2->setText(QString());
        label_34->setText(QCoreApplication::translate("MainWindow", "pp:", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Aim:", nullptr));
        aimValueLabel->setText(QString());
        label_30->setText(QCoreApplication::translate("MainWindow", "Accuracy:", nullptr));
        accuracyValueLabel->setText(QString());
        label_31->setText(QCoreApplication::translate("MainWindow", "Speed:", nullptr));
        speedValueLabel->setText(QString());
        label_32->setText(QCoreApplication::translate("MainWindow", "Stamina:", nullptr));
        staminaValueLabel->setText(QString());
        label_27->setText(QCoreApplication::translate("MainWindow", "AIM", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ACCURACY", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "SPEED", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "STAMINA", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "App config", nullptr));
        saveDataCheckBox->setText(QCoreApplication::translate("MainWindow", "Save application data", nullptr));
        removeDataButton->setText(QCoreApplication::translate("MainWindow", "Remove data folder", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Lorem ipsum", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Lorem ipsum", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Lorem ipsum", nullptr));
        label_19->setText(QString());
        label_18->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
