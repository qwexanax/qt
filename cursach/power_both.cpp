#include "power_both.h"

Power_both::Power_both(Power *parent)//конструктор
    : Power{parent}
{

    x = 0; //задаём значенияе поля 0
}

double Power_both::data_adaptation(){
    double res = a * pow(x,2) - b;//реализация метода
    return res; //функция возвращает значение res
}

void Power_both::field_formation2(QString str, QString str1,QString str2){
    a = str.toDouble();   //преобразовываем строки типа string в double
    b = str1.toDouble();
    x = str2.toDouble();
}
