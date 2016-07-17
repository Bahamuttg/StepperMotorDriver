#ifndef THREADWORKER_H
#define THREADWORKER_H
#include <QtCore>
#include <wiringPi.h>
#include "steppermotor.h"

class Worker : public QObject
{
    Q_OBJECT
    StepperMotor *_Motor;

public:
    Worker(StepperMotor *Motor);
    ~Worker();
    bool Terminate;

public slots:
    void process();

signals:
    void finished();
    void error(QString err);

private:
    // add your variables here
};

#endif//THREADWORKER_H
