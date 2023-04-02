#include "transportregdialog.h"
#include "ui_transportregdialog.h"
#include <iostream>


TransportRegDialog::TransportRegDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransportRegDialog)
{
    ui->setupUi(this);
}

TransportRegDialog::~TransportRegDialog()
{
    delete ui;
}

void TransportRegDialog::on_confirm_clicked()
{

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    dbconnection->createTables();

    QSqlQuery qry;
    qry.prepare("INSERT INTO transportcompany(username, company_name, password, address)"
                "VALUES (?,?,?,?)");
    QString companyname = ui->company_name->text();
    QString input_address = ui->address->toPlainText();
    QString input_password = ui->password->text();
    QString input_username = ui->username->text();
    try{
        qry.addBindValue(input_username);
        qry.addBindValue(companyname);
        qry.addBindValue(input_password);
        qry.addBindValue(input_address);
        qry.exec();
    }catch(QSqlError e){
        throw new QSqlError;
    }

    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();

    dbconnection->discConn();
}

void TransportRegDialog::on_ToLogin_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}
