#include "cargoregdialog.h"
#include "ui_cargoregdialog.h"

CargoRegDialog::CargoRegDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CargoRegDialog)
{
    ui->setupUi(this);
}

CargoRegDialog::~CargoRegDialog()
{
    delete ui;
}

void CargoRegDialog::on_Confirm_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/jared/SDI_group_B6/db.db");
    db.open();

    if (!db.open())
    {
        qDebug()<<"problem opening database";
    }
    else
    {
        QString query = "CREATE TABLE IF NOT EXISTS cargoowner (username VARCHAR(30) UNIQUE PRIMARY KEY, firstname VARCHAR(30), surname VARCHAR(30), password VARCHAR(30), address VARCHAR(100), email VARCHAR(30), mobile VARCHAR(14))";
        QSqlQuery qry;
        qry.prepare(query);
        qry.exec(query);
        if( !qry.exec(query) )
            qDebug() << qry.lastError();
        else
        {
            qry.prepare("INSERT INTO cargoowner(username, firstname, surname, password, address, email, mobile)"
            "VALUES (?,?,?,?,?,?,?)");
            QString in_firstname=ui->firstname->text();
            QString in_surname=ui->surname->text();
            QString in_username=ui->username->text();
            QString in_email=ui->email->text();
            QString in_password=ui->password->text();
            QString in_mobile=ui->mobilenumber->text();
            QString in_address = ui->address->toPlainText();
            try{
                qry.addBindValue(in_username);
                qry.addBindValue(in_firstname);
                qry.addBindValue(in_surname);
                qry.addBindValue(in_password);
                qry.addBindValue(in_address);
                qry.addBindValue(in_email);
                qry.addBindValue(in_mobile);
                qry.exec();
            }catch(QSqlError e){
                throw new QSqlError;
            }

            hide();
            LoginDialog *loginDialog = new LoginDialog(this);
            loginDialog->show();
        }
    }
    db.close();
}

void CargoRegDialog::on_ToLogin_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}
