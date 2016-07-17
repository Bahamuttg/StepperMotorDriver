#ifndef THREADWORKER_H
#define THREADWORKER_H
#include <QtCore>
#include <wiringPi.h>

class ThreadWorker : public QObject
{
    Q_OBJECT
    QThread workerThread;

public slots:
    void doWork(const QString &parameter);

signals:
    void resultReady(const QString &result);
};

class ThreadController : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    ThreadController();
    ~ThreadController();

public slots:
    void handleResults(const QString &);
signals:
    void operate(const QString &);
};

#endif // THREADWORKER_H

