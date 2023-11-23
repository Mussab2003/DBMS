#ifndef DATABASESCREEN_H
#define DATABASESCREEN_H

#include <QMainWindow>
#include <vector>
#include <string>
#include "Table.h"
#include "Database.h"
#include <QPushButton>
#include <QGridLayout>
#include "displaytable.h"
#include <QHBoxLayout>

namespace Ui {
class DatabaseScreen;
}

class DatabaseScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit DatabaseScreen(QWidget *parent = nullptr);
    QString databaseName;
    void display();
    ~DatabaseScreen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DatabaseScreen *ui;
    std::vector<std::string> input;
    void createTable(Table *obj);
    QStringList tableName;
    QPushButton *tableButton;
    int count;
    void displayTable(Table *obj);
    QGridLayout *layout;
    int x, y;
};

#endif // DATABASESCREEN_H
