#ifndef POWER_BOTH_H
#define POWER_BOTH_H

#include "power_both.h"
#include <QObject>

class Power_both : public Power
{
    Q_OBJECT
    double x;
public:
    explicit Power_both(Power *parent = nullptr);
public slots:
    double data_adaptation();
    void field_formation2(QString str,QString str1,QString str2);
signals:
};

#endif // POWER_BOTH_H
