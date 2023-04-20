#include <iostream>
using namespace std;

class A
{
protected:
    int  x;
public:
    void Show(){ cout << "x=" << x << '\n'; }
    A(int a = 0){ x = a; }
};

class B
{
protected:
    int  x;
public:
    void Show(){ cout << "x=" << x << '\n'; }
    B(int a = 0){ x = a; }
};

class C : public A, public B //公有继承A和B
{
    int  y;
public:
    void Setx(int a) { x = a; }        //D，类内访问x出现二义性
    void Sety(int b) { y = b; }
    int Gety(){ return y; }
};
int main()
{
    C c;

    c.Setx(35);
    c.Sety(300);
    c.Show();                   		//E，类外访问Show( )出现二义性
    return 0;
}
