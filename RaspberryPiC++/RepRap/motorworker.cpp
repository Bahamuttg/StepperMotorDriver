#include "motorworker.h"
#include <QThread>
#include <QtCore>
#include "steppermotor.h"

MotorWorker::MotorWorker(StepperMotor *Motor)
{
    this->_Motor = Motor;
    this->StopThread = false;
}

void MotorWorker::DoWork()
{
    QString result;
    while (!this->StopThread)
    {
        _Motor->Rotate(_Motor->Direction, 1, 50);
    }
    emit WorkComplete(result);
}

void MotorWorker::Terminate()
{
    this->StopThread = true;
}
