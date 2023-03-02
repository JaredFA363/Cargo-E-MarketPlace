#include "dbcon.h"

dbcon::dbcon()
{
    QSqlDatabase regdb;
    regdb = QSqlDatabase::addDatabase("QSQLITE");
    regdb.setDatabaseName("/home/jared/SDI_group_B6/reg.db");
    regdb.open();

    if (!regdb.open())
    {
        qDebug()<<"problem opening database";
    }

    QSqlQuery qry;
    QString query =  "CREATE TABLE IF NOT EXISTS transportcompany (username VARCHAR(30) UNIQUE PRIMARY KEY, company_name VARCHAR(30), password VARCHAR(30), address VARCHAR(100))";
    qry.prepare(query);
    qry.exec(query);
    if( !qry.exec(query) )
        qDebug() << qry.lastError();

    query = "CREATE TABLE IF NOT EXISTS cargoowner (username VARCHAR(30) UNIQUE PRIMARY KEY, firstname VARCHAR(30), surname VARCHAR(30), password VARCHAR(30), address VARCHAR(100), email VARCHAR(30), mobile VARCHAR(14))";
    qry.prepare(query);
    qry.exec(query);
    if( !qry.exec(query) )
        qDebug() << qry.lastError();

    query = "CREATE TABLE IF NOT EXISTS drivers (username VARCHAR(30) UNIQUE PRIMARY KEY, firstname VARCHAR(30), surname VARCHAR(30), password VARCHAR(30), address VARCHAR(100), email VARCHAR(30), mobile VARCHAR(14), ninum VARCHAR(10), driverid VARCHAR(15))";
    qry.prepare(query);
    qry.exec();
    if( !qry.exec() )
        qDebug() << qry.lastError();

    regdb.close();
}
