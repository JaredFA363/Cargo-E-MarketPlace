#include "transportregdialog.h"
#include "ui_transportregdialog.h"

TransportRegDialog::TransportRegDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransportRegDialog)
{
    ui->setupUi(this);
}

TransportRegDialog::~TransportRegDialog()
{
    delete ui;
}

void TransportRegDialog::on_confirm_clicked()
{
    dbcon();
}

void TransportRegDialog::on_ToLogin_clicked()
{
    hide();
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->show();
}
