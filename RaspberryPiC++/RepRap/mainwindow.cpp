#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "threadworker.h"
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

    Motor_1->Rotate(CTRCLOCKWISE, 1, 50);
    while (ui->pushButton->isDown())
    {
        delay(100);
    }
    delete T;
}

void MainWindow::on_pushButton_pressed()
{
    QPushButton *button = ui->pushButton;
    QTimer *T = new QTimer(this);
    connect(T, SIGNAL(timeout()), this, SLOT(ThreadedRotate(button)));
    T->setSingleShot(true);
    T->start(1000);

    Motor_1->Rotate(CLOCKWISE, 1, 50);
    while (ui->pushButton->isDown())
    {
        delay(100);
    }
    delete T;
}

void MainWindow::ThreadedRotate(QPushButton *button)
{
    QThread *thread = new QThread;
    Worker *worker = new Worker(Motor_1);
    worker->moveToThread(thread);
    connect(button, SIGNAL(released()), worker, SLOT(Terminate()));
    connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), worker, SLOT(Process()));
    connect(worker, SIGNAL(Finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(Finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(Finished()), thread, SLOT(deleteLater()));
    thread->start();
}

void MainWindow::errorString(QString err)
{
     qDebug() << err;
}
