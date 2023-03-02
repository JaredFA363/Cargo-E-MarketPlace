#ifndef TRANSPORTREGDIALOG_H
#define TRANSPORTREGDIALOG_H

#include <QDialog>
#include <QtSql>
#include "logindialog.h"
#include "dbcon.h"

namespace Ui {
class TransportRegDialog;
}

class TransportRegDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransportRegDialog(QWidget *parent = nullptr);
    ~TransportRegDialog();

private slots:
    void on_confirm_clicked();

    void on_ToLogin_clicked();

private:
    Ui::TransportRegDialog *ui;
};

#endif // TRANSPORTREGDIALOG_H
