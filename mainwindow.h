#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "steppermotor.h"
#include "motorworker.h"
#include <QtCore>
#include <QPushButton>
#include "coildialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
private:
    Q_OBJECT
    bool StopThread;
    unsigned int _A1;
    unsigned int _A2;
    unsigned int _B1;
    unsigned int _B2;

    void UpdateLabels();

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

    void on_pushButton_released();
    void on_pushButton_2_released();

    void errorString(QString);

    void ResetThreadStop();

    void UpdatePositionLabel(QString);

    void UpdateMotorSettings();

    void on_action_Exit_triggered();

    void on_action_Configure_Coils_triggered();

    void on_actionUse_NOT_Gates_toggled(bool arg1);

    void on_action_Reset_MotorPosition_triggered();



    void on_action_Turn_Off_Coils_triggered();

    void on_action_Enable_Motor_triggered();

signals:
    void CoilSettingsChanged();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
