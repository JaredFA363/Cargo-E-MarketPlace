#include "transportregdialog.h"
#include "ui_transportregdialog.h"

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

/*
 *
 * \brief Transportation Company Registration Function
 *
 * \details The Cargo owner should be able to add there details to the database.
 *          The function establishes the connection eith the database.
 *          Collects the inputs from the user and then stores it in the database.
*/

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
    QString hashed_password = hash_Password(input_password);

    if (check_inputs(input_username, input_password, input_address, companyname) == "Message1")
    {
        QMessageBox::information(this,"Register","Empty Values");
    }
    else if(check_inputs(input_username, input_password, input_address, companyname) == "Message2"){
        QMessageBox::information(this,"Register","Invalid Username");
    }
    else
    {
        try{
            qry.addBindValue(input_username);
            qry.addBindValue(companyname);
            qry.addBindValue(hashed_password);
            qry.addBindValue(input_address);
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

void TransportRegDialog::on_ToLogin_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}

/*
 *
 * \brief Hashes the password so it is secured
 *
 * \details This encrypts the password qith QCryptographic Hash
 *
 * \returns THe hashed Password
*/

QString TransportRegDialog::hash_Password(QString password)
{
    QByteArray hashData = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QString hash_password = QString::fromLatin1(hashData.toHex());
    return hash_password;
}

/*
 *
 * \brief Check Transport Company Registration Details
 *
 * \details Checks the inputs are correct
 *
 * \returns QString tell function what Message to display
*/

QString TransportRegDialog::check_inputs(QString input_username,QString input_password,QString input_address,QString companyname)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM transportcompany WHERE username = '"+input_username+"'");
    query.exec();

    if (companyname == "" || input_address== "" || input_password== "" || input_username== "")
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
