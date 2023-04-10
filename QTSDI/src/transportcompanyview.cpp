#include "transportcompanyview.h"
#include "ui_transportcompanyview.h"

transportcompanyview::transportcompanyview(QString acc, QString user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transportcompanyview)
{
    ui->setupUi(this);
    retrieved_acc = acc;
    retrieved_user = user;
    QString companyname = "'"+retrieved_user+"'";

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QSqlQuery query;
    try{
        query.prepare("SELECT * FROM orders WHERE orderstatus = 'Order Placed' AND transportcompany = "+companyname+"");
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

transportcompanyview::~transportcompanyview()
{
    delete ui;
}


void transportcompanyview::on_accept_clicked()
{
    QString orderid = ui->orderId->text();
    QString updated_status = "Transportation Company Accepted";

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QSqlQuery qry;
    qry.prepare("SELECT source FROM orders WHERE orderid = "+orderid+"");
    qry.exec();
    dbconnection->discConn();
    if(qry.first() == false)
    {
        QMessageBox::information(this,"Order","INcorrect order id");
    }
    else if (qry.first() == true){
        QMessageBox::information(this,"Order","Forwarded to available drivers");

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

void transportcompanyview::on_profile_clicked()
{
    hide();
    profile *Profile = new profile(retrieved_acc, retrieved_user, this);
    Profile->show();
}

void transportcompanyview::on_logout_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}

void transportcompanyview::on_update_clicked()
{
    QString companyname = "'"+retrieved_user+"'";

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QSqlQuery qry;

    try{
        qry.prepare("SELECT * FROM orders WHERE orderstatus = 'Order Placed' AND transportcompany = "+companyname+"");
        qry.exec();
        QSqlQueryModel *modal = new QSqlQueryModel;
        modal->setQuery(qry);

        ui->tableView->setModel(modal);
    }
    catch(QSqlError e){
        throw new QSqlError;
    }
    dbconnection->discConn();
}
