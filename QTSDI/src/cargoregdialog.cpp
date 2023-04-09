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

/*
 *
 * \brief Cargo Owner Registration Function
 *
 * \details The Cargo owner should be able to add there details to the database.
 *          The function establishes the connection eith the database.
 *          Collects the inputs from the user and then stores it in the database.
*/

void CargoRegDialog::on_Confirm_clicked()
{
    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    dbconnection->createTables();
    QSqlQuery qry;

    qry.prepare("INSERT INTO cargoowner(username, firstname, surname, password, address, email, mobile)"
    "VALUES (?,?,?,?,?,?,?)");
    QString in_firstname=ui->firstname->text();
    QString in_surname=ui->surname->text();
    QString in_username=ui->username->text();
    QString in_email=ui->email->text();
    QString in_password=ui->password->text();
    QString in_mobile=ui->mobilenumber->text();
    QString in_address = ui->address->toPlainText();

    TransportRegDialog *transReg = new TransportRegDialog(this);
    QString hashed_password = transReg->hash_Password(in_password);

    try{
        qry.addBindValue(in_username);
        qry.addBindValue(in_firstname);
        qry.addBindValue(in_surname);
        qry.addBindValue(hashed_password);
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

    dbconnection->discConn();
}

void CargoRegDialog::on_ToLogin_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}
