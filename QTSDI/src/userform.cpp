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

    if (checkOrder(in_source,in_destination,in_weight,in_condition,in_transCompany,in_dimensions) == "Empty Order")
    {
        QMessageBox::information(this,"Order","Empty Order");
    }
    else if (checkOrder(in_source,in_destination,in_weight,in_condition,in_transCompany,in_dimensions) == "No Such Company")
    {
        QMessageBox::information(this,"Order","No Such Company");
    }
    else if (checkOrder(in_source,in_destination,in_weight,in_condition,in_transCompany,in_dimensions) == "Order Placed")
    {
        dbcon *dbconnection = new dbcon();
        dbconnection->openConn();

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
        dbconnection->discConn();
    }
    else
    {
        QMessageBox::information(this,"Order","Invalid Order");
    }

}

QString userform::checkOrder(QString in_source, QString in_destination, QString in_weight, QString in_condition, QString in_transCompany, QString in_dimensions)
{
    QString transCompany = "'"+in_transCompany+"'";

    if(in_source == "" || in_destination == "" || in_weight == "" || in_condition == "" || in_transCompany == "" || in_dimensions == "")
    {
        return "Empty Order";
    }
    else
    {
        dbcon *dbconnection = new dbcon();
        dbconnection->openConn();

        QSqlQuery query;

        query.exec("SELECT username FROM transportcompany WHERE username = "+transCompany+"");
        dbconnection->discConn();
        if(query.first() == false)
        {
            return "No Such Company";
        }
        else{
            return "Order Placed";
        }

        return "";
    }
}
