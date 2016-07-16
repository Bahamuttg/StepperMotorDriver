#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QTimer>

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
    connect(T, SIGNAL(timeout()), this, SLOT(ClockwiseMove()));
    T->setSingleShot(true);
    T->start(1000);

    Motor_1->Rotate(CLOCKWISE, 1, 50);

}

void MainWindow::on_pushButton_pressed()
{
    QTimer *T = new QTimer(this);
    connect(T, SIGNAL(timeout()), this, SLOT(Clockwise()));
    T->setSingleShot(true);
    T->start(1000);

    Motor_1->Rotate(CTRCLOCKWISE, 1, 50);

}

void MainWindow::ClockwiseMove()
{
    while (ui->pushButton->isDown())
    {
        Motor_1->Rotate(CTRCLOCKWISE, 1, 50);
    }
}

void MainWindow::CtrClockwiseMove()
{
    while (ui->pushButton_2->isDown())
    {
        Motor_1->Rotate(CTRCLOCKWISE, 1, 50);
    }
}
