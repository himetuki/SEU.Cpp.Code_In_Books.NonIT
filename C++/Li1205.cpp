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

class C : public A, public B //���м̳�A��B
{
    int  y;
public:
    void Setx(int a) { x = a; }        //D�����ڷ���x���ֶ�����
    void Sety(int b) { y = b; }
    int Gety(){ return y; }
};
int main()
{
    C c;

    c.Setx(35);
    c.Sety(300);
    c.Show();                   		//E���������Show( )���ֶ�����
    return 0;
}
