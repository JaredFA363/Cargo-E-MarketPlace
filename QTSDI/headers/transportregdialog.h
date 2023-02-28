#ifndef TRANSPORTREGDIALOG_H
#define TRANSPORTREGDIALOG_H

#include <QDialog>

namespace Ui {
class TransportRegDialog;
}

class TransportRegDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransportRegDialog(QWidget *parent = nullptr);
    ~TransportRegDialog();

private:
    Ui::TransportRegDialog *ui;
};

#endif // TRANSPORTREGDIALOG_H
