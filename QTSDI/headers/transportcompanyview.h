#ifndef TRANSPORTCOMPANYVIEW_H
#define TRANSPORTCOMPANYVIEW_H

#include <QDialog>
#include <logindialog.h>
#include <profile.h>
#include <QtSql>
#include "userform.h"
#include "updatedatabasethread.h"
#include "updateorderstatusthread.h"

namespace Ui {
class transportcompanyview;
}

class transportcompanyview : public QDialog
{
    Q_OBJECT

public:
    explicit transportcompanyview(QString acc, QString user, QWidget *parent = nullptr);
    ~transportcompanyview();

private slots:
    void on_accept_clicked();

    void on_profile_clicked();

    void on_logout_clicked();

    void on_update_clicked();

private:
    Ui::transportcompanyview *ui;
    QString retrieved_acc;
    QString retrieved_user;
};

#endif // TRANSPORTCOMPANYVIEW_H
