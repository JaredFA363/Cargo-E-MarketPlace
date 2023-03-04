#include "logindialog.h"
#include "ui_logindialog.h"

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

void LoginDialog::on_Login_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/jared/SDI_group_B6/db.db");
    db.open();

    if (!db.open())
    {
        qDebug()<<"problem opening database";
    }

    QString acc_type = ui->Login_comboBox->currentText();
    QString username = ui->Login_username->text();
    QString password = ui->Login_password->text();
    QSqlQuery query;

    if (acc_type == "Transportation Company")
    {
        QString username_1 = "'"+username+"'";
        if(query.exec("SELECT password FROM transportcompany WHERE username ="+username_1+""))
        {
            query.first();
            QString db_pass = query.value(0).toString();
            if (db_pass == password)
            {
                QMessageBox::information(this,"Login","Success");
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

    }
    else if (acc_type == "Cargo Company")
    {

    }
}
