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

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QSqlQuery query;

    try{
        query.prepare("UPDATE orders SET orderstatus = 'Transportation Company Accepted'  WHERE orderid = "+orderid+"");
        query.exec();
        userform *Userform = new userform(retrieved_acc,retrieved_user,this);
        Userform->changeOrderStatus("Transportation Company Accepted");
    }
    catch(QSqlError e){
        throw new QSqlError;
        QMessageBox::information(this,"Order","No Such Order Available");
    }
    dbconnection->discConn();
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
