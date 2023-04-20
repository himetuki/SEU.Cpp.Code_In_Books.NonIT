#include <iostream>
using namespace std;

class Complex
{
	double Real, Image;
public:
	Complex(double r = 0, double i = 0)    // 构造函数
	{
		Real = r; Image = i;
	}
	Complex(Complex &c)                // 拷贝构造函数
	{
		Real = c.Real; Image = c.Image;
		cout << "Call copy " << Real << ' ' << Image << "\n";
	}
	Complex operator=(const Complex &c) // 赋值运算符重载函数
	{
		Real = c.Real;
		Image = c.Image;
		cout << "Call = " << Real << ' ' << Image << "\n";
		return *this;                  //A   初始化内存临时对象 
	}
	void Show()
	{
		cout << Real;
		if (Image>0) cout << '+' << Image << 'i'; //如果是正数，必须输出正号
		else if (Image<0) cout << Image << 'i'; //如果是负数，自动输出负号
		cout << endl;
	}
};

int main()
{
	Complex c1(2, 3), c2(4, -2);
	Complex c3 = c1;         //B 调用拷贝构造函数，此句等价于Complex c3(c1);

	cout << "Section1" << endl;
	c1 = c2;                 //C 调用赋值运算符重载函数
	cout << "Section2" << endl;
	c1.Show();
	c3.Show();
	return 0;
}
