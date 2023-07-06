/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
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
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *chooseUsername;
    QLabel *chooseAvatar;
    QSpacerItem *verticalSpacer;
    QPushButton *goOverviewButton;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_13;
    QSpacerItem *verticalSpacer_2;
    QPushButton *goSettingsPage;
    QStackedWidget *stackedWidget;
    QWidget *choosePage;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_29;
    QPushButton *chooseButton_8;
    QPushButton *addButton_8;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *clearButton_8;
    QHBoxLayout *horizontalLayout_30;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_16;
    QSpinBox *rowsSpinBox_8;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_17;
    QSpinBox *colsSpinBox_8;
    QSpacerItem *horizontalSpacer_16;
    QCheckBox *viewJsonCheckBox_8;
    QTableWidget *userTable_8;
    QTextBrowser *jsonViewer_8;
    QWidget *overviewPage;
    QWidget *settingsPage;
    QGridLayout *gridLayout;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QCheckBox *saveDataCB;
    QPushButton *removeData;
    QCheckBox *searcherCB;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(910, 652);
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

        widget_3 = new QWidget(buttonPanel);
        widget_3->setObjectName("widget_3");
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        chooseUsername = new QLabel(widget_3);
        chooseUsername->setObjectName("chooseUsername");
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        chooseUsername->setFont(font);

        verticalLayout_3->addWidget(chooseUsername);

        chooseAvatar = new QLabel(widget_3);
        chooseAvatar->setObjectName("chooseAvatar");
        chooseAvatar->setMinimumSize(QSize(110, 110));

        verticalLayout_3->addWidget(chooseAvatar);


        verticalLayout->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        goOverviewButton = new QPushButton(buttonPanel);
        goOverviewButton->setObjectName("goOverviewButton");
        sizePolicy1.setHeightForWidth(goOverviewButton->sizePolicy().hasHeightForWidth());
        goOverviewButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(goOverviewButton);

        pushButton_8 = new QPushButton(buttonPanel);
        pushButton_8->setObjectName("pushButton_8");
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_8);

        pushButton_10 = new QPushButton(buttonPanel);
        pushButton_10->setObjectName("pushButton_10");
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(buttonPanel);
        pushButton_11->setObjectName("pushButton_11");
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_11);

        pushButton_13 = new QPushButton(buttonPanel);
        pushButton_13->setObjectName("pushButton_13");
        sizePolicy1.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_13);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        goSettingsPage = new QPushButton(buttonPanel);
        goSettingsPage->setObjectName("goSettingsPage");
        sizePolicy1.setHeightForWidth(goSettingsPage->sizePolicy().hasHeightForWidth());
        goSettingsPage->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(goSettingsPage);


        formLayout->setWidget(0, QFormLayout::LabelRole, buttonPanel);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        choosePage = new QWidget();
        choosePage->setObjectName("choosePage");
        gridLayout_8 = new QGridLayout(choosePage);
        gridLayout_8->setObjectName("gridLayout_8");
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        chooseButton_8 = new QPushButton(choosePage);
        chooseButton_8->setObjectName("chooseButton_8");

        horizontalLayout_29->addWidget(chooseButton_8);

        addButton_8 = new QPushButton(choosePage);
        addButton_8->setObjectName("addButton_8");

        horizontalLayout_29->addWidget(addButton_8);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_15);

        clearButton_8 = new QPushButton(choosePage);
        clearButton_8->setObjectName("clearButton_8");

        horizontalLayout_29->addWidget(clearButton_8);


        verticalLayout_10->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName("horizontalLayout_30");
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName("horizontalLayout_31");
        label_16 = new QLabel(choosePage);
        label_16->setObjectName("label_16");

        horizontalLayout_31->addWidget(label_16);

        rowsSpinBox_8 = new QSpinBox(choosePage);
        rowsSpinBox_8->setObjectName("rowsSpinBox_8");
        rowsSpinBox_8->setMinimum(0);
        rowsSpinBox_8->setMaximum(10);
        rowsSpinBox_8->setValue(0);

        horizontalLayout_31->addWidget(rowsSpinBox_8);


        horizontalLayout_30->addLayout(horizontalLayout_31);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName("horizontalLayout_32");
        label_17 = new QLabel(choosePage);
        label_17->setObjectName("label_17");

        horizontalLayout_32->addWidget(label_17);

        colsSpinBox_8 = new QSpinBox(choosePage);
        colsSpinBox_8->setObjectName("colsSpinBox_8");
        colsSpinBox_8->setMaximum(20);

        horizontalLayout_32->addWidget(colsSpinBox_8);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_16);


        horizontalLayout_30->addLayout(horizontalLayout_32);


        verticalLayout_10->addLayout(horizontalLayout_30);


        gridLayout_8->addLayout(verticalLayout_10, 0, 0, 1, 1);

        viewJsonCheckBox_8 = new QCheckBox(choosePage);
        viewJsonCheckBox_8->setObjectName("viewJsonCheckBox_8");

        gridLayout_8->addWidget(viewJsonCheckBox_8, 0, 1, 1, 1);

        userTable_8 = new QTableWidget(choosePage);
        userTable_8->setObjectName("userTable_8");
        userTable_8->setEditTriggers(QAbstractItemView::NoEditTriggers);
        userTable_8->setSelectionMode(QAbstractItemView::SingleSelection);
        userTable_8->setRowCount(0);
        userTable_8->setColumnCount(0);
        userTable_8->horizontalHeader()->setVisible(false);
        userTable_8->horizontalHeader()->setCascadingSectionResizes(true);
        userTable_8->horizontalHeader()->setMinimumSectionSize(130);
        userTable_8->horizontalHeader()->setDefaultSectionSize(130);
        userTable_8->verticalHeader()->setVisible(false);
        userTable_8->verticalHeader()->setCascadingSectionResizes(true);
        userTable_8->verticalHeader()->setMinimumSectionSize(150);
        userTable_8->verticalHeader()->setDefaultSectionSize(150);

        gridLayout_8->addWidget(userTable_8, 1, 0, 1, 1);

        jsonViewer_8 = new QTextBrowser(choosePage);
        jsonViewer_8->setObjectName("jsonViewer_8");
        sizePolicy1.setHeightForWidth(jsonViewer_8->sizePolicy().hasHeightForWidth());
        jsonViewer_8->setSizePolicy(sizePolicy1);
        jsonViewer_8->setMinimumSize(QSize(30, 0));
        jsonViewer_8->setMaximumSize(QSize(500, 16777215));

        gridLayout_8->addWidget(jsonViewer_8, 1, 1, 1, 1);

        stackedWidget->addWidget(choosePage);
        overviewPage = new QWidget();
        overviewPage->setObjectName("overviewPage");
        stackedWidget->addWidget(overviewPage);
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
        saveDataCB = new QCheckBox(settingsPage);
        saveDataCB->setObjectName("saveDataCB");

        horizontalLayout->addWidget(saveDataCB);

        removeData = new QPushButton(settingsPage);
        removeData->setObjectName("removeData");

        horizontalLayout->addWidget(removeData);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);

        searcherCB = new QCheckBox(settingsPage);
        searcherCB->setObjectName("searcherCB");

        verticalLayout_5->addWidget(searcherCB);

        verticalSpacer_3 = new QSpacerItem(20, 338, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 3, 2);

        label_18 = new QLabel(settingsPage);
        label_18->setObjectName("label_18");

        gridLayout->addWidget(label_18, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        stackedWidget->addWidget(settingsPage);

        formLayout->setWidget(0, QFormLayout::FieldRole, stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Osu! Stats", nullptr));
        goChoosePage->setText(QCoreApplication::translate("MainWindow", "Choose a player...", nullptr));
        chooseUsername->setText(QString());
        chooseAvatar->setText(QString());
        goOverviewButton->setText(QCoreApplication::translate("MainWindow", "Overview", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Recent plays", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Visualizer", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Top", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Duel", nullptr));
        goSettingsPage->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        chooseButton_8->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        addButton_8->setText(QCoreApplication::translate("MainWindow", "Add new player", nullptr));
        clearButton_8->setText(QCoreApplication::translate("MainWindow", "Clear player", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Rows:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Columns:", nullptr));
        viewJsonCheckBox_8->setText(QCoreApplication::translate("MainWindow", "View Json", nullptr));
        label_19->setText(QString());
        saveDataCB->setText(QCoreApplication::translate("MainWindow", "Save application data", nullptr));
        removeData->setText(QCoreApplication::translate("MainWindow", "Remove data folder", nullptr));
        searcherCB->setText(QCoreApplication::translate("MainWindow", "Use player search", nullptr));
        label_18->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
