#include <iostream>
using namespace std;

class Complex
{

	double Real, Image;
public:
	Complex(double r = 0, double i = 0) : Real(r), Image(i) { }

	operator double()	  //A  ����ת����������Complex����ת����double����
	{
		return Real;
	}
};
int main()
{
	Complex c(3, 2);
	double x;

	x = c;                   // B 
	cout << "x=" << x << endl;
	return 0;
}
