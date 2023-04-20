#include <iostream>
using namespace std;

class Complex
{
	double Real, Image;
public:
	Complex(double r = 0, double i = 0)    // ���캯��
	{
		Real = r; Image = i;
	}
	Complex(Complex &c)                // �������캯��
	{
		Real = c.Real; Image = c.Image;
		cout << "Call copy " << Real << ' ' << Image << "\n";
	}
	Complex operator=(const Complex &c) // ��ֵ��������غ���
	{
		Real = c.Real;
		Image = c.Image;
		cout << "Call = " << Real << ' ' << Image << "\n";
		return *this;                  //A   ��ʼ���ڴ���ʱ���� 
	}
	void Show()
	{
		cout << Real;
		if (Image>0) cout << '+' << Image << 'i'; //����������������������
		else if (Image<0) cout << Image << 'i'; //����Ǹ������Զ��������
		cout << endl;
	}
};

int main()
{
	Complex c1(2, 3), c2(4, -2);
	Complex c3 = c1;         //B ���ÿ������캯�����˾�ȼ���Complex c3(c1);

	cout << "Section1" << endl;
	c1 = c2;                 //C ���ø�ֵ��������غ���
	cout << "Section2" << endl;
	c1.Show();
	c3.Show();
	return 0;
}
