#ifndef DBCON_H
#define DBCON_H

#include <QApplication>
#include <QtSql>
#include <QtDebug>

class dbcon
{
public:
     dbcon();
     QSqlDatabase db;
     bool openConn();
     void discConn();
};

#endif // DBCON_H
