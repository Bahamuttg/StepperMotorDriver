#include "threadworker.h"
#include <QtCore>
#include <wiringPi.h>
#include "steppermotor.h"

Worker::Worker(StepperMotor *Motor)
{
    this->_Motor = Motor;
    this->Terminate = false;
}

Worker::~Worker()
{
    // free resources
}

void Worker::process()
{
    while (!this->Terminate)
    {
        _Motor->Rotate(_Motor->Direction, 1, 50);
    }
    emit finished();
}

