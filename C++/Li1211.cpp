#include <iostream>
using namespace std;
class A
{
public:
    A() { cout << "A"; }
    ~A() { cout << "~A"; }
};
class B
{
public:
    B() { cout << "B"; }
    ~B() { cout << "~B"; }
};
class C
{
public:
    C() { cout << "C"; }
    ~C() { cout << "~C"; }
};
class D
{
public:
    D() { cout << "D"; }
    ~D() { cout << "~D"; }
};
class E : virtual public B, public A, public D, virtual public C   // G 
{   // E��������ǿյ�
};
int main()
{
    E c;

    return 0;
}
