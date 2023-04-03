#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>
#include <QtSql>
#include "logindialog.h"

namespace Ui {
class profile;
}

class profile : public QDialog
{
    Q_OBJECT

public:
    explicit profile(QWidget *parent = nullptr);
    ~profile();

private slots:
    void on_profile_back_clicked();

private:
    Ui::profile *ui;
};

#endif // PROFILE_H
