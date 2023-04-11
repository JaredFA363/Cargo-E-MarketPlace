#include "updatedatabasethread.h"

UpdateDatabaseThread::UpdateDatabaseThread()
{

}

/*
 *
 * \brief Update Database Thread
 *
 * \details Opens Connection.
 *          Updates the Database Value
 *          Closes the databse.
 *
*/

void UpdateDatabaseThread::run()
{
    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QSqlQuery query;
    try{
        query.prepare("UPDATE orders SET orderstatus = '"+updated_status+"'  WHERE orderid = "+orderid+"");
        query.exec();
    }
    catch(QSqlError e){
        throw new QSqlError;
    }
    dbconnection->discConn();
}
