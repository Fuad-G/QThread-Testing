#ifndef WORKERSUBCLASS_H
#define WORKERSUBCLASS_H

#include <QObject>
#include <QDebug>

class WorkerSubclass : public QObject
{
    Q_OBJECT
public:
    WorkerSubclass(QObject* parent) : QObject(parent) {}
    WorkerSubclass() = default;

public slots:
    void CheckThread() {
        qDebug() << "Subworker doing work" << this->thread();
    }
};

#endif // WORKERSUBCLASS_H
