#ifndef LOADER_H
#define LOADER_H

#include <QObject>

class Loader : public QObject
{
    Q_OBJECT
public:
    explicit Loader(QObject *parent = nullptr);

    void setVectors(QVector<QString> *hi, QVector<QString> *hx, QVector<QString> *pn, QVector<QString> *tn, QVector<QString> *cj);

signals:
    void newPercent(double percent);
    void finished();
    void errorString(QString msg);

public slots:
    void load();

private:
    QVector<QString> *hi, *hx, *pn, *tn, *cj;
};

#endif // LOADER_H
