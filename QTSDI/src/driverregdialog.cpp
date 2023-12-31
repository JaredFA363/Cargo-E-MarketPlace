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

/*
 *
 * \brief Driver Registration Function
 *
 * \details The Driver should be able to add there details to the database.
 *          The function establishes the connection eith the database.
 *          Collects the inputs from the user and then stores it in the database.
*/

void DriverRegDialog::on_Confirm_clicked()
{

    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();

    dbconnection->createTables();

    QSqlQuery qry;

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

    TransportRegDialog *transReg = new TransportRegDialog(this);
    QString hashed_password = transReg->hash_Password(in_password);

    QSqlQuery query;
    query.prepare("SELECT * FROM drivers WHERE username = '"+in_username+"'");
    query.exec();

    if (check_inputs(in_username,in_firstname,in_surname,in_email,in_mobile,in_address,in_ninum,in_password,in_driverid) == "Message1")
    {
        QMessageBox::information(this,"Register","Empty Values");
    }
    else if(check_inputs(in_username,in_firstname,in_surname,in_email,in_mobile,in_address,in_ninum,in_password,in_driverid) == "Message2"){
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
            qry.addBindValue(in_ninum);
            qry.addBindValue(in_driverid);
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

void DriverRegDialog::on_ToLogin_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}

/*
 *
 * \brief Check Driver Registration Details
 *
 * \details Checks the inputs are correct
 *
 * \returns QString tell function what Message to display
*/

QString DriverRegDialog::check_inputs(QString in_username, QString in_firstname, QString in_surname, QString in_email, QString in_mobile, QString in_address, QString in_ninum, QString in_password, QString in_driverid)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM drivers WHERE username = '"+in_username+"'");
    query.exec();

    if (in_firstname== "" || in_surname== "" || in_address== "" || in_password== "" || in_username== "" || in_email== "" || in_mobile== "" || in_ninum== "" || in_driverid== "")
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
