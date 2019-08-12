#include "loader.h"

#include <QFile>
#include <QVector>
#include <QTextStream>
#include <QDebug>
#include <QThread>

Loader::Loader(QObject *parent) : QObject(parent)
{
    hi = new QVector<QString>;
    cj = new QVector<QString>;
    hx = new QVector<QString>;
    tn = new QVector<QString>;
    pn = new QVector<QString>;
}

void Loader::setVectors(QVector<QString> *hi, QVector<QString> *hx, QVector<QString> *pn, QVector<QString> *tn, QVector<QString> *cj)
{
    this->hi = hi;
    this->hx = hx;
    this->pn = pn;
    this->tn = tn;
    this->cj = cj;
}

void Loader::load()
{
    QFile inFH(":/data/REPO2.txt");
    if( !inFH.open(QIODevice::ReadOnly) ){
        qDebug() << "Cann't open file!!!" << inFH.errorString();
        emit errorString(inFH.errorString() + "\nCan't find file with initial data...");
        return;
    }

    QTextStream in(&inFH);
    in.setCodec("utf-8");
    int counter = 0;

    while( !in.atEnd() ){
        QString tmpStr = in.readLine();
        if( !tmpStr.isEmpty() ){
            QVector<QString> tmp = tmpStr.split("|").toVector();

            hi->push_back(tmp.at(0));
            hx->push_back(tmp.at(1));
            tn->push_back(tmp.at(2));
            pn->push_back(tmp.at(3));
            cj->push_back(tmp.at(4));
            if( counter++ % 820 == 0 ){
                emit newPercent( ((counter / 408600.0) * 100) );
            }
//            qDebug() << "Curr counter: " << counter;
        }
    }
    emit newPercent( 100.0 );
    emit finished();
    qDebug() << "Vec size (in loader): " << hi->size();
    qDebug() << "Loader finish loading....";
}
