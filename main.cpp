#include "MainScreen.h"
#include "DatabaseScreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScreen w;
    DatabaseScreen o;
    w.show();
    return a.exec();
}


