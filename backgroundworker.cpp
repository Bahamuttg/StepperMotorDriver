#include "backgroundworker.h"
#include <QtCore>

BackgroundWorker::BackgroundWorker()
{

}

BackgroundWorker::~BackgroundWorker()
{

}
void BackgroundWorker::RunWorkerAsync()
{
        QThread *thread = new QThread;
        this->moveToThread(thread);

        connect(thread, SIGNAL(started()), this, SLOT(DoWork()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        connect(this, SIGNAL(ReportProgress()), this, SLOT(ProgressReported()));
        connect(this, SIGNAL(WorkComplete()), this, SLOT(RunWorkerCompleted()));
        thread->start();
        emit WorkerStarted();
}


