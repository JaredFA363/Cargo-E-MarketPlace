#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QSqlDatabase regdb;
    //regdb = QSqlDatabase::addDatabase("QSQLITE");
    //regdb.setDatabaseName("/home/jared/SDI_group_B6/reg.db");
    //regdb.open();

    //if (!regdb.open())
    //{
        //qDebug()<<"problem opening database";
    //}

    MainWindow w;
    w.show();
    return a.exec();
}
