#ifndef USERFORM_H
#define USERFORM_H

#include <QDialog>
#include "logindialog.h"
#include "profile.h"

namespace Ui {
class userform;
}

class userform : public QDialog
{
    Q_OBJECT

public:
    explicit userform(QString acc, QString user, QWidget *parent = nullptr);
    ~userform();
    void changeOrderStatus(QString);
    QString updated_status;

private slots:
    void on_Logout_clicked();

    void on_profile_clicked();

    void on_pushButton_clicked();

private:
    Ui::userform *ui;
    QString account;
    QString log_user;
    void setVars(QString, QString);
};

#endif // USERFORM_H
