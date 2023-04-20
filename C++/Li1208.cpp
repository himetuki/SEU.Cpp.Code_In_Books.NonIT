#include <iostream>
using namespace std;

class A
{
protected:
    int x;
public:
    void Set(int a) { x = a; }
    void Show() { cout << "x=" << x << '\n'; }
};

class B : public A
{
protected:
    int x;            					// x 成员与基类的成员x 同名 
public:
    void SetAx(int a) { A::x = a; } 	// C，访问的是基类A的x
    void SetBx(int a) { x = a; }    	// D，访问的是派生类B的x
    void Show() { cout << "x=" << x << endl; }
};
int main(void)
{
    B b;

    b.SetAx(1);
    b.SetBx(2);
    b.A::Show();              			// E，访问的是基类A的Show( )
    b.Show();                 			// F，访问的是派生类B的Show( )
    return 0;
}
