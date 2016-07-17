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
    MotorWorker *worker = new Worker(Motor_1);
    connect(ui->pushButton, SIGNAL(released()), worker, SLOT(Terminate()));
    connect(ui->pushButton_2, SIGNAL(released()), worker, SLOT(Terminate()));
    connect(worker, SIGNAL(ProgressChanged(QString)), this, SLOT(on_ProgressChanged(QString)));
    connect(worker, SIGNAL(Error(QString)), this, SLOT(errorString(QString)));
    connect(worker, SIGNAL(Finished()), worker, SLOT(deleteLater()));
    //    if(ui->pushButton->isDown() || ui->pushButton_2->isDown())
    //    {
    //        thread->start();
    //    }
    worker->start();
}

void MainWindow::errorString(QString err)
{
     qDebug() << err;
}
