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

class C : public A, public B              //���м̳�A��B
{
    int  y;
public:
    void SetAx(int a) { A::x = a; }         //D1��ע����������ν��������
    void SetBx(int a) { B::x = a; }         //D2
    void Sety(int b) { y = b; }
    int Gety(){ return y; }
};

int main()
{
    C c;

    c.SetAx(35);
    c.SetBx(45);
    c.Sety(300);
    cout << "A::"; c.A::Show();           //E1��ע����������ν��������
    cout << "B::"; c.B::Show();           //E2
    cout << "y=" << c.Gety() << endl;
    return 0;
}
