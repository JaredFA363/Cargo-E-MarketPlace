#include "driverview.h"
#include "ui_driverview.h"

driverview::driverview(QString acc, QString user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::driverview)
{
    ui->setupUi(this);
    retrieved_acc = acc;
    retrieved_user = user;

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QSqlQuery query;
    try{
        query.prepare("SELECT * FROM orders WHERE orderstatus = 'Transportation Company Accepted'");
        query.exec();
        QSqlQueryModel *modal = new QSqlQueryModel;
        modal->setQuery(query);

        ui->tableView->setModel(modal);
    }
    catch(QSqlError e){
        throw new QSqlError;
    }

    dbconnection->discConn();
}

driverview::~driverview()
{
    delete ui;
}

void driverview::on_profile_clicked()
{
    hide();
    profile *Profile = new profile(retrieved_acc, retrieved_user, this);
    Profile->show();
}

void driverview::on_logout_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}

void driverview::on_accept_clicked()
{
    QString orderid = ui->orderid->text();
    order_id = orderid;
    QString updated_status = "Driver "+retrieved_user+" will complete the order";

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QSqlQuery qry;
    qry.prepare("SELECT orderid FROM orders WHERE orderid = "+orderid+"");
    qry.exec();
    dbconnection->discConn();
    if(qry.first() == false)
    {
        QMessageBox::information(this,"Order","Incorrect order id");
    }
    else if(qry.first() == true){
        UpdateDatabaseThread* updateDatabaseThread = new UpdateDatabaseThread();
        updateDatabaseThread->orderid = orderid;
        updateDatabaseThread->updated_status = updated_status;
        updateDatabaseThread->start();

        UpdateOrderStatusThread* updateOrderStatusThread = new UpdateOrderStatusThread();
        updateOrderStatusThread->updated_status = updated_status;
        updateOrderStatusThread->userForm = new userform(retrieved_acc, retrieved_user, this);
        updateOrderStatusThread->start();
    }
}

void driverview::on_reject_clicked()
{
    QString orderid = ui->orderid->text();
    rejectedOrders.append(orderid);
    qDebug() << rejectedOrders;

    QString rejectedOrdersStr = "'"+rejectedOrders.join("','")+"'";

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QSqlQuery query;

    try{
        query.prepare("SELECT * FROM orders WHERE orderid NOT IN ("+ rejectedOrdersStr+") AND orderstatus = 'Transportation Company Accepted'");
        query.exec();
        QSqlQueryModel *modal = new QSqlQueryModel;
        modal->setQuery(query);

        ui->tableView->setModel(modal);

    }
    catch(QSqlError e){
        throw new QSqlError;
        QMessageBox::information(this,"Order","No Such Order Available");
    }
    dbconnection->discConn();

}

void driverview::on_update_clicked()
{
    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QString orderid = order_id;

    QSqlQuery qry;
    try{
        qry.prepare("SELECT * FROM orders WHERE orderstatus = 'Transportation Company Accepted'");
        qry.exec();
        QSqlQueryModel *modal = new QSqlQueryModel;
        modal->setQuery(qry);

        ui->tableView->setModel(modal);

        QSqlQuery qry;
        qry.prepare("SELECT * FROM orders WHERE orderid = "+orderid+"");
        qry.exec();
        QSqlQueryModel *modal1 = new QSqlQueryModel;
        modal1->setQuery(qry);

        ui->tableView_2->setModel(modal1);

    }
    catch(QSqlError e){
        throw new QSqlError;
    }
    dbconnection->discConn();
}
