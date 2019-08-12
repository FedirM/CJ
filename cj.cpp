#include "cj.h"
#include "loader.h"

#include <QFile>
#include <QVector>
#include <QTextStream>
#include <QDebug>
#include <QThread>


CJ::CJ(QObject *parent) : QObject(parent)
{
    hi = new QVector<QString>();
    cj = new QVector<QString>();
    hx = new QVector<QString>();
    tn = new QVector<QString>();
    pn = new QVector<QString>();
}

QObject *CJ::initSingleton(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    CJ *cj = new CJ();
    return cj;
}

CJ::~CJ()
{
    delete hi;
    delete cj;
    delete hx;
    delete tn;
    delete pn;
}

void CJ::runLoader()
{
    QThread *thread = new QThread();
    Loader* worker = new Loader();
    worker->setVectors(hi, hx, pn, tn, cj);

    worker->moveToThread(thread);
    connect(worker, SIGNAL(errorString(QString)), this, SLOT(onErrorString(QString)));
    connect(worker, SIGNAL(newPercent(double)), this, SLOT(onNewPercent(double)));
    connect(worker, SIGNAL(finished()), this, SLOT(onFinished()));
    connect(thread, SIGNAL(started()), worker, SLOT(load()));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

void CJ::onErrorString(QString msg)
{
    qDebug() << "New error has been occuer....\nErr msg: " << msg;
    emit repeatError(msg);
}

void CJ::onNewPercent(double val)
{
    emit repeatPercent(val);
}

void CJ::onFinished()
{
//    worker->getVectors(hi, hx, pn, tn, cj);
    qDebug() << "Loaded vectors size: " << hi->size();
    emit repeatFinished();
}
