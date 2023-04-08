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
    QString updated_status = "Driver "+retrieved_user+" will complete the order";

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QSqlQuery query;

    try{
        query.prepare("UPDATE orders SET orderstatus = '"+updated_status+"'  WHERE orderid = "+orderid+"");
        query.exec();
        userform *Userform = new userform(retrieved_acc,retrieved_user,this);
        Userform->changeOrderStatus(updated_status);
    }
    catch(QSqlError e){
        throw new QSqlError;
        QMessageBox::information(this,"Order","No Such Order Available");
    }
    dbconnection->discConn();
}

void driverview::on_reject_clicked()
{
    QString orderid = ui->orderid->text();
    int int_orderid = orderid.toInt();
    qDebug() << int_orderid;
}
