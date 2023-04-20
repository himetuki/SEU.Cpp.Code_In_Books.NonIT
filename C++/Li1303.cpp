#include <iostream>
using namespace std;

class Complex
{
    double Real, Image;
public:
    Complex(double r = 0, double i = 0)       	                          //A 
    {
        Real = r; Image = i;
    }
    friend Complex operator+(const Complex &c1, const Complex &c2);   // B 
    friend Complex operator+(const Complex &c, double r);               // C 
    friend Complex operator-(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c, double r);
    friend Complex operator-(const Complex &c);                           // D 
    friend Complex operator*(const Complex &c1, const Complex &c2);
    friend Complex operator/(const Complex &c1, const Complex &c2);
    void Show()
    {
        cout << Real;
        if (Image>0) cout << '+' << Image << 'i';  //����������������������
        else if (Image<0) cout << Image << 'i';    //����Ǹ������Զ��������
        cout << endl;
    }
};
Complex operator +(const Complex &c1, const Complex &c2)// ���ض�Ԫ"�ӷ�" 
{
    return Complex(c1.Real + c2.Real, c1.Image + c2.Image);
}

Complex operator+(const Complex &c, double r)              // ���ض�Ԫ"�ӷ�" 
{
    return Complex(c.Real + r, c.Image);
}

Complex operator-(const Complex &c1, const Complex &c2) // ���ض�Ԫ"����" 
{
    Complex t;

    t.Real = c1.Real - c2.Real;
    t.Image = c1.Image - c2.Image;
    return t;
}
Complex operator-(const Complex &c, double r)             // ���ض�Ԫ"����" 
{
    Complex t;

    t.Real = c.Real - r;
    t.Image = c.Image;
    return t;
}
Complex operator-(const Complex &c)                     // ����һԪ"����"�����
{
    return Complex(-c.Real, -c.Image);
}
Complex operator*(const Complex &c1, const Complex &c2) // ���ض�Ԫ"�˷�" 
{
    double r, i;

    r = c1.Real*c2.Real - c1.Image*c2.Image;
    i = c1.Real*c2.Image + c1.Image*c2.Real;
    return Complex(r, i);
}
Complex operator/(const Complex &c1, const Complex &c2) // ���ض�Ԫ"����" 
{
    double t, r, i;

    t = c2.Real*c2.Real + c2.Image*c2.Image;
    r = (c1.Real*c2.Real + c1.Image * c2.Image) / t;
    i = (c1.Image*c2.Real - c1.Real*c2.Image) / t;
    return Complex(r, i);
}
int main()
{
    Complex c1(2, 3), c2(4, -2), c3;

    cout << "c1="; c1.Show();
    cout << "c2="; c2.Show();
    c3 = 5.0;                           	                                      // E
    cout << "c3="; c3.Show();
    c3 = c1 + c2;                                                              // F
    cout << "c1+c2="; c3.Show();
    c3 = c1 + 5;                                                               // G 
    cout << "c1+5="; c3.Show();
    c3 = c1 - c2;
    cout << "c1-c2="; c3.Show();
    c3 = c1 - 5;
    cout << "c1-5="; c3.Show();
    c3 = -c1;                                                                   //H 
    cout << "-c1="; c3.Show();
    c3 = c1*c2;
    cout << "c1*c2="; c3.Show();
    c3 = c1 / c2;
    cout << "c1/c2="; c3.Show();
    c3 = (c1 + c2)*(c1 - c2)*c2 / c1;
    cout << "(c1+c2)*(c1-c2)*c2/c1="; c3.Show();
    return 0;
}
