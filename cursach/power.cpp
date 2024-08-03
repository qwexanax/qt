#include "power.h"

Power::Power(QObject *parent) : QObject{parent}
{



    a = 0; b = 0; //задаём значения полей 0
}

double Power::field_processing(){
    double res = pow(a,2) - pow(b,2); //реализация метода
    return res; //функция возвращает значение res
}

void Power::field_formation(QString str, QString str1){
    a = str.toDouble(); //преобразовываем строки типа string в double
    b = str1.toDouble();
}
