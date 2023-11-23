#ifndef DATABASELOGIN_H
#define DATABASELOGIN_H
#include <QFile>
#include <QDialog>
#include <QMessageBox>
#include "DatabaseScreen.h"

namespace Ui {
class DatabaseLogIn;
}

class DatabaseLogIn : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseLogIn(QWidget *parent = nullptr);
    ~DatabaseLogIn();
    void setText(QString text);
    void verify();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DatabaseLogIn *ui;
    QMessageBox errorBox1;
    QMessageBox errorBox2;
    //DatabaseScreen *obj;

};

#endif // DATABASELOGIN_H
