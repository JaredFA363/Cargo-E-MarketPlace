#include "profile.h"
#include "ui_profile.h"
#include "userform.h"

profile::profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);

    LoginDialog *loginDialog = new LoginDialog(this);
    QString acc_type,username = loginDialog->getUserType();

}

profile::~profile()
{
    delete ui;
}

void profile::on_profile_back_clicked()
{
    hide();
    userform *userForm = new userform(this);
    userForm->show();
}
