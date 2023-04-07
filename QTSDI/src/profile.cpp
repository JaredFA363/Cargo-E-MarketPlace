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

void profile::change_details()
{
    QString new_username = "'"+retrieved_username+"'";
    QString new_accountType = "'"+retrieved_accountType+"'";

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    QSqlQuery query;

    if(retrieved_accountType == "Transportation Company")
    {
        QString username = ui->profileEdit0->text();
        QString password = ui->profileEdit1->text();
        QString address = ui->profileEdit2->text();
        QString company_name = ui->profileEdit3->text();

        try{
            query.prepare("UPDATE transportcompany SET username = :in_username, password = :in_pass, address = :in_address, company_name = :in_company_name WHERE username = :old_username");
            query.bindValue(":in_username",username);
            query.bindValue(":in_pass",password);
            query.bindValue(":in_address",address);
            query.bindValue(":in_company_name",company_name);
            query.bindValue(":old_username",retrieved_username);
            query.exec();
            retrieved_username = username;
        }catch(QSqlError e){
            throw new QSqlError;
        }
    }
    else if(retrieved_accountType == "Cargo Company")
    {
        QString username = ui->profileEdit0->text();
        QString password = ui->profileEdit1->text();
        QString address = ui->profileEdit2->text();
        QString firstname = ui->profileEdit3->text();
        QString surname = ui->profileEdit4->text();
        QString email = ui->profileEdit5->text();
        QString mobile = ui->profileEdit6->text();

        try{
            query.prepare("UPDATE cargoowner SET username = :in_username, password = :in_pass, address = :in_address, firstname = :in_firstname, surname = :in_surname, email = :in_email, mobile = :in_mobile WHERE username = :old_username");
            query.bindValue(":in_username",username);
            query.bindValue(":in_pass",password);
            query.bindValue(":in_address",address);
            query.bindValue(":in_firstname",firstname);
            query.bindValue(":in_surname",surname);
            query.bindValue(":in_email",email);
            query.bindValue(":in_mobile",mobile);
            query.bindValue(":old_username",retrieved_username);
            query.exec();
            retrieved_username = username;
        }catch(QSqlError e){
            throw new QSqlError;
        }
    }
    else if(retrieved_accountType == "Driver")
    {
        QString username = ui->profileEdit0->text();
        QString password = ui->profileEdit1->text();
        QString address = ui->profileEdit2->text();
        QString firstname = ui->profileEdit3->text();
        QString surname = ui->profileEdit4->text();
        QString email = ui->profileEdit5->text();
        QString mobile = ui->profileEdit6->text();
        QString ninum = ui->profileEdit7->text();
        QString driverid = ui->profileEdit8->text();

        try{
            query.prepare("UPDATE drivers SET username = :in_username, password = :in_pass, address = :in_address, firstname = :in_firstname, surname = :in_surname, email = :in_email, mobile = :in_mobile, ninum = :in_ninum, driverid = :in_driverid WHERE username = :old_username");
            query.bindValue(":in_username",username);
            query.bindValue(":in_pass",password);
            query.bindValue(":in_address",address);
            query.bindValue(":in_firstname",firstname);
            query.bindValue(":in_surname",surname);
            query.bindValue(":in_email",email);
            query.bindValue(":in_mobile",mobile);
            query.bindValue(":in_ninum",ninum);
            query.bindValue(":in_driverid",driverid);
            query.bindValue(":old_username",retrieved_username);
            query.exec();
            qDebug() << retrieved_username;
            retrieved_username = username;
            qDebug() << retrieved_username;
        }catch(QSqlError e){
            throw new QSqlError;
        }
    }
    dbconnection->discConn();
}

void profile::on_profile_save_clicked()
{
    change_details();
}
