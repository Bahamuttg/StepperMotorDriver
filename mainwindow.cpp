#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "motorworker.h"
#include "steppermotor.h"
#include <QtCore>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include "coildialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Motor_1 = new StepperMotor(1,2,3,4,false);
    ButtonTimer = new QTimer(this);
    MotorThread = new QThread(this);

    ButtonTimer->setInterval(1000);
    Worker = new MotorWorker(Motor_1);
    Worker->moveToThread(MotorThread);
    //Link the MotorThread to the DoWork Slot.
    connect(MotorThread, SIGNAL(started()), Worker, SLOT(DoWork()));
    connect(MotorThread, SIGNAL(terminated()), Worker, SLOT(Stop()));
    connect(Worker, SIGNAL(ProgressChanged(QString)), this, SLOT(UpdatePositionLabel(QString)));
    //Link the Timer elapsed to the MotorThread start.
    connect(ButtonTimer, SIGNAL(timeout()), MotorThread, SLOT(start()));
    //Link the Timer elapsed to the Timer stop so we can use it again.
    connect(ButtonTimer, SIGNAL(timeout()), ButtonTimer, SLOT(stop()));
    //Link the Buttons pressed signal to the timer start
    connect(ui->pushButton, SIGNAL(pressed()), ButtonTimer, SLOT(start()));
    connect(ui->pushButton_2, SIGNAL(pressed()), ButtonTimer, SLOT(start()));
    //Link the Buttons released signal to the MotorThread quit.
    connect(ui->pushButton, SIGNAL(released()), MotorThread, SLOT(quit()));
    connect(ui->pushButton_2, SIGNAL(released()), MotorThread, SLOT(quit()));
    //Link the Buttons released signal to the ButtonTimer stop.
    connect(ui->pushButton, SIGNAL(released()), ButtonTimer, SLOT(stop()));
    connect(ui->pushButton_2, SIGNAL(released()), ButtonTimer, SLOT(stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete MotorThread;
    delete ButtonTimer;
    delete Motor_1;
}

void MainWindow::on_pushButton_2_pressed()
{
    Worker->StopThread = false;
    Motor_1->Rotate(StepperMotor::CTRCLOCKWISE, 1, 50);
    UpdatePositionLabel(QString::number(Motor_1->Position));
    qDebug()<<"Rotating Counter Clockwise!";
}

void MainWindow::on_pushButton_pressed()
{
    Worker->StopThread = false;
    Motor_1->Rotate(StepperMotor::CLOCKWISE, 1, 50);
    UpdatePositionLabel(QString::number(Motor_1->Position));
    qDebug()<<"Rotating Clockwise!";
}

void MainWindow::ResetThreadStop()
{
    Worker->StopThread = false;
    this->StopThread = false;
}

void MainWindow::errorString(QString err)
{
    qDebug() << err;
}

void MainWindow::on_pushButton_released()
{
    //add if worker is running...
    Worker->Stop();
    qDebug()<<"Button Released!";
}

void MainWindow::on_pushButton_2_released()
{
    //add if worker is running..
    Worker->Stop();
    qDebug()<<"Button Released!";
}

void MainWindow::UpdatePositionLabel(QString Arg)
{
    ui->lblMotorPosition->setText(Arg);
}

void MainWindow::on_action_Exit_triggered()
{
    this->close();
}

void MainWindow::on_action_Configure_Coils_triggered()
{
    CoilDialog CD;
    CD.show();
}

void MainWindow::on_actionUse_NOT_Gates_toggled(bool arg1)
{

}
