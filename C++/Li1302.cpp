#include <iostream>
using namespace std;

class Complex
{
	double Real, Image;
public:
	Complex(double r = 0, double i = 0)      		// A行，构造函数
	{
		Real = r; Image = i;
	}
	Complex operator+(const Complex &c);		// B行，重载二元"加法"运算符
	Complex operator+(double);            		// C行，重载二元"加法"运算符
	Complex operator-(const Complex &c);   		// 重载二元"减法"运算符
	Complex operator-(double);             		// 重载二元"减法"运算符
	Complex operator-(void);               		// D行，重载一元"负号"运算符
	Complex operator*(const Complex &c);   		// 重载二元"乘法"运算符
	Complex operator/(const Complex &c);   		// 重载二元"除法"运算符
	void Show()
	{
		cout << Real;
		if (Image>0)
			cout << '+' << Image << 'i';  			// 如果是正数，应显式输出正号
		else
			if (Image<0) cout << Image << 'i';   	// 如果是负数，自动输出负号
		cout << endl;
	}
};
Complex Complex::operator +(const Complex &c)	// 重载二元"加法"运算符
{
	return Complex(Real + c.Real, Image + c.Image);	// 构造一个临时对象作为返回值
}
Complex Complex::operator+(double r)         	// 重载二元"加法"运算符
{
	return Complex(Real + r, Image);           	// 构造一个临时对象作为返回值
}
Complex Complex::operator-(const Complex &c)  	// 重载二元"减法"运算符
{
	Complex t;

	t.Real = Real - c.Real;
	t.Image = Image - c.Image;
	return t;
}
Complex Complex::operator-(double r)      		// 重载二元"减法"运算符
{
	Complex t;

	t.Real = Real - r;
	t.Image = Image;
	return t;
}
Complex Complex::operator-(void)           		// 重载一元"负号"运算符
{
	return Complex(-Real, -Image);
}
Complex Complex::operator*(const Complex &c)  	// 重载二元"乘法"运算符
{
	double r, i;

	r = Real*c.Real - Image*c.Image;
	i = Real*c.Image + Image*c.Real;
	return Complex(r, i);
}
Complex Complex::operator/(const Complex &c)  	// 重载二元"除法"运算符
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
