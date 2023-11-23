#include "DatabaseScreen.h"
#include "qlabel.h"
#include "ui_DatabaseScreen.h"

DatabaseScreen::DatabaseScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DatabaseScreen)
{
    ui->setupUi(this);
    count = 0;


    layout = new QGridLayout(ui->frame);
    layout->setAlignment(Qt::AlignTop);

    x = 0;
    y = 0;
}

DatabaseScreen::~DatabaseScreen()
{
    delete ui;
}

void DatabaseScreen::display()
{
    qDebug() << "Hello";
    //qDebug() << databaseName;
    Database obj(QString(databaseName).toStdString());
    obj.pull();

    auto *temp = obj.table_list.head;
    int i=0;

    while(temp != NULL)
    {
        tableName.append(QString::fromStdString(temp->data->label));
        i++;
        //qDebug() << temp->data->label;
        temp->data->display();
        temp = temp->next;
    }

    tableButton = new QPushButton[tableName.count()];

    for(int i=count; i<tableName.count(); i++)
    {
        layout->setVerticalSpacing(10);
        tableButton[i].setParent(ui->frame);
        tableButton[i].setText(tableName[i]);
        layout->addWidget(&tableButton[i], x++, y);
    }
    count++;

    temp = obj.table_list.head;
    i=0;

    while(temp != NULL)
    {
        int count = 0;
        connect(&tableButton[i], &QPushButton::clicked, [i, &count, this, &temp](){
            count = i;
            displayTable(temp->data);
        });
        i++;
        temp = temp->next;
    }

}

void DatabaseScreen::displayTable(Table *obj)
{
    DisplayTable *display = new DisplayTable(obj);
    display->show();
}



void DatabaseScreen::on_pushButton_clicked()
{
    QString text;
    text = ui->textEdit->toPlainText();
   // qDebug() << text;

    QStringList textLines = text.split("\n");

    //qDebug() << textLines[0];


    for(int i=0; i<textLines.size(); i++)
    {
        input.push_back(QString(textLines[i]).toStdString());
    }

    for(int i=0; i<input.size(); i++)
    {
        qDebug() << input[i];
    }

    std::pair<std::string, vector<pair<std::string, std::string>>> query;

    query.first = "Table1";
    query.second.push_back(std::pair<std::string, std::string>("int", "ID"));
    query.second.push_back(std::pair<std::string, std::string>("class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >", "Name"));
    query.second.push_back(std::pair<std::string, std::string>("char", "Grade"));

    Table *table = new Table(query);

    table->addRow(5, std::string("Row1"), 'A');
    table->addRow(6, std::string("Row2"), 'C');
    table->addRow(1, std::string("Row3"), 'D');
    table->addRow(4, std::string("Row4"), 'E');
    table->addRow(7, std::string("Row5"), 'F');

    createTable(table);
}

void DatabaseScreen::createTable(Table *obj)
{
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


