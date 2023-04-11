#include "updateorderstatusthread.h"

UpdateOrderStatusThread::UpdateOrderStatusThread()
{

}

/*
 *
 * \brief Update Order Status Thread
 *
 * \details Opens Connection.
 *          Updates the Order Status
 *          Closes the databse.
 *
*/
void UpdateOrderStatusThread::run()
{
     userForm->changeOrderStatus(updated_status);
}
