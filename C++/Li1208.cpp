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
    int x;            					// x ��Ա�����ĳ�Աx ͬ�� 
public:
    void SetAx(int a) { A::x = a; } 	// C�����ʵ��ǻ���A��x
    void SetBx(int a) { x = a; }    	// D�����ʵ���������B��x
    void Show() { cout << "x=" << x << endl; }
};
int main(void)
{
    B b;

    b.SetAx(1);
    b.SetBx(2);
    b.A::Show();              			// E�����ʵ��ǻ���A��Show( )
    b.Show();                 			// F�����ʵ���������B��Show( )
    return 0;
}
