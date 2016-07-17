#include "threadworker.h"
#include <QtCore>
#include <wiringPi.h>
#include "steppermotor.h"

Worker::Worker(StepperMotor *Motor)
{
    this->_Motor = Motor;
    this->Stop = false;
}

Worker::~Worker()
{
    // free resources
}

void Worker::Process()
{
    while (!this->Stop)
    {
        _Motor->Rotate(_Motor->Direction, 1, 50);
    }
    emit Finished();
}

void Worker::Terminate()
{
    this->Stop = true;
}
