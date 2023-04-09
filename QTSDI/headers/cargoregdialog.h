#ifndef CARGOREGDIALOG_H
#define CARGOREGDIALOG_H

#include <QDialog>
#include <QtSql>
#include "logindialog.h"
#include "transportregdialog.h"
#include "dbcon.h"

namespace Ui {
class CargoRegDialog;
}

class CargoRegDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CargoRegDialog(QWidget *parent = nullptr);
    ~CargoRegDialog();

private slots:
    void on_Confirm_clicked();

    void on_ToLogin_clicked();

private:
    Ui::CargoRegDialog *ui;
};

#endif // CARGOREGDIALOG_H
