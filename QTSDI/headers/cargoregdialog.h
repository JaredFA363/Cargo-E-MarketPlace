#ifndef CARGOREGDIALOG_H
#define CARGOREGDIALOG_H

#include <QDialog>

namespace Ui {
class CargoRegDialog;
}

class CargoRegDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CargoRegDialog(QWidget *parent = nullptr);
    ~CargoRegDialog();

private:
    Ui::CargoRegDialog *ui;
};

#endif // CARGOREGDIALOG_H
