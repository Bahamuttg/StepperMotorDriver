#ifndef MOTORWORKER_H
#define MOTORWORKER_H
#include <QThread>
#include <QtCore>
#include "steppermotor.h"

class MotorWorker : public QObject
{
private:
    Q_OBJECT
    StepperMotor *_Motor;
    QThread WorkerThread;

public:
    bool StopThread;

    MotorWorker(StepperMotor *);
    ~MotorWorker();

    void DoWork();
public slots:
    void Terminate();

signals:
    void ProgressChanged(QString info);
    void WorkComplete(QString result);
    void Error(QString err);

};

#endif // MOTORWORKER_H
