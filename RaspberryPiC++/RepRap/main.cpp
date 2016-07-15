#include "mainwindow.h"
#include <QApplication>
#include "steppermotor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //StepperMotor *Motor = new StepperMotor(1,2,3,4,false);

    return a.exec();
}
