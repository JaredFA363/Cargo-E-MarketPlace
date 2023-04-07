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
    //void setVars(QString, QString);

private slots:
    void on_Logout_clicked();

    void on_profile_clicked();

private:
    Ui::userform *ui;
    QString account;
    QString log_user;
    void changeOrderStatus(QString);
    void changeOrderId(QString);
    void setVars(QString, QString);
};

#endif // USERFORM_H
