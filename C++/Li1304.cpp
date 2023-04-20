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
		if (Image>0) cout << '+' << Image << 'i' << endl;    // ����������������������
		else if (Image<0) cout << Image << 'i' << endl;    // ����Ǹ������Զ��������
	}
};
Complex operator +(Complex &c1, Complex &c2)        // ��Ԫ����
{													// ������Ϊ operator + ��һ������ͨ������
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
