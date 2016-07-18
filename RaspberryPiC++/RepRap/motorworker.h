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
    QThread WorkerThread;
    MotorWorker(StepperMotor * Motor)
    {
        this->_Motor = Motor;
        this->StopThread = false;
    }

public slots:
    void DoWork()
    {
        while (!this->StopThread)
        {
            _Motor->Rotate(_Motor->Direction, 1, 50);
        }
    }

    void Terminate()
    {
        this->StopThread = true;
    }

signals:
    void ProgressChanged(QString info);
    void WorkComplete(QString result);
    void Error(QString err);

};
class Controller : public QObject
 {
     Q_OBJECT
     QThread workerThread;
 public:
     Controller(StepperMotor *Motor)
     {
         MotorWorker *worker = new MotorWorker(Motor);
         worker->moveToThread(&workerThread);
         connect(&workerThread, SIGNAL(finished()), worker, SLOT(deleteLater()));
         connect(this, SIGNAL(operate()), worker, SLOT(DoWork()));

         workerThread.start();
     }
     ~Controller()
     {
         workerThread.quit();
         workerThread.wait();
     }
 public slots:

 signals:
     void operate();
 };

#endif // MOTORWORKER_H
