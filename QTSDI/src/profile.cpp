#include "profile.h"
#include "ui_profile.h"
#include "userform.h"
#include <iostream>
#include <QDebug>

profile::profile(QString acc, QString user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
    setVars(acc,user);
    getDetails();
}

profile::~profile()
{
    delete ui;
}

void profile::getDetails()
{

    QString username = retrieved_username;
    QString acc_type = retrieved_accountType;
    //QString username = user;

    QString username_profile = "'"+username+"'";

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QSqlQuery query;

    if(acc_type == "Transportation Company")
    {
        if(query.exec("SELECT username, password, address, company_name FROM transportcompany WHERE username ="+username_profile+""))
        {
            query.first();
            ui->profileEdit0->setText(query.value(0).toString());
            ui->profileEdit1->setText(query.value(1).toString());
            ui->profileEdit2->setText(query.value(2).toString());
            ui->profileEdit3->setText(query.value(3).toString());
        }
    }
    else if(acc_type == "Cargo Company")
    {
        if(query.exec("SELECT username, password, address, firstname, surname, email, mobile FROM cargoowner WHERE username ="+username_profile+""))
        {
            query.first();
            ui->profileEdit0->setText(query.value(0).toString());
            ui->profileEdit1->setText(query.value(1).toString());
            ui->profileEdit2->setText(query.value(2).toString());
            ui->profileEdit3->setText(query.value(3).toString());
            ui->profileEdit4->setText(query.value(4).toString());
            ui->profileEdit5->setText(query.value(5).toString());
            ui->profileEdit6->setText(query.value(6).toString());
        }
    }
    else if(acc_type == "Driver")
    {
        if(query.exec("SELECT username, password, address, firstname, surname, email, mobile, ninum, driverid FROM drivers WHERE username ="+username_profile+""))
        {
            query.first();
            ui->profileEdit0->setText(query.value(0).toString());
            ui->profileEdit1->setText(query.value(1).toString());
            ui->profileEdit2->setText(query.value(2).toString());
            ui->profileEdit3->setText(query.value(3).toString());
            ui->profileEdit4->setText(query.value(4).toString());
            ui->profileEdit5->setText(query.value(5).toString());
            ui->profileEdit6->setText(query.value(6).toString());
            ui->profileEdit7->setText(query.value(7).toString());
            ui->profileEdit8->setText(query.value(8).toString());
        }
    }
    dbconnection->discConn();
}

void profile::on_profile_back_clicked()
{
    hide();
    userform *userForm = new userform(retrieved_accountType, retrieved_username, this);
    userForm->show();
}

void profile::setVars(QString acc_type, QString username)
{
    retrieved_username = username;
    retrieved_accountType = acc_type;
    qDebug() << retrieved_accountType;
}
