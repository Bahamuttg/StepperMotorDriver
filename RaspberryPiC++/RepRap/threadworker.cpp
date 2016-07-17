#include "threadworker.h"
#include <QtCore>
#include <wiringPi.h>

void doWork(const QString &parameter)
{
    // ...
    emit resultReady(result);
}

ThreadController::ThreadController()
{
    ThreadWorker *worker = new ThreadWorker;
    worker->moveToThread(&workerThread);
    connect(&workerThread, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(this, SIGNAL(operate(QString)), worker, SLOT(doWork(QString)));
    connect(worker, SIGNAL(resultReady(QString)), this, SLOT(handleResults(QString)));
    workerThread.start();
}
ThreadController::~ThreadController()
{
    workerThread.quit();
    workerThread.wait();
}

void resultReady(const QString &result)
{

}

void handleResults(const QString &)
{
}

void operate(const QString &)
{

}

