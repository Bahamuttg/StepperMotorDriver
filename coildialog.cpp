#include "coildialog.h"
#include "ui_coildialog.h"

CoilDialog::CoilDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoilDialog)
{
    ui->setupUi(this);
}

CoilDialog::~CoilDialog()
{
    delete ui;
}
