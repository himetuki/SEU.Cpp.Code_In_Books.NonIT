#include <iostream>
using namespace std;

class Complex
{
	double Real, Image;
public:
	Complex(double r = 0, double i = 0) { Real = r; Image = i; }

	void operator+=(const Complex &c)       // ����ֵΪvoid��
	{
		Real += c.Real;
		Image += c.Image;
	}
	void Show()
	{
		cout << Real;
		if (Image>0) cout << '+' << Image << 'i';  // ����������������������
		else if (Image<0) cout << Image << 'i';  // ����Ǹ������Զ��������
		cout << endl;
	}
};
int main()
{
	Complex c1(2, 3), c2(4, -2);

	cout << "c1="; c1.Show();
	cout << "c2="; c2.Show();
	c1 += c2;                             // A
	cout << "c1+=c2;c1="; c1.Show();
	return 0;
}
---------------------------------------------------
��д����
---------------------------------------------------
	Complex operator+=(const Complex &c) // ����ֵΪ�������͵Ķ���
	{
		Real += c.Real;
		Image += c.Image;
		return *this;
	}



