#include "driverregdialog.h"
#include "ui_driverregdialog.h"

DriverRegDialog::DriverRegDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DriverRegDialog)
{
    ui->setupUi(this);
}

DriverRegDialog::~DriverRegDialog()
{
    delete ui;
}

void DriverRegDialog::on_Confirm_clicked()
{

}

void DriverRegDialog::on_ToLogin_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}
