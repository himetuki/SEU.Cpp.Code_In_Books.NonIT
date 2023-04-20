#include <iostream>
using namespace std;

class Complex
{
	double Real, Image;
public:
	Complex(double r = 0, double i = 0)	{ Real = r; Image = i; }
	void SetReal(double r)	{ Real = r; }
	void SetImage(double r) { Image = r; }
	double GetReal() { return Real; }
	double GetImage() { return Image; }
};
istream& operator>>(istream &in, Complex &c) //非成员非友元函数
{
	double r, i;

	in >> r >> i;
	c.SetReal(r);
	c.SetImage(i);
	return in;
}
ostream& operator<<(ostream &out, Complex &c) //非成员非友元函数
{
	double r, i;

	r = c.GetReal(); i = c.GetImage();
	out << r;
	if (i>0) out << '+' << i << 'i';      // 如果是正数，应显式输出正号
	else if (i<0) out << i << 'i';      // 如果是负数，自动输出负号
	out << endl;
	return out;
}
int main()
{
	Complex c1(1, 2), c2;

	cout << c1;
	cout << "Please input c1 & c2:\n";
	cin >> c1 >> c2;
	cout << c1 << c2;
	return 0;
}
