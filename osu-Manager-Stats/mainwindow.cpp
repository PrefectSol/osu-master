#include <QInputDialog>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isCorrectUsername(QString username)
{
    // osu check...
    return rand() % 2;
}

void MainWindow::on_addButton_clicked()
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
    QString username = QInputDialog::getText(nullptr, messageTitle, "Enter a nickname:", QLineEdit::Normal, "username", &isOk);
    if (!isOk)
    {
        return;
    }

    if (!isCorrectUsername(username))
    {
        QMessageBox::warning(nullptr, messageTitle, "Couldn't find a player");
        return;
    }

    const size_t pixmapSizes = 100;

    QWidget *player = new QWidget();
    QLabel *usernameLabel = new QLabel(username);
    QPixmap pixmap(":/Images/icon.png");
    QLabel *imageLabel = new QLabel();
    imageLabel->setPixmap(pixmap.scaled(pixmapSizes, pixmapSizes, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

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

void MainWindow::on_clearButton_clicked()
{
    QTableWidget *table = ui->userTable;
    QModelIndex currentIndex = table->currentIndex();

    if (currentIndex == QModelIndex())
    {
        QMessageBox::warning(nullptr, "Remove player...", "The player is not selected");
    }
    else
    {
        table->setCellWidget(currentIndex.row(), currentIndex.column(), nullptr);
    }
}

void MainWindow::on_chooseButton_clicked()
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
            QLabel *usernameLabel = qobject_cast<QLabel*>(layout->itemAt(0)->widget());
            QLabel *imageLabel = qobject_cast<QLabel*>(layout->itemAt(1)->widget());

            ui->chooseUsername->setText(usernameLabel->text());
            ui->chooseUsername->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

            ui->chooseAvatar->setPixmap(imageLabel->pixmap());
            ui->chooseAvatar->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

            return;
        }
    }

    QMessageBox::warning(nullptr, "Choose a player...", "Selected error");
}


void MainWindow::on_spinBox_valueChanged(int)
{

}


void MainWindow::on_spinBox_2_valueChanged(int)
{

}


void MainWindow::on_spinBox_textChanged(const QString&)
{

}


void MainWindow::on_spinBox_2_textChanged(const QString&)
{

}

