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
