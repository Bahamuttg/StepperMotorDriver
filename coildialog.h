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
    int A1;
    int A2;
    int B1;
    int B2;

    explicit CoilDialog(int A1, int A2, int B1, int B2, QWidget *parent = 0);
    ~CoilDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_Value_ChangedA1(QString);
    void on_Value_ChangedA2(QString);
    void on_Value_ChangedB1(QString);
    void on_Value_ChangedB2(QString);

private:
    Ui::CoilDialog *ui;
};

#endif // COILDIALOG_H
