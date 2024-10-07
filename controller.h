#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include "worker.h"

class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;

public:
    Controller() {
        Worker *worker = new Worker;
        qDebug() << "GUI THREAD" << worker->thread();
        qDebug() << "SUBCLASS THREAD 2 - Parented to worker thread" << worker->m_workerSubclass->thread();
        qDebug() << "SUBCLASS THREAD 3 - Default instantiated" << worker->m_workerSubclass2.thread();

        // Move worker to new thread, check if local QObject members moved with it
        worker->moveToThread(&workerThread);


        qDebug() << "WORKER THREAD" << worker->thread();
        qDebug() << "SUBCLASS THREAD 2 - Parented to worker thread" << worker->m_workerSubclass->thread();
        qDebug() << "SUBCLASS THREAD 3 - Default instantiated" << worker->m_workerSubclass2.thread();


        connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
        connect(this, &Controller::operate, worker, &Worker::doWork);
        //connect(worker, &Worker::resultReady, this, &Controller::handleResults);
        workerThread.start();

        QTimer::singleShot(5000, worker, &Worker::doWork);
        //QTimer::singleShot(5000, worker->m_workerSubclass, &WorkerSubclass::CheckThread);
        QTimer::singleShot(5000, &(worker->m_workerSubclass2), &WorkerSubclass::CheckThread);
    }
    ~Controller() {
        workerThread.quit();
        workerThread.wait();
    }
public slots:
    //void handleResults(const QString &);
signals:
    void operate(const QString &);
};

#endif // CONTROLLER_H
