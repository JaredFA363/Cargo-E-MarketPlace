#include "profile.h"
#include "ui_profile.h"

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
