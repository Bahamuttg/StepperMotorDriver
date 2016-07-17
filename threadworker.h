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
    bool Stop;

public slots:
    void Process();
    void Terminate();

signals:
    void Finished();
    void Error(QString err);
};

#endif//THREADWORKER_H
