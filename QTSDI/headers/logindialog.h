#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include "dbcon.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    QString getUserType();

private slots:
    void on_Login_pushButton_clicked();

private:
    Ui::LoginDialog *ui;
    //QString getUserType();
};

#endif // LOGINDIALOG_H
