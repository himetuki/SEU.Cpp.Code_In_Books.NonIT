#include <iostream>
using namespace std;

class N;     				 // A，类N的引用性说明

class M
{
    int a, b;
public:
    M(int x, int y) { a = x; b = y; }
    void Print(){ cout << "a=" << a << '\t' << "b=" << b << endl; }

    void Setab(N &); 	// B，Setab()是M类的成员函数，其参数是N类对象的引用  
};

class N
{
    int c, d;
public:
    N(int x, int y) { c = x; d = y; }
    void Print() { cout << "c=" << c << '\t' << "d=" << d << endl; }

    friend void M::Setab(N&);	// C，将类M的成员函数Setab()说明成本类的友元函数
};

void  M::Setab(N &obj)			// 类M的成员函数Setab( )是类N的友元函数，
{
    a = obj.c;  				// D，因此在Setab( )中可直接访问类N的私有成员。
    b = obj.d;
}
int main( )
{
    M m(25, 40);
    N n(55, 66);

    cout << "m: "; m.Print();
    cout << "n: "; n.Print();
    m.Setab(n);
    cout << "m: "; m.Print();
    return 0;
}
