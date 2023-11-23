#include "displaytable.h"
#include "ui_displaytable.h"

DisplayTable::DisplayTable(Table *obj, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayTable)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(obj->num_of_cols);
    ui->tableWidget->setRowCount(obj->num_of_rows);

    qDebug() << ui->tableWidget->columnCount();


    for(int i=0; i<obj->num_of_cols; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::fromStdString((*obj)[i].label));
        ui->tableWidget->setHorizontalHeaderItem(i, item);
    }

    for(int i=0; i<obj->num_of_rows; i++)
    {
        for(int j=0; j<obj->num_of_cols; j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(QString::fromStdString((*obj)[j][i].getValue()));
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

DisplayTable::~DisplayTable()
{
    delete ui;
}
