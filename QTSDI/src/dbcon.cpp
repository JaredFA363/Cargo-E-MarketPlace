#include "dbcon.h"

dbcon::dbcon()
{

}

/*
 *
 * \brief Open Connection Function
 *
 * \details This function opens the connection to the database for other functions.
 *          This is reused in the application
 *
 * \return True or False
*/

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

/*
 *
 * \brief Disconnect Connection Function
 *
 * \details This function disconnects the database connection.
 *          This is resused multiple times in the program.
*/

void dbcon::discConn()
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
    qDebug()<<"Connection removed";
}

/*
 *
 * \brief Create Tables Function
 *
 * \details This function creates the base tables in the database.
 *          For if the program is run on different devices.
*/

void dbcon::createTables()
{
    try{
        QSqlQuery qry;
        QString query = "CREATE TABLE IF NOT EXISTS drivers (username VARCHAR(30) UNIQUE NOT NULL PRIMARY KEY, firstname VARCHAR(30) NOT NULL, surname VARCHAR(30) NOT NULL, password VARCHAR(30) NOT NULL, address VARCHAR(100) NOT NULL, email VARCHAR(30) NOT NULL, mobile VARCHAR(11) NOT NULL, ninum VARCHAR(10) NOT NULL, driverid VARCHAR(15) NOT NULL)";
        qry.prepare(query);
        qry.exec();
        if( !qry.exec() )
        {
            qDebug() << qry.lastError();
        }
        QString query1 =  "CREATE TABLE IF NOT EXISTS transportcompany (username VARCHAR(30) UNIQUE NOT NULL PRIMARY KEY, company_name VARCHAR(30) NOT NULL, password VARCHAR(30) NOT NULL, address VARCHAR(100) NOT NULL)";
        qry.prepare(query1);
        qry.exec();
        if( !qry.exec() )
        {
            qDebug() << qry.lastError();
        }
        QString query2 = "CREATE TABLE IF NOT EXISTS cargoowner (username VARCHAR(30) UNIQUE NOT NULL PRIMARY KEY, firstname VARCHAR(30) NOT NULL, surname VARCHAR(30) NOT NULL, password VARCHAR(30) NOT NULL, address VARCHAR(100) NOT NULL, email VARCHAR(30) NOT NULL, mobile VARCHAR(14) NOT NULL)";
        qry.prepare(query2);
        qry.exec();
        if( !qry.exec() )
        {
            qDebug() << qry.lastError();
        }
        QString query3 = "CREATE TABLE IF NOT EXISTS orders (orderid INTEGER UNIQUE NOT NULL PRIMARY KEY AUTOINCREMENT DEFAULT 1, source VARCHAR(30) NOT NULL, destination VARCHAR(30) NOT NULL, weight VARCHAR(30) NOT NULL, dimensions VARCHAR(20) NOT NULL, condition VARCHAR(30) NOT NULL, transportcompany VARCHAR(30) NOT NULL, orderstatus VARCHAR(20) NOT NULL)";
        qry.prepare(query3);
        qry.exec();
        if( !qry.exec() )
        {
            qDebug() << qry.lastError();
        }
    }
    catch(QSqlError e){
        throw new QSqlError;
    }
}


