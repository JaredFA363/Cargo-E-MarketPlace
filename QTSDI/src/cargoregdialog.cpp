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
 * \brief Cargo Owner Registration Button
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

    if (check_inputs(in_username,in_firstname,in_surname,in_password,in_address,in_email,in_mobile) == "Message1")
    {
        QMessageBox::information(this,"Register","Empty Values");
    }
    else if(check_inputs(in_username,in_firstname,in_surname,in_password,in_address,in_email,in_mobile) == "Message2"){
        QMessageBox::information(this,"Register","Invalid Username");
    }
    else
    {
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
            QMessageBox::information(this,"Register","Incorrect Value");
        }

        hide();
        LoginDialog *loginDialog = new LoginDialog(this);
        loginDialog->show();
    }

    dbconnection->discConn();
}

void CargoRegDialog::on_ToLogin_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}

/*
 *
 * \brief Check Cargo Owner Registration Details
 *
 * \details Checks the inputs are correct
 *
 * \returns QString tell function what Message to display
*/

QString CargoRegDialog::check_inputs(QString in_username,QString in_firstname,QString in_surname,QString in_password,QString in_address,QString in_email,QString in_mobile)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM cargoowner WHERE username = '"+in_username+"'");
    query.exec();

    if (in_firstname== "" || in_surname== "" || in_address== "" || in_password== "" || in_username== "" || in_email== "" || in_mobile== "")
    {
        return "Message1";
    }
    else if(query.first() == true){
        return "Message2";
    }
    else
    {
        return "Message3";
    }
}
