#ifndef COILDIALOG_H
#define COILDIALOG_H

#include <QDialog>

namespace Ui {
class CoilDialog;
}

class CoilDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CoilDialog(QWidget *parent = 0);
    ~CoilDialog();

private:
    Ui::CoilDialog *ui;
};

#endif // COILDIALOG_H
