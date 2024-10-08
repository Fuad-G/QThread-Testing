#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "workersubclass.h"

class Worker : public QObject
{
    Q_OBJECT

public:

    Worker() : m_workerSubclass2(this) {
        m_workerSubclass = new WorkerSubclass(this);
    }

    // Public for testing
    WorkerSubclass * m_workerSubclass; // on heap
    WorkerSubclass m_workerSubclass2; // Initialized in initializer list
    WorkerSubclass m_workerSubclass3; // Default constructed


public slots:
    void doWork() {
        qDebug() << "Worker doing work" << this->thread();
    }

signals:
    void resultReady(const QString &result);

};

#endif // WORKER_H
