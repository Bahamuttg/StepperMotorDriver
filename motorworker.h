#ifndef MOTORWORKER_H
#define MOTORWORKER_H
#include <QThread>
#include <QtCore>
#include "steppermotor.h"

class MotorWorker : public QObject
{
    Q_OBJECT
    StepperMotor *_Motor;

public:
    bool StopThread;
    bool IsBusy;

    MotorWorker(StepperMotor *Motor)
    {
        this->_Motor = Motor;
        this->StopThread = false;
    }

public slots:
    void DoWork()
    {
        qDebug()<< "Firing Thread!";
        while (!this->StopThread)
        {
            _Motor->Rotate(_Motor->Direction, 1, 50);
            qDebug()<< "Stepping";
            emit ProgressChanged(QString::number(_Motor->Position));
        }
        this->StopThread = false;
		emit WorkComplete("Done");
    }

    void Stop()
    {
        qDebug()<< "Setting Stop Flag!";
        this->StopThread = true;
    }

signals:
    void ProgressChanged(QString info);
    void WorkComplete(QString result);
    void Error(QString err);
};

#endif // MOTORWORKER_H
