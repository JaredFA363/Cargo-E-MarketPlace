#include "logindialog.h"
#include "ui_logindialog.h"
#include "userform.h"

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

    QString acc_type = ui->Login_comboBox->currentText();
    QString username = ui->Login_username->text();
    QString password = ui->Login_password->text();
    QString username_1 = "'"+username+"'";
    QString db_pass;
    QSqlQuery query;

    //profile *profilefind = new profile();

    if (acc_type == "Transportation Company")
    {
        if(query.exec("SELECT password FROM transportcompany WHERE username ="+username_1+""))
        {
            query.first();
            QString db_pass = query.value(0).toString();
            if (db_pass == password)
            {
                QMessageBox::information(this,"Login","Success");
                hide();
                userform *userForm = new userform(this);
                userForm->show();
            }
            else
            {
                QMessageBox::information(this,"Login","Incorrect Password");
            }
        }
        else
        {
            QMessageBox::information(this,"Login","Incorrect Username");
        }
    }
    else if (acc_type == "Driver")
    {
        if(query.exec("SELECT password FROM drivers WHERE username ="+username_1+""))
        {
            query.first();
            QString db_pass = query.value(0).toString();
            if (db_pass == password)
            {
                QMessageBox::information(this,"Login","Success");
                hide();
                userform *userForm = new userform(this);
                userForm->show();
            }
            else
            {
                QMessageBox::information(this,"Login","Incorrect Password");
            }
        }
        else
        {
            QMessageBox::information(this,"Login","Incorrect Username");
        }
    }
    else if (acc_type == "Cargo Company")
    {
        if(query.exec("SELECT password FROM cargoowner WHERE username ="+username_1+""))
        {
            query.first();
            QString db_pass = query.value(0).toString();
            if (db_pass == password)
            {
                QMessageBox::information(this,"Login","Success");
                hide();
                userform *userForm = new userform(this);
                userForm->show();
            }
            else
            {
                QMessageBox::information(this,"Login","Incorrect Password");
            }
        }
        else
        {
            QMessageBox::information(this,"Login","Incorrect Username");
        }
    }
    dbconnection->discConn();
}

QString LoginDialog::getUserType()
{
    QString acc_type = ui->Login_comboBox->currentText();
    QString username = ui->Login_username->text();
    return acc_type,username;
}
