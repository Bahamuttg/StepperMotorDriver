#ifndef MOTORWORKER_H
#define MOTORWORKER_H
#include <QThread>
#include "steppermotor.h"

class MotorWorker : public QThread
{
private:
    StepperMotor *_Motor;

public:
    bool StopThread;

    MotorWorker(StepperMotor *);
    ~MotorWorker();

    void run();
public slots:
    void Terminate();

signals:
    void ProgressChanged(QString info);
    void WorkComplete(QString result);
    void Error(QString err);

};

#endif // MOTORWORKER_H
