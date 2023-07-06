/********************************************************************************
** Form generated from reading UI file 'addplayerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLAYERWINDOW_H
#define UI_ADDPLAYERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addPlayerWindow
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *addPlayerWindow)
    {
        if (addPlayerWindow->objectName().isEmpty())
            addPlayerWindow->setObjectName("addPlayerWindow");
        addPlayerWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addPlayerWindow->sizePolicy().hasHeightForWidth());
        addPlayerWindow->setSizePolicy(sizePolicy);
        label = new QLabel(addPlayerWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 231, 22));
        textEdit = new QTextEdit(addPlayerWindow);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 60, 321, 31));
        textEdit->setAcceptDrops(true);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);
        textEdit->setTextInteractionFlags(Qt::TextEditorInteraction);
        widget = new QWidget(addPlayerWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 240, 361, 33));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        retranslateUi(addPlayerWindow);

        QMetaObject::connectSlotsByName(addPlayerWindow);
    } // setupUi

    void retranslateUi(QDialog *addPlayerWindow)
    {
        addPlayerWindow->setWindowTitle(QCoreApplication::translate("addPlayerWindow", "Add new player...", nullptr));
        label->setText(QCoreApplication::translate("addPlayerWindow", "Enter the player's username:", nullptr));
        textEdit->setPlaceholderText(QString());
        pushButton_2->setText(QCoreApplication::translate("addPlayerWindow", "Close", nullptr));
        pushButton->setText(QCoreApplication::translate("addPlayerWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addPlayerWindow: public Ui_addPlayerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLAYERWINDOW_H
