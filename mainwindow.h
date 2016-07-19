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
private:
    Q_OBJECT
    bool StopThread;
public:
    StepperMotor *Motor_1;// = new StepperMotor(1,2,3,4,false);
    QTimer *ButtonTimer;
    QThread *MotorThread;
    MotorWorker *Worker;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_pressed();
    void on_pushButton_pressed();
    void errorString(QString);
    void ResetThreadStop();

    void on_pushButton_released();

    void on_pushButton_2_released();

signals:


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
