#include "dbcon.h"

dbcon::dbcon()
{

}

bool dbcon::openConn()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/jared/SDI_group_B6/db.db");
    db.open();

    if (!db.open())
    {
        qDebug()<<"problem opening database";
        return false;
    }
    else
    {
        qDebug()<<"Connected .. ";
        return true;
    }
}

void dbcon::discConn()
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
    qDebug()<<"Connection removed";
}



