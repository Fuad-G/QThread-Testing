#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "workersubclass.h"

class Worker : public QObject
{
    Q_OBJECT

public:

    Worker() {
        m_workerSubclass = new WorkerSubclass(this);
    }

    WorkerSubclass * m_workerSubclass;

    WorkerSubclass m_workerSubclass2;


public slots:
    void doWork() {
        qDebug() << "Worker doing work" << this->thread();
    }

signals:
    void resultReady(const QString &result);


};

#endif // WORKER_H
