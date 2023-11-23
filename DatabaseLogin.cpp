#include "DatabaseLogin.h"
#include "ui_DatabaseLogin.h"
#include <iostream>

DatabaseLogIn::DatabaseLogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseLogIn)
{
    ui->setupUi(this);



}

DatabaseLogIn::~DatabaseLogIn()
{
    delete ui;
}

void DatabaseLogIn::setText(QString text)
{
    ui->label_databaseName->setText(text);
}

void DatabaseLogIn::verify()
{



}




void DatabaseLogIn::on_buttonBox_accepted()
{
    QString databaseName;
    std::string text = QString(ui->label_databaseName->text()).toStdString();
    int pos = text.find('\n');

    std::string text2 = text.substr(0, pos);
//    qDebug() << text;
//    qDebug() << text2;
    qDebug() << text2;
    databaseName = QString::fromStdString(text2);
    //qDebug() << "Database Name in login file " << databaseName;
    QFile file(databaseName + ".dat");
    QString userName;
    QString password;
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);

        in >> userName;
        in >> password;
        qDebug() << userName;
        qDebug() << password;
        file.close();
    }
    else
    {
        qDebug() << "File not found";
    }

    if(!ui->lineEdit_Userid->text().isEmpty() && !ui->lineEdit_databasePass->text().isEmpty())
    {
        if(userName == ui->lineEdit_Userid->text() && password == ui->lineEdit_databasePass->text())
        {
            DatabaseScreen *obj = new DatabaseScreen;
            obj->databaseName = databaseName;
            close();
            obj->display();
            obj->show();
            qDebug() << "Access Granted";
        }
        else
        {
            qDebug() << "Incorrect";
        }
    }
    else
    {
        errorBox1.setIcon(QMessageBox::Information);
        errorBox1.setWindowTitle("Incomplete Info");
        errorBox1.setText("Username and Password cannot be empty");
        errorBox1.setInformativeText("Please check your Username and Password");
        errorBox1.exec();
    }
}

