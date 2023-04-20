#include <iostream>
using namespace std;

class Money
{
	int Yuan, Jiao; // 元、角
public:
	Money(int y = 0, int j = 0)
	{
		Yuan = y; Jiao = j;
	}
	Money(double d)
	{
		Yuan = int(d); Jiao = int((d - Yuan) * 10);
	}
	Money operator++();					//①用成员函数实现前置++
	Money operator++(int);					//②用成员函数实现后置++
	friend Money operator--(Money &m);		//③用友元函数实现前置--
	friend Money operator--(Money &m, int); //④用友元函数实现后置--
	void Show(char *s)
	{
		cout << s << ':' << Yuan << "," << Jiao << endl;
	}
};
Money Money::operator++()			//①用成员函数实现前置++
{
	Jiao++;
	if (Jiao >= 10)
	{
		Yuan += 1; Jiao -= 10;
	}
	return *this;
}
Money Money::operator++(int)		//②用成员函数实现后置++
{
	Money temp = *this;			    //保存对象原始的值

	Jiao++;
	if (Jiao >= 10)
	{
		Yuan += 1; Jiao -= 10;
	}
	return temp;					//返回对象原始的值
}
Money operator--(Money &m)			//③用友元函数实现前置--
{
	if (m.Jiao == 0)
	{
		m.Yuan -= 1; m.Jiao = 10;
	}
	m.Jiao--;
	return m;
}
Money operator--(Money &m, int)		//④用友元函数实现后置--
{
	Money temp = m;					//保存对象的原始值
	if (m.Jiao == 0)
	{
		m.Yuan -= 1;					// 借位
		m.Jiao = 10;
	}
	m.Jiao--;
	return temp;					 //返回对象原始的值
}
int main(void)
{
	Money m(15, 3), m1, m2, m3, m4;

	m.Show("m");
	m1 = ++m;						// 处理成：m1 = m.opetator++( ); 
	cout << "m1=++m;\n"; m1.Show("m1"); m.Show("m");
	m2 = m++;						// 处理成：m2 = m.opetator++(int);
	cout << "m2=m++;\n"; m2.Show("m2"); m.Show("m");
	m3 = --m;						// 处理成：m3 = opetator－－(m);
	cout << "m3=--m;\n"; m3.Show("m3"); m.Show("m");
	m4 = m--;						// 处理成：m4 = opetator－―(m, int );
	cout << "m4=m--;\n"; m4.Show("m4"); m.Show("m");
	Money m5(8.5);
	m5.Show("m5");
	return 0;
}
