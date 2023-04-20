#include <iostream>
using namespace std;

class Money
{
	int Yuan, Jiao; // Ԫ����
public:
	Money(int y = 0, int j = 0)
	{
		Yuan = y; Jiao = j;
	}
	Money(double d)
	{
		Yuan = int(d); Jiao = int((d - Yuan) * 10);
	}
	Money operator++();					//���ó�Ա����ʵ��ǰ��++
	Money operator++(int);					//���ó�Ա����ʵ�ֺ���++
	friend Money operator--(Money &m);		//������Ԫ����ʵ��ǰ��--
	friend Money operator--(Money &m, int); //������Ԫ����ʵ�ֺ���--
	void Show(char *s)
	{
		cout << s << ':' << Yuan << "," << Jiao << endl;
	}
};
Money Money::operator++()			//���ó�Ա����ʵ��ǰ��++
{
	Jiao++;
	if (Jiao >= 10)
	{
		Yuan += 1; Jiao -= 10;
	}
	return *this;
}
Money Money::operator++(int)		//���ó�Ա����ʵ�ֺ���++
{
	Money temp = *this;			    //�������ԭʼ��ֵ

	Jiao++;
	if (Jiao >= 10)
	{
		Yuan += 1; Jiao -= 10;
	}
	return temp;					//���ض���ԭʼ��ֵ
}
Money operator--(Money &m)			//������Ԫ����ʵ��ǰ��--
{
	if (m.Jiao == 0)
	{
		m.Yuan -= 1; m.Jiao = 10;
	}
	m.Jiao--;
	return m;
}
Money operator--(Money &m, int)		//������Ԫ����ʵ�ֺ���--
{
	Money temp = m;					//��������ԭʼֵ
	if (m.Jiao == 0)
	{
		m.Yuan -= 1;					// ��λ
		m.Jiao = 10;
	}
	m.Jiao--;
	return temp;					 //���ض���ԭʼ��ֵ
}
int main(void)
{
	Money m(15, 3), m1, m2, m3, m4;

	m.Show("m");
	m1 = ++m;						// ����ɣ�m1 = m.opetator++( ); 
	cout << "m1=++m;\n"; m1.Show("m1"); m.Show("m");
	m2 = m++;						// ����ɣ�m2 = m.opetator++(int);
	cout << "m2=m++;\n"; m2.Show("m2"); m.Show("m");
	m3 = --m;						// ����ɣ�m3 = opetator����(m);
	cout << "m3=--m;\n"; m3.Show("m3"); m.Show("m");
	m4 = m--;						// ����ɣ�m4 = opetator���D(m, int );
	cout << "m4=m--;\n"; m4.Show("m4"); m.Show("m");
	Money m5(8.5);
	m5.Show("m5");
	return 0;
}
