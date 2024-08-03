#ifndef POWER_H
#define POWER_H

#include <QObject>

class Power : public QObject
{
    Q_OBJECT
public:
    explicit Power(QObject *parent = nullptr);
protected:
    double a,b;
public slots:
    double field_processing();
    void field_formation(QString str, QString str1);
};


#endif // POWER_H
