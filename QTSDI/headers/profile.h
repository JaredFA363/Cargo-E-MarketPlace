#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>
#include <QtSql>
#include "dbcon.h"
#include "logindialog.h"

namespace Ui {
class profile;
}

class profile : public QDialog
{
    Q_OBJECT

public:
    explicit profile(QString, QString,QWidget *parent = nullptr);
    ~profile();
    //void getDetails();
    //void setVars(QString,QString);

private slots:
    void on_profile_back_clicked();

    void on_profile_save_clicked();

private:
    Ui::profile *ui;
    QString retrieved_username;
    QString retrieved_accountType;
    void getDetails();
    void setVars(QString,QString);
    void change_details();

};

#endif // PROFILE_H
