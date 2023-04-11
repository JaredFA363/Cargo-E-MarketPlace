#include "logindialog.h"
#include "ui_logindialog.h"
#include "userform.h"
#include "transportcompanyview.h"
#include "driverview.h"
#include "transportregdialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    ui->Login_comboBox->addItem("Transportation Company");
    ui->Login_comboBox->addItem("Driver");
    ui->Login_comboBox->addItem("Cargo Company");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

/*
 *
 * \brief Login Function
 *
 * \details This Function allows users (Cargo Owner, Transportation Company, Driver)
 *          to login. Takes the inputs then compares it with the database.
 *          If correct allows user to enter program, if not throws error.
*/

void LoginDialog::on_Login_pushButton_clicked()
{
    dbcon *dbconnection = new dbcon();
    dbconnection->openConn();
    QString account_type = ui->Login_comboBox->currentText();
    QString username = ui->Login_username->text();
    QString password = ui->Login_password->text();

    TransportRegDialog *transReg = new TransportRegDialog(this);
    QString hashed_password = transReg->hash_Password(password);

    if (checkLoginDetails(account_type,username,hashed_password) == "Correct Transportation Company")
    {
        QMessageBox::information(this,"Login","Success");
        hide();
        transportcompanyview *transview = new transportcompanyview(account_type, username, this);
        transview->show();
    }
    else if (checkLoginDetails(account_type,username,hashed_password) == "Correct Driver")
    {
        QMessageBox::information(this,"Login","Success");
        hide();
        driverview *Driver = new driverview(account_type, username, this);
        Driver->show();
    }
    else if (checkLoginDetails(account_type,username,hashed_password) == "Correct Cargo Company")
    {
        QMessageBox::information(this,"Login","Success");
        hide();
        userform *userForm = new userform(account_type, username, this);
        userForm->show();
    }
    else if (checkLoginDetails(account_type,username,hashed_password) == "Incorrect Password")
    {
        QMessageBox::information(this,"Login","Incorrect Password");
    }
    else if (checkLoginDetails(account_type,username,hashed_password) == "Incorrect Username")
    {
        QMessageBox::information(this,"Login","Incorrect Username");
    }
    else
    {
        QMessageBox::information(this,"Login","Incorrect Values");
    }

    dbconnection->discConn();
}

QString LoginDialog::checkLoginDetails(QString account_type,QString username,QString hashed_password)
{
    QString username_1 = "'"+username+"'";
    QString db_pass;
    QSqlQuery query;

    if (account_type == "Transportation Company")
    {
        query.exec("SELECT password FROM transportcompany WHERE username ="+username_1+"");
        if(query.first() == true)
        {
            QString db_pass = query.value(0).toString();
            if (db_pass == hashed_password)
            {
                return "Correct Transportation Company";
            }
            else
            {
                return "Incorrect Password";
            }
        }
        else
        {
            return "Incorrect Username";
        }
    }
    else if (account_type == "Driver")
    {
        query.exec("SELECT password FROM drivers WHERE username ="+username_1+"");
        if(query.first() == true)
        {
            QString db_pass = query.value(0).toString();
            if (db_pass == hashed_password)
            {
                return "Correct Driver";
            }
            else
            {
                return "Incorrect Password";
            }
        }
        else
        {
            return "Incorrect Username";
        }
    }
    else if (account_type == "Cargo Company")
    {
        query.exec("SELECT password FROM cargoowner WHERE username ="+username_1+"");
        if(query.first() == true)
        {
            QString db_pass = query.value(0).toString();
            if (db_pass == hashed_password)
            {
                return "Correct Cargo Company";
            }
            else
            {
                return "Incorrect Password";
            }
        }
        else
        {
            return "Incorrect Username";
        }
    }
    else
    {
        return "";
    }
}
