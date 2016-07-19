#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "motorworker.h"
#include <QtCore>
#include <QTimer>
#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Motor_1 = new StepperMotor(1,2,3,4,false);
    ButtonTimer = new QTimer(this);
    MotorThread = new QThread(this);
    ButtonTimer->setSingleShot(true);
    ButtonTimer->setInterval(1000);

    //Link the MotorThread to the DoWork Slot.
    connect(MotorThread, SIGNAL(started()), this, SLOT(DoWork()));
    //Link the timer to the MotorThread start.
    connect(ButtonTimer, SIGNAL(timeout()), MotorThread, SLOT(start()));
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
    Motor_1->Rotate(StepperMotor::CTRCLOCKWISE, 1, 50);
}

void MainWindow::on_pushButton_pressed()
{
    Motor_1->Rotate(StepperMotor::CLOCKWISE, 1, 50);
}

void MainWindow::errorString(QString err)
{
     qDebug() << err;
}
