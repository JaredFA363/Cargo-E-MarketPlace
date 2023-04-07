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
        QString query = "CREATE TABLE IF NOT EXISTS drivers (username VARCHAR(30) UNIQUE PRIMARY KEY, firstname VARCHAR(30), surname VARCHAR(30), password VARCHAR(30), address VARCHAR(100), email VARCHAR(30), mobile VARCHAR(14), ninum VARCHAR(10), driverid VARCHAR(15))";
        qry.prepare(query);
        QString query1 =  "CREATE TABLE IF NOT EXISTS transportcompany (username VARCHAR(30) UNIQUE PRIMARY KEY, company_name VARCHAR(30), password VARCHAR(30), address VARCHAR(100))";
        qry.prepare(query1);
        QString query2 = "CREATE TABLE IF NOT EXISTS cargoowner (username VARCHAR(30) UNIQUE PRIMARY KEY, firstname VARCHAR(30), surname VARCHAR(30), password VARCHAR(30), address VARCHAR(100), email VARCHAR(30), mobile VARCHAR(14))";
        qry.prepare(query2);
        QString query3 = "CREATE TABLE IF NOT EXISTS orders (orderid INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT DEFAULT 1, source VARCHAR(30), destination VARCHAR(30), weight VARCHAR(30), condition VARCHAR(30), transportcompany VARCHAR(30), orderstatus VARCHAR(20))";
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


