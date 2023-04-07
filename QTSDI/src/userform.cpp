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
