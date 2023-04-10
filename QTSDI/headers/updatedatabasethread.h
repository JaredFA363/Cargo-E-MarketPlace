#ifndef UPDATEDATABASETHREAD_H
#define UPDATEDATABASETHREAD_H
#include <QThread>
#include <QSqlQuery>
#include "dbcon.h"
#include <QMessageBox>

class UpdateDatabaseThread : public QThread
{
public:
    UpdateDatabaseThread();
    QString orderid;
    QString updated_status;

protected:
    void run() override;
};

#endif // UPDATEDATABASETHREAD_H
