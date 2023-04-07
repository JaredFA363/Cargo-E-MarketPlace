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
