#include <iostream>
using namespace std;

class A
{
public:
	virtual void fun1()               // D  Ðéº¯Êý 
	{
		cout << "A::fun1" << '\t';
		fun2();
	}
	void fun2()
	{
		cout << "A::fun2" << '\t';
		fun3();                       //E  
	}
	virtual void fun3()               //F  Ðéº¯Êý
	{
		cout << "A::fun3" << '\t';
		fun4();
	}
	void fun4()
	{
		cout << "A::fun4" << '\n';
	}
};
class B : public A
{
public:
	void fun3()
	{
		cout << "B::fun3" << '\t';
		fun4();
	}
	void fun4()
	{
		cout << "B::fun4" << '\n';
	}
};
int main()
{
	A  a;
	B  b;

	a.fun1();
	b.fun1();							// G
	return 0;
}
