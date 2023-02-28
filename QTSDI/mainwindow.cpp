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

}

void MainWindow::on_Driver_pushButton_clicked()
{

}

void MainWindow::on_Cargo_Owner_pushButton_clicked()
{

}
