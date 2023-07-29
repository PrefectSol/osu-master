/********************************************************************************
** Form generated from reading UI file 'playersearchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERSEARCHDIALOG_H
#define UI_PLAYERSEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PlayerSearchDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout;
    QPushButton *closeButton;
    QPushButton *addButton;

    void setupUi(QDialog *PlayerSearchDialog)
    {
        if (PlayerSearchDialog->objectName().isEmpty())
            PlayerSearchDialog->setObjectName("PlayerSearchDialog");
        PlayerSearchDialog->resize(252, 123);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlayerSearchDialog->sizePolicy().hasHeightForWidth());
        PlayerSearchDialog->setSizePolicy(sizePolicy);
        PlayerSearchDialog->setMinimumSize(QSize(252, 123));
        PlayerSearchDialog->setMaximumSize(QSize(252, 123));
        verticalLayout_2 = new QVBoxLayout(PlayerSearchDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(PlayerSearchDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        username = new QLineEdit(PlayerSearchDialog);
        username->setObjectName("username");
        username->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(username);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        closeButton = new QPushButton(PlayerSearchDialog);
        closeButton->setObjectName("closeButton");

        horizontalLayout->addWidget(closeButton);

        addButton = new QPushButton(PlayerSearchDialog);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(PlayerSearchDialog);

        QMetaObject::connectSlotsByName(PlayerSearchDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayerSearchDialog)
    {
        PlayerSearchDialog->setWindowTitle(QCoreApplication::translate("PlayerSearchDialog", "Add new player...", nullptr));
        label->setText(QCoreApplication::translate("PlayerSearchDialog", "Enter the player's username:", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("PlayerSearchDialog", "username", nullptr));
        closeButton->setText(QCoreApplication::translate("PlayerSearchDialog", "Cancel", nullptr));
        addButton->setText(QCoreApplication::translate("PlayerSearchDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerSearchDialog: public Ui_PlayerSearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERSEARCHDIALOG_H
