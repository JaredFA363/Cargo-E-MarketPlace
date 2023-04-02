#ifndef USERFORM_H
#define USERFORM_H

#include <QDialog>
#include "logindialog.h"

namespace Ui {
class userform;
}

class userform : public QDialog
{
    Q_OBJECT

public:
    explicit userform(QWidget *parent = nullptr);
    ~userform();

private slots:
    void on_Logout_clicked();

    void on_profile_clicked();

private:
    Ui::userform *ui;
};

#endif // USERFORM_H
