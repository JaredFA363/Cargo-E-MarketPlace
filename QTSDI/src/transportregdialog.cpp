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
    try{
        qry.addBindValue(input_username);
        qry.addBindValue(companyname);
        qry.addBindValue(hashed_password);
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

QString TransportRegDialog::hash_Password(QString password)
{
    QByteArray hashData = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QString hash_password = QString::fromLatin1(hashData.toHex());
    return hash_password;
}
