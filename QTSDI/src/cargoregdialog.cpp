#include "cargoregdialog.h"
#include "ui_cargoregdialog.h"

CargoRegDialog::CargoRegDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CargoRegDialog)
{
    ui->setupUi(this);
}

CargoRegDialog::~CargoRegDialog()
{
    delete ui;
}

void CargoRegDialog::on_Confirm_clicked()
{

}
