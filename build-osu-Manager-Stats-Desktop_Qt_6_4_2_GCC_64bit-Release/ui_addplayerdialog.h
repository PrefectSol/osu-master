/********************************************************************************
** Form generated from reading UI file 'addplayerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLAYERDIALOG_H
#define UI_ADDPLAYERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addPlayerDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout;
    QPushButton *closeButton;
    QPushButton *addButton;

    void setupUi(QDialog *addPlayerDialog)
    {
        if (addPlayerDialog->objectName().isEmpty())
            addPlayerDialog->setObjectName("addPlayerDialog");
        addPlayerDialog->resize(252, 123);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addPlayerDialog->sizePolicy().hasHeightForWidth());
        addPlayerDialog->setSizePolicy(sizePolicy);
        addPlayerDialog->setMinimumSize(QSize(252, 123));
        addPlayerDialog->setMaximumSize(QSize(252, 123));
        verticalLayout_2 = new QVBoxLayout(addPlayerDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(addPlayerDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        username = new QLineEdit(addPlayerDialog);
        username->setObjectName("username");
        username->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(username);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        closeButton = new QPushButton(addPlayerDialog);
        closeButton->setObjectName("closeButton");

        horizontalLayout->addWidget(closeButton);

        addButton = new QPushButton(addPlayerDialog);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(addPlayerDialog);

        QMetaObject::connectSlotsByName(addPlayerDialog);
    } // setupUi

    void retranslateUi(QDialog *addPlayerDialog)
    {
        addPlayerDialog->setWindowTitle(QCoreApplication::translate("addPlayerDialog", "Add new player...", nullptr));
        label->setText(QCoreApplication::translate("addPlayerDialog", "Enter the player's username:", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("addPlayerDialog", "username", nullptr));
        closeButton->setText(QCoreApplication::translate("addPlayerDialog", "Cancel", nullptr));
        addButton->setText(QCoreApplication::translate("addPlayerDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addPlayerDialog: public Ui_addPlayerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLAYERDIALOG_H
