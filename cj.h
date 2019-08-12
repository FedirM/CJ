#ifndef CJ_H
#define CJ_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>

#include <loader.h>

class CJ : public QObject
{
    Q_OBJECT
public:

    explicit CJ(QObject *parent = nullptr);
    static QObject *initSingleton(QQmlEngine *engine, QJSEngine *scriptEngine);
    ~CJ();

    Q_INVOKABLE
    void runLoader();

signals:
    void repeatPercent(double percent);
    void repeatFinished();
    void repeatError(QString msg);

public slots:
    void onErrorString(QString msg);
    void onNewPercent(double percent);
    void onFinished();

private:
    QVector<QString> *hi, *hx, *pn, *tn, *cj;
};

#endif // CJ_H
