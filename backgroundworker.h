#ifndef BACKGROUNDWORKER_H
#define BACKGROUNDWORKER_H
#include <QtCore>

class BackgroundWorker : public QThread
{
private:
    Q_OBJECT
public:
    BackgroundWorker();
    ~BackgroundWorker();
    bool Cancel;

public slots:
    virtual void DoWork();
    virtual void ProgressReported();
    virtual void RunWorkerCompleted();

signals:
    void RunWorkerAsync();
    void ReportProgress();
    void WorkComplete();
    void Error(QString err);
};

#endif // BACKGROUNDWORKER_H
