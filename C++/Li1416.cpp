#include <iostream>
using namespace std;

class Complex
{
	double Real, Image;
public:
	Complex(double r = 0, double i = 0)
	{
		Real = r; Image = i;
	}
	friend istream& operator>>(istream &, Complex &);	// ��Ԫ��������
	friend ostream& operator<<(ostream &, Complex &);	// ��Ԫ��������
};
istream& operator>>(istream &in, Complex &c)
{
	in >> c.Real >> c.Image;
	return in;
}
ostream& operator<<(ostream &out, Complex &c)
{
	out << c.Real;
	if (c.Image>0) 
		out << '+' << c.Image << 'i';	// �����������Ӧ��ʽ�������
	else 
		if (c.Image<0) 
			out << c.Image << 'i';		// ����Ǹ������Զ��������
	out << endl;
	return out;
}
int main()
{
	Complex c1(1, 2), c2;

	cout << c1;
	cout << "Please input c1 & c2:\n";
	cin >> c1 >> c2;                         // A
	cout << c1 << c2;                        // B
	return 0;
}
