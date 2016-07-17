#ifndef BACKGROUNDWORKER_H
#define BACKGROUNDWORKER_H
#include <QtCore>

class BackgroundWorker : public QObject
{
private:
    Q_OBJECT
public:
    BackgroundWorker();
    ~BackgroundWorker();
    bool Cancel;
    void RunWorkerAsync();

public slots:
    virtual void DoWork();
    virtual void ProgressReported();
    virtual void RunWorkerCompleted();

signals:
    void WorkerStarted();
    void ReportProgress();
    void WorkComplete();
    void Error(QString err);
};

#endif // BACKGROUNDWORKER_H
