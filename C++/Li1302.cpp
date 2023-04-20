#include <iostream>
using namespace std;

class Complex
{
	double Real, Image;
public:
	Complex(double r = 0, double i = 0)      		// A�У����캯��
	{
		Real = r; Image = i;
	}
	Complex operator+(const Complex &c);		// B�У����ض�Ԫ"�ӷ�"�����
	Complex operator+(double);            		// C�У����ض�Ԫ"�ӷ�"�����
	Complex operator-(const Complex &c);   		// ���ض�Ԫ"����"�����
	Complex operator-(double);             		// ���ض�Ԫ"����"�����
	Complex operator-(void);               		// D�У�����һԪ"����"�����
	Complex operator*(const Complex &c);   		// ���ض�Ԫ"�˷�"�����
	Complex operator/(const Complex &c);   		// ���ض�Ԫ"����"�����
	void Show()
	{
		cout << Real;
		if (Image>0)
			cout << '+' << Image << 'i';  			// �����������Ӧ��ʽ�������
		else
			if (Image<0) cout << Image << 'i';   	// ����Ǹ������Զ��������
		cout << endl;
	}
};
Complex Complex::operator +(const Complex &c)	// ���ض�Ԫ"�ӷ�"�����
{
	return Complex(Real + c.Real, Image + c.Image);	// ����һ����ʱ������Ϊ����ֵ
}
Complex Complex::operator+(double r)         	// ���ض�Ԫ"�ӷ�"�����
{
	return Complex(Real + r, Image);           	// ����һ����ʱ������Ϊ����ֵ
}
Complex Complex::operator-(const Complex &c)  	// ���ض�Ԫ"����"�����
{
	Complex t;

	t.Real = Real - c.Real;
	t.Image = Image - c.Image;
	return t;
}
Complex Complex::operator-(double r)      		// ���ض�Ԫ"����"�����
{
	Complex t;

	t.Real = Real - r;
	t.Image = Image;
	return t;
}
Complex Complex::operator-(void)           		// ����һԪ"����"�����
{
	return Complex(-Real, -Image);
}
Complex Complex::operator*(const Complex &c)  	// ���ض�Ԫ"�˷�"�����
{
	double r, i;

	r = Real*c.Real - Image*c.Image;
	i = Real*c.Image + Image*c.Real;
	return Complex(r, i);
}
Complex Complex::operator/(const Complex &c)  	// ���ض�Ԫ"����"�����
{
	double t, r, i;

	t = c.Real*c.Real + c.Image*c.Image;
	r = (Real*c.Real + Image * c.Image) / t;
	i = (Image*c.Real - Real*c.Image) / t;
	return Complex(r, i);
}
int main()
{
	Complex c1(2, 3), c2(4, -2), c3;

	cout << "c1="; c1.Show();
	cout << "c2="; c2.Show();
	c3 = 5.0;                        	// E
	cout << "c3="; c3.Show();
	c3 = c1 + c2;                       // F
	cout << "c1+c2="; c3.Show();
	c3 = c1 + 5;                       	// G 
	cout << "c1+5="; c3.Show();
	c3 = c1 - c2;
	cout << "c1-c2="; c3.Show();
	c3 = c1 - 5;
	cout << "c1-5="; c3.Show();
	c3 = -c1;                        	// H 
	cout << "-c1="; c3.Show();
	c3 = c1*c2;
	cout << "c1*c2="; c3.Show();
	c3 = c1 / c2;
	cout << "c1/c2="; c3.Show();
	c3 = (c1 + c2)*(c1 - c2)*c2 / c1;
	cout << "(c1+c2)*(c1-c2)*c2/c1="; c3.Show();
	return 0;
}
