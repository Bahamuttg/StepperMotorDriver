#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "steppermotor.h"
#include <QtCore>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    StepperMotor *Motor_1;// = new StepperMotor(1,2,3,4,false);

    ~MainWindow();

private slots:
    void on_pushButton_2_pressed();
    void on_pushButton_pressed();
    void ThreadedRotate();
    void errorString(QString);

signals:


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
