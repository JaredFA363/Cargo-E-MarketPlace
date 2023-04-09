#ifndef DRIVERREGDIALOG_H
#define DRIVERREGDIALOG_H

#include <QDialog>
#include <QtSql>
#include "logindialog.h"
#include "transportregdialog.h"
#include "dbcon.h"

namespace Ui {
class DriverRegDialog;
}

class DriverRegDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DriverRegDialog(QWidget *parent = nullptr);
    ~DriverRegDialog();

private slots:
    void on_Confirm_clicked();

    void on_ToLogin_clicked();

private:
    Ui::DriverRegDialog *ui;
};

#endif // DRIVERREGDIALOG_H
