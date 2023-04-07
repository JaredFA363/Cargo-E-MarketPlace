#ifndef DRIVERVIEW_H
#define DRIVERVIEW_H

#include <QDialog>
#include "profile.h"
#include "logindialog.h"

namespace Ui {
class driverview;
}

class driverview : public QDialog
{
    Q_OBJECT

public:
    explicit driverview(QString acc, QString user, QWidget *parent = nullptr);
    ~driverview();

private slots:
    void on_profile_clicked();

    void on_logout_clicked();

private:
    Ui::driverview *ui;
    QString retrieved_acc;
    QString retrieved_user;
};

#endif // DRIVERVIEW_H
