#include <iostream>
#include <memory>

using namespace std;

class Ph
{


public:
    int i;
    int r;
    int p;
  
   
    


    void seti(int valueI) {
        i = valueI;

    }

    void setr(int valueR) {

        r = valueR;
    }
    


};

class Dop : public Ph {
public:
    int t;
    int po;
    
    void show2();
   
    void setrr(int valueRR) {
        t = valueRR;

    }

    Dop(int b, int c, int d) : Ph()  {
        seti(b);
        setr(c);
        setrr(d);
        
    }
};
void Dop::show2()
{
    int p = i * i * r;
    cout << "Сила тока = " << i << endl;
    cout << "Сопротивление = " << r << endl;
    cout << "Мощность = " << p << endl;
    int po = p + i * i * t;
    cout << "Сопротивление второго резистора = " << t << endl;
    cout << "Мощность обоих = " << po << endl;
}
int main()
{
    setlocale(LC_ALL, "ru");

    int b;
    int c;
    int d;
    cout << "Введите силу тока" << endl;
    
    while (!(cin >> b) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input error! Retry input" << endl;
    }
    cout << "Введите сопротивление" << endl;
    
    while (!(cin >> c) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input error! Retry input" << endl;
    }
    cout << "Сопротивление второго резистора" << endl;
    
    while (!(cin >> d) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input error! Retry input" << endl;
    }
   
    Dop e(b, c, d);
    e.seti(b);
    e.setr(c);
    e.setrr(d);
    
    e.show2();
    return 0;
}
   


   
