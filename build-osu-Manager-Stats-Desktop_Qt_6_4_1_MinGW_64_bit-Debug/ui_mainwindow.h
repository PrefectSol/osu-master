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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QPushButton *recentButton;
    QPushButton *visualizerButton;
    QPushButton *topButton;
    QPushButton *goDuelButton;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *goSettingsPage;
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
    QWidget *overviewPage;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_6;
    QWidget *playerViewer_2;
    QVBoxLayout *verticalLayout_9;
    QLabel *usernamelabel;
    QLabel *picturelabel;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_7;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkBox;
    QWidget *settingsPage;
    QGridLayout *gridLayout;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QCheckBox *saveDataCheckBox;
    QPushButton *removeDataButton;
    QCheckBox *useSearchCheckBox;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(910, 652);
        MainWindow->setTabletTracking(false);
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

        recentButton = new QPushButton(buttonPanel);
        recentButton->setObjectName("recentButton");
        sizePolicy1.setHeightForWidth(recentButton->sizePolicy().hasHeightForWidth());
        recentButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(recentButton);

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

        pushButton = new QPushButton(buttonPanel);
        pushButton->setObjectName("pushButton");
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        goSettingsPage = new QPushButton(buttonPanel);
        goSettingsPage->setObjectName("goSettingsPage");
        sizePolicy1.setHeightForWidth(goSettingsPage->sizePolicy().hasHeightForWidth());
        goSettingsPage->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(goSettingsPage);


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
        overviewPage = new QWidget();
        overviewPage->setObjectName("overviewPage");
        gridLayout_3 = new QGridLayout(overviewPage);
        gridLayout_3->setObjectName("gridLayout_3");
        radioButton = new QRadioButton(overviewPage);
        radioButton->setObjectName("radioButton");

        gridLayout_3->addWidget(radioButton, 1, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_6);

        playerViewer_2 = new QWidget(overviewPage);
        playerViewer_2->setObjectName("playerViewer_2");
        sizePolicy.setHeightForWidth(playerViewer_2->sizePolicy().hasHeightForWidth());
        playerViewer_2->setSizePolicy(sizePolicy);
        verticalLayout_9 = new QVBoxLayout(playerViewer_2);
        verticalLayout_9->setObjectName("verticalLayout_9");
        usernamelabel = new QLabel(playerViewer_2);
        usernamelabel->setObjectName("usernamelabel");
        usernamelabel->setFont(font);

        verticalLayout_9->addWidget(usernamelabel);

        picturelabel = new QLabel(playerViewer_2);
        picturelabel->setObjectName("picturelabel");
        picturelabel->setMinimumSize(QSize(110, 110));

        verticalLayout_9->addWidget(picturelabel);


        verticalLayout_10->addWidget(playerViewer_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_5);


        gridLayout_3->addLayout(verticalLayout_10, 0, 3, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_7, 1, 3, 1, 2);

        pushButton_2 = new QPushButton(overviewPage);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_3->addWidget(pushButton_2, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(234, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 4, 1, 1);

        checkBox = new QCheckBox(overviewPage);
        checkBox->setObjectName("checkBox");

        gridLayout_3->addWidget(checkBox, 1, 2, 1, 1);

        contentViewer->addWidget(overviewPage);
        settingsPage = new QWidget();
        settingsPage->setObjectName("settingsPage");
        gridLayout = new QGridLayout(settingsPage);
        gridLayout->setObjectName("gridLayout");
        label_19 = new QLabel(settingsPage);
        label_19->setObjectName("label_19");

        gridLayout->addWidget(label_19, 1, 2, 2, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
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


        verticalLayout_5->addLayout(verticalLayout_4);

        useSearchCheckBox = new QCheckBox(settingsPage);
        useSearchCheckBox->setObjectName("useSearchCheckBox");

        verticalLayout_5->addWidget(useSearchCheckBox);

        verticalSpacer_3 = new QSpacerItem(20, 338, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 3, 2);

        label_18 = new QLabel(settingsPage);
        label_18->setObjectName("label_18");

        gridLayout->addWidget(label_18, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        contentViewer->addWidget(settingsPage);

        formLayout->setWidget(0, QFormLayout::FieldRole, contentViewer);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        contentViewer->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Osu! Stats", nullptr));
        goChoosePage->setText(QCoreApplication::translate("MainWindow", "Choose a player...", nullptr));
        chooseUsername->setText(QString());
        chooseImage->setText(QString());
        goOverviewButton->setText(QCoreApplication::translate("MainWindow", "Overview", nullptr));
        recentButton->setText(QCoreApplication::translate("MainWindow", "Recent plays", nullptr));
        visualizerButton->setText(QCoreApplication::translate("MainWindow", "Visualizer", nullptr));
        topButton->setText(QCoreApplication::translate("MainWindow", "Top", nullptr));
        goDuelButton->setText(QCoreApplication::translate("MainWindow", "Duel", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Overlay", nullptr));
        goSettingsPage->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        chooseButton->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add new player", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear player", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Rows:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Columns:", nullptr));
        viewJsonCheckBox->setText(QCoreApplication::translate("MainWindow", "View Json", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        usernamelabel->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        picturelabel->setText(QCoreApplication::translate("MainWindow", "pic", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
        label_19->setText(QString());
        saveDataCheckBox->setText(QCoreApplication::translate("MainWindow", "Save application data", nullptr));
        removeDataButton->setText(QCoreApplication::translate("MainWindow", "Remove data folder", nullptr));
        useSearchCheckBox->setText(QCoreApplication::translate("MainWindow", "Use player search", nullptr));
        label_18->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
