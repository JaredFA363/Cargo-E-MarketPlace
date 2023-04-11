#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QObject>
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
    QString checkLoginDetails(QString,QString,QString);

private slots:
    void on_Login_pushButton_clicked();

private:
    Ui::LoginDialog *ui;

};

#endif // LOGINDIALOG_H
