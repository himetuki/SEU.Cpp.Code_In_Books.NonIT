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
istream& operator>>(istream &in, Complex &c) //�ǳ�Ա����Ԫ����
{
	double r, i;

	in >> r >> i;
	c.SetReal(r);
	c.SetImage(i);
	return in;
}
ostream& operator<<(ostream &out, Complex &c) //�ǳ�Ա����Ԫ����
{
	double r, i;

	r = c.GetReal(); i = c.GetImage();
	out << r;
	if (i>0) out << '+' << i << 'i';      // �����������Ӧ��ʽ�������
	else if (i<0) out << i << 'i';      // ����Ǹ������Զ��������
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
