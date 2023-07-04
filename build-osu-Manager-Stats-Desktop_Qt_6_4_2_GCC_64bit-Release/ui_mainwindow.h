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
    QPushButton *pushButton;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *chooseUsername;
    QLabel *chooseAvatar;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_13;
    QPushButton *pushButton_12;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_5;
    QWidget *viewer;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *chooseButton;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearButton;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *rowsSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *colsSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *userTable;
    QTextBrowser *jsonViewer;
    QCheckBox *viewJsonCheckBox;

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
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(buttonPanel);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton);

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

        pushButton_6 = new QPushButton(buttonPanel);
        pushButton_6->setObjectName("pushButton_6");
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_6);

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

        pushButton_12 = new QPushButton(buttonPanel);
        pushButton_12->setObjectName("pushButton_12");
        sizePolicy1.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_12);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_5 = new QPushButton(buttonPanel);
        pushButton_5->setObjectName("pushButton_5");
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_5);


        formLayout->setWidget(0, QFormLayout::LabelRole, buttonPanel);

        viewer = new QWidget(centralwidget);
        viewer->setObjectName("viewer");
        sizePolicy.setHeightForWidth(viewer->sizePolicy().hasHeightForWidth());
        viewer->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(viewer);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        chooseButton = new QPushButton(viewer);
        chooseButton->setObjectName("chooseButton");

        horizontalLayout->addWidget(chooseButton);

        addButton = new QPushButton(viewer);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearButton = new QPushButton(viewer);
        clearButton->setObjectName("clearButton");

        horizontalLayout->addWidget(clearButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(viewer);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        rowsSpinBox = new QSpinBox(viewer);
        rowsSpinBox->setObjectName("rowsSpinBox");
        rowsSpinBox->setMinimum(0);
        rowsSpinBox->setMaximum(10);
        rowsSpinBox->setValue(0);

        horizontalLayout_2->addWidget(rowsSpinBox);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(viewer);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        colsSpinBox = new QSpinBox(viewer);
        colsSpinBox->setObjectName("colsSpinBox");
        colsSpinBox->setMaximum(20);

        horizontalLayout_3->addWidget(colsSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        userTable = new QTableWidget(viewer);
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

        gridLayout->addWidget(userTable, 1, 0, 1, 1);

        jsonViewer = new QTextBrowser(viewer);
        jsonViewer->setObjectName("jsonViewer");
        sizePolicy1.setHeightForWidth(jsonViewer->sizePolicy().hasHeightForWidth());
        jsonViewer->setSizePolicy(sizePolicy1);
        jsonViewer->setMinimumSize(QSize(30, 0));
        jsonViewer->setMaximumSize(QSize(500, 16777215));

        gridLayout->addWidget(jsonViewer, 1, 1, 1, 1);

        viewJsonCheckBox = new QCheckBox(viewer);
        viewJsonCheckBox->setObjectName("viewJsonCheckBox");

        gridLayout->addWidget(viewJsonCheckBox, 0, 1, 1, 1, Qt::AlignRight|Qt::AlignBottom);


        formLayout->setWidget(0, QFormLayout::FieldRole, viewer);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Osu! Stats", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Choose a player...", nullptr));
        chooseUsername->setText(QString());
        chooseAvatar->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        chooseButton->setText(QCoreApplication::translate("MainWindow", "Choose a player", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add new player", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear player", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Rows:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Columns:", nullptr));
        viewJsonCheckBox->setText(QCoreApplication::translate("MainWindow", "View Json", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
