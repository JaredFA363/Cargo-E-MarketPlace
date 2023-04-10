#include "updateorderstatusthread.h"

UpdateOrderStatusThread::UpdateOrderStatusThread()
{

}


void UpdateOrderStatusThread::run()
{
     userForm->changeOrderStatus(updated_status);
}
