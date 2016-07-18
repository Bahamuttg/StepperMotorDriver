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

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_2_pressed()
{
    QTimer *T = new QTimer(this);
    connect(T, SIGNAL(timeout()), this, SLOT(ThreadedRotate()));
    T->setSingleShot(true);
    T->start(1000);
    Motor_1->Rotate(StepperMotor::CTRCLOCKWISE, 1, 50);
}

void MainWindow::on_pushButton_pressed()
{
    //Timer still not right
    QTimer *T = new QTimer(this);
    connect(T, SIGNAL(timeout()), this, SLOT(ThreadedRotate()));
    T->setSingleShot(true);
    T->start(1000);
    Motor_1->Rotate(StepperMotor::CLOCKWISE, 1, 50);
}

void MainWindow::ThreadedRotate()
{
    Controller *MotorCtrl = new Controller(this->Motor_1);

}

void MainWindow::errorString(QString err)
{
     qDebug() << err;
}
