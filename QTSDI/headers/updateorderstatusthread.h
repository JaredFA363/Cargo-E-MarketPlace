#ifndef UPDATEORDERSTATUSTHREAD_H
#define UPDATEORDERSTATUSTHREAD_H
#include <QThread>
#include "userform.h"

class UpdateOrderStatusThread : public QThread
{
public:
    UpdateOrderStatusThread();
    QString updated_status;
    userform* userForm;

protected:
    void run() override;
};

#endif // UPDATEORDERSTATUSTHREAD_H
