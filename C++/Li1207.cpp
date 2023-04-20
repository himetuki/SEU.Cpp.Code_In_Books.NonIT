#include <iostream>
using namespace std;

class  A
{
protected:
    int x;
public:
    void Show() { cout << "x=" << x << '\n'; }
};

class  B
{
protected:
    int x;
public:
    void Show() { cout << "x=" << x << '\n'; }
};

class  C : public A, public B       //���м̳� A��B ��
{
    int y;
public:
    void SetAx(int a) { A::x = a; }
    void SetBx(int a) { B::x = a; }
    void Sety(int b) { y = b; }
    int Gety() { return y; }
};

class  D : public C                  //���м̳� C ��
{
    int z;
public:
    void Setz(int a) { z = a; }
    int Getz() { return z; }
};
int main(void)
{
    D d;

    d.SetAx(10);  d.SetBx(20);  d.Sety(30);  d.Setz(40);
    cout << "A";
    d.C::A::Show();                   		//E 
    cout << "B";
    d.C::B::Show();                   		//F
    cout << "y=" << d.Gety() << '\n';
    cout << "z=" << d.Getz() << '\n';
    return 0;
}
