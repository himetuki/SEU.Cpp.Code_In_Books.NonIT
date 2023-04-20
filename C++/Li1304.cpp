#include <iostream>
using namespace std;

class Complex
{
	double Real, Image;
public:
	Complex(double r = 0, double i = 0)  { Real = r; Image = i; }
	void SetReal(double Real) { Complex::Real = Real; }
	void SetImage(double Image)	{ Complex::Image = Image; }
	double GetReal(){ return(Real); }
	double GetImage(){ return(Image); }
	void Show()
	{
		cout << Real;
		if (Image>0) cout << '+' << Image << 'i' << endl;    // 如果是正数，必须输出正号
		else if (Image<0) cout << Image << 'i' << endl;    // 如果是负数，自动输出负号
	}
};
Complex operator +(Complex &c1, Complex &c2)        // 二元运算
{													// 函数名为 operator + 的一个“普通”函数
	Complex t;

	t.SetReal(c1.GetReal() + c2.GetReal());
	t.SetImage(c1.GetImage() + c2.GetImage());
	return t;
}
int main()
{
	Complex c1(2, 3), c2(4, 8), c3;

	c3 = c1 + c2;
	c3.Show();
	return 0;
}
