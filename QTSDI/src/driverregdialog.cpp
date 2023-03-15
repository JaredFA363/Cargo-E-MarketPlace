#include "driverregdialog.h"
#include "ui_driverregdialog.h"

DriverRegDialog::DriverRegDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DriverRegDialog)
{
    ui->setupUi(this);
}

DriverRegDialog::~DriverRegDialog()
{
    delete ui;
}

void DriverRegDialog::on_Confirm_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/jared/SDI_group_B6/db.db");
    db.open();

    if (!db.open())
    {
        qDebug()<<"problem opening database";
    }

    QSqlQuery qry;

    QString query = "CREATE TABLE IF NOT EXISTS drivers (username VARCHAR(30) UNIQUE PRIMARY KEY, firstname VARCHAR(30), surname VARCHAR(30), password VARCHAR(30), address VARCHAR(100), email VARCHAR(30), mobile VARCHAR(14), ninum VARCHAR(10), driverid VARCHAR(15))";
    qry.prepare(query);
    qry.exec();
    if( !qry.exec() )
    {
        qDebug() << qry.lastError();
    }
    else
    {
        qry.prepare("INSERT INTO drivers(username, firstname, surname, password, address, email, mobile, ninum, driverid)"
                    "VALUES(?,?,?,?,?,?,?,?,?)");

        QString in_firstname=ui->firstname->text();
        QString in_surname=ui->surname->text();
        QString in_username=ui->username->text();
        QString in_email=ui->email->text();
        QString in_password=ui->password->text();
        QString in_mobile=ui->Mobilenumber->text();
        QString in_address = ui->address->toPlainText();
        QString in_ninum=ui->ninumber->text();
        QString in_driverid=ui->drivinglicense->text();

        try{
            qry.addBindValue(in_username);
            qry.addBindValue(in_firstname);
            qry.addBindValue(in_surname);
            qry.addBindValue(in_password);
            qry.addBindValue(in_address);
            qry.addBindValue(in_email);
            qry.addBindValue(in_mobile);
            qry.addBindValue(in_ninum);
            qry.addBindValue(in_driverid);
            qry.exec();
        }catch(QSqlError e){
            throw new QSqlError;
        }

        hide();
        LoginDialog *loginDialog = new LoginDialog(this);
        loginDialog->show();
    }
    db.close();
}

void DriverRegDialog::on_ToLogin_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}
