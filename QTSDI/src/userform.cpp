#include "userform.h"
#include "ui_userform.h"

userform::userform(QString acc, QString user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userform)
{
    ui->setupUi(this);
    setVars(acc,user);
}

userform::~userform()
{
    delete ui;
}

void userform::on_Logout_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}

void userform::on_profile_clicked()
{
    hide();
    profile *Profile = new profile(account, log_user, this);
    Profile->show();
}

void userform::setVars(QString acc, QString user)
{
    log_user = user;
    account = acc;
}

void userform::changeOrderStatus(QString new_status)
{
    ui->status->setText(new_status);
}


void userform::on_pushButton_clicked()
{
    QString in_source = ui->source->text();
    QString in_destination = ui->destination->text();
    QString in_weight = ui->weight->text();
    QString in_dimensions = ui->dimensions->text();
    QString in_condition = ui->condition->text();
    QString in_transCompany = ui->transCompany->text();

    QString transCompany = "'"+in_transCompany+"'";

    if(in_source == "" || in_destination == "" || in_weight == "" || in_condition == "" || in_transCompany == "" || in_dimensions == "")
    {
        QMessageBox::information(this,"Order","Invalid input");
    }
    else
    {
        dbcon *dbconnection = new dbcon();
        dbconnection->openConn();

        QSqlQuery query;

        query.exec("SELECT username FROM transportcompany WHERE username ="+transCompany+"");
        if(!query.exec())
        {
            QMessageBox::information(this,"Order","No Such Company");
        }
        else{
            QSqlQuery qry;
            qry.prepare("INSERT INTO orders(source, destination, weight, dimensions, condition, transportcompany, orderstatus)"
                        "VALUES (?,?,?,?,?,?,?)");
            try{
                qry.addBindValue(in_source);
                qry.addBindValue(in_destination);
                qry.addBindValue(in_weight);
                qry.addBindValue(in_dimensions);
                qry.addBindValue(in_condition);
                qry.addBindValue(in_transCompany);
                qry.addBindValue("Order Placed");
                qry.exec();

                changeOrderStatus("Order Placed");

            }catch(QSqlError e){
                throw new QSqlError;
            }

        }
        dbconnection->discConn();
    }
}
