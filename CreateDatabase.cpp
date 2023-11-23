#include "CreateDatabase.h"
#include "ui_CreateDatabase.h"
#include "ui_MainScreen.h"

CreateDatabase::CreateDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDatabase)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet(
        "QPushButton:hover {background-color: rgb(173,216,230);}"
        "QPushButton {background-color: blue;}"
    );
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setStyleSheet(
        "QPushButton:hover {background-color: rgb(255,127,127);}"
        "QPushButton {background-color: red"
    );

    //errorBox = new QMessageBox(nullptr);
}

CreateDatabase::~CreateDatabase()
{
    delete ui;
}

bool verify(QString name)
{
    QFile file("userData.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);

    QStringList data1;
    int i=0;

    while(!in.atEnd())
    {
        QString line = in.readLine();
        if(i%2==0)
        {
            data1.append(line);
        }
        i++;
    }
    file.close();

    for(int i=0; i<data1.size(); i++)
    {
        if(data1[i] == name)
        {
            return 1;
        }
    }

    return 0;
}



void CreateDatabase::on_buttonBox_accepted()
{
    if(!ui->input_databaseName->text().isEmpty() && !ui->input_databaseName->text().contains(' ') && !ui->input_userName->text().isEmpty() && !ui->input_userPassword->text().isEmpty())
    {
        if(verify(ui->input_databaseName->text()) == 0)
        {
            if(ui->input_userPassword->text() == ui->input_userPassword_2->text())
            {
                emit enteredDatabaseName(ui->input_databaseName->text().toLower(), ui->input_userName->text().toLower());
                Database obj(QString(ui->input_databaseName->text().toLower()).toStdString());
                obj.username = QString(ui->input_userName->text().toLower()).toStdString();
                obj.password = QString(ui->input_userPassword->text()).toStdString();
                qDebug() << obj.username;
                qDebug() << obj.password;
                obj.commit();
                close();
            }
            else
            {
                QLabel label;
                label.setText("Password should be same");
                label.move(30, 300);
                label.setStyleSheet("QLabel {color: white;}");
            }
        }
        else
        {
            QMessageBox *errorBox = new QMessageBox();
            errorBox->setIcon(QMessageBox::Critical);

            errorBox->setWindowTitle("Incorrect Name");
            errorBox->setText("Database Name cannot be an existing name");
            errorBox->exec();
            //delete errorBox;
        }
    }
    else
    {

        QMessageBox *errorBox = new QMessageBox();
        errorBox->setIcon(QMessageBox::Critical);

        errorBox->setWindowTitle("Incomplete Info");
        errorBox->setText("Database Name, Username and password cannot be empty");
        errorBox->setInformativeText("Please check your Database Name, username and password");
        errorBox->show();

        //delete errorBox;
    }
}




