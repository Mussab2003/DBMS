#ifndef CREATEDATABASE_H
#define CREATEDATABASE_H


#include <QDialog>
#include "Database.h"
#include <QMessageBox>

namespace Ui {
class CreateDatabase;
}

class CreateDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDatabase(QWidget *parent = nullptr);
    ~CreateDatabase();

signals:
    void enteredDatabaseName(const QString& name, const QString& databaseName);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CreateDatabase *ui;
    //QMessageBox *errorBox;
};

#endif // CREATEDATABASE_H
