#include "updatedatabasethread.h"

UpdateDatabaseThread::UpdateDatabaseThread()
{

}

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
