#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Transport_Company_pushButton_clicked()
{
    hide();
    TransportRegDialog *transportRegDialog = new TransportRegDialog(this);
    transportRegDialog->show();
}

void MainWindow::on_Driver_pushButton_clicked()
{
    hide();
    DriverRegDialog *driverRegDialog = new DriverRegDialog(this);
    driverRegDialog->show();
}

void MainWindow::on_Cargo_Owner_pushButton_clicked()
{
    hide();
    CargoRegDialog *cargoRegDialog = new CargoRegDialog(this);
    cargoRegDialog->show();
}
