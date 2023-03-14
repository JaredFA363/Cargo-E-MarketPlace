#include "userform.h"
#include "ui_userform.h"

userform::userform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userform)
{
    ui->setupUi(this);
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
