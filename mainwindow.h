#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "steppermotor.h"
#include "motorworker.h"
#include <QtCore>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    StepperMotor *Motor_1;// = new StepperMotor(1,2,3,4,false);

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_pressed();
    void on_pushButton_pressed();
    void on_ProgressChanged(QString);
    void ThreadedRotate();
    void errorString(QString);

signals:


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
