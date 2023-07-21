#include "datahandler.h"
#include "settings.hpp"
#include "ui_mainwindow.h"

DataHandler::DataHandler(const QString &folderPath, Ui::MainWindow *ui)
    : m_folderPath(folderPath), m_filePath(folderPath + m_settings::saveFile),
      m_ui(ui) {}

void DataHandler::loadData()
{
    QFile file(m_filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    QDataStream in(&file);

    bool isSaveData;
    in >> isSaveData;

    if (!isSaveData)
    {
        file.close();

        return;
    }

    m_ui->saveDataCheckBox->setChecked(isSaveData);

    in >> settings::isViewJson;
    m_ui->viewJsonCheckBox->setChecked(settings::isViewJson);

    if (!m_ui->viewJsonCheckBox->isChecked())
    {
        m_ui->jsonViewer->hide();
    }

    in >> settings::isSearcher;
    m_ui->useSearchCheckBox->setChecked(settings::isSearcher);

    QString folderPath;
    in >> folderPath;
    m_ui->songsFolderPath->setText(folderPath);

    int rowCount, columnCount;
    in >> rowCount;
    in >> columnCount;

    QTableWidget *userTable = m_ui->userTable;
    userTable->setRowCount(rowCount);
    userTable->setColumnCount(columnCount);

    m_ui->rowsSpinBox->setValue(rowCount);
    m_ui->colsSpinBox->setValue(columnCount);

    QString user, json;
    QPixmap image;
    int row, column;

    in >> user;

    const QString endPoint = m_settings::endPoint;
    const int pixmapSize = m_settings::pixmapSize;

    while (user != m_settings::endPoint)
    {
        in >> image;
        in >> json;
        in >> row;
        in >> column;

        m_users.insert(user, json);

        QLabel *usernameLabel = new QLabel();
        usernameLabel->setText(user);

        QLabel *imageLabel = new QLabel();
        imageLabel->setPixmap(image.scaled(pixmapSize, pixmapSize, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

        QWidget *player = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(player);
        layout->addWidget(usernameLabel, 0, Qt::AlignHCenter | Qt::AlignTop);
        layout->addWidget(imageLabel, 0, Qt::AlignHCenter | Qt::AlignVCenter);

        userTable->setCellWidget(row, column, player);

        in >> user;
    }

    QString chooseUsername;
    QPixmap chooseAvatar;

    in >> chooseUsername;
    in >> chooseAvatar;

    m_isChooseUsername = !chooseUsername.isEmpty();

    QLabel *uiUsername = m_ui->chooseUsername;
    QLabel *uiImage = m_ui->chooseImage;

    uiUsername->setText(chooseUsername);
    uiUsername->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    uiImage->setPixmap(chooseAvatar);
    uiImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    file.close();
}

void DataHandler::saveData()
{
    QDir().mkdir(m_folderPath);

    QFile file(m_filePath);
    file.open(QIODevice::WriteOnly);

    QDataStream out(&file);

    const bool isSaveData = m_ui->saveDataCheckBox->isChecked();
    out << isSaveData;

    if (!isSaveData)
    {
        file.close();

        return;
    }

    out << m_ui->viewJsonCheckBox->isChecked();
    out << m_ui->useSearchCheckBox->isChecked();

    out << m_ui->songsFolderPath->document()->toPlainText();

    const QTableWidget *table = m_ui->userTable;

    const int rows = table->rowCount();
    out << rows;

    const int columns = table->columnCount();
    out << columns;

    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            QWidget *widget = table->cellWidget(row, column);
            if (widget)
            {
                QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(widget->layout());
                if (layout)
                {
                    const QLabel *usernameLabel = qobject_cast<QLabel*>(layout->itemAt(0)->widget());
                    const QLabel *imageLabel = qobject_cast<QLabel*>(layout->itemAt(1)->widget());
                    const QString username = usernameLabel->text();

                    out << username;
                    out << imageLabel->pixmap();
                    out << m_users.value(username);
                    out << row;
                    out << column;
                }
            }
        }
    }

    out << m_settings::endPoint;
    out << m_ui->chooseUsername->text();
    out << m_ui->chooseImage->pixmap();

    file.close();
}

void DataHandler::deleteData()
{
    QDir folderDir(m_folderPath);

    if (folderDir.exists())
    {
        folderDir.removeRecursively();
    }
}

void DataHandler::getIsChooseUsername(bool *isChooseUsername)
{
    *isChooseUsername = m_isChooseUsername;
}

void DataHandler::usersRemove(const QString &key)
{
    m_users.remove(key);
}

void DataHandler::usersInsert(const QString &key, const QString &value)
{
    m_users.insert(key, value);
}

QString DataHandler::getUsersValue(const QString &key)
{
    return m_users.value(key);
}

