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
    QString companyname = ui->company_name->text();
    QString input_address = ui->address->toPlainText();
    QString input_password = ui->password->text();
    QString input_username = ui->username->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/jared/SDI_group_B6/db.db");
    db.open();

    if (!db.open())
    {
        qDebug()<<"problem opening database";
    }

    QSqlQuery qry;
    QString query =  "CREATE TABLE IF NOT EXISTS transportcompany (username VARCHAR(30) UNIQUE PRIMARY KEY, company_name VARCHAR(30), password VARCHAR(30), address VARCHAR(100))";
    qry.prepare(query);
    qry.exec(query);
    if( !qry.exec(query) )
        qDebug() << qry.lastError();
    else
    {
        QSqlQuery qry;
        qry.prepare("INSERT INTO transportcompany(username VARCHAR(30) UNIQUE PRIMARY KEY, company_name VARCHAR(30), password VARCHAR(30), address VARCHAR(100)"
                    "VALUES (?,?,?,?)");
        qry.addBindValue(input_username);
        qry.addBindValue(companyname);
        qry.addBindValue(input_password);
        qry.addBindValue(input_address);
        std::cout << "saved";
        //db.removeDatabase(QSqlDatabase::defaultConnection);
        hide();
        LoginDialog *loginDialog = new LoginDialog(this);
        loginDialog->show();
    }
    db.close();
}

void TransportRegDialog::on_ToLogin_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}
