#include <iostream>
#include <cmath>
using namespace std;

class  CRect  //���峤������
{
private:
    int left, top, right, bottom;
public:
    void setcoord(int, int, int, int);
    void getcoord(int *L, int *T, int *R, int *B)  //ע�⣺�β�Ϊָ�����
    {
        *L = left; *T = top; *R = right; *B = bottom;
    }
    void print(void)
    {
        cout << "Area = " << abs(right - left)*abs(bottom - top) << endl;
    }
};

void CRect::setcoord(int L, int T, int R, int B)
{
    left = L;  top = T;  right = R;  bottom = B;
}

int main(void)
{
    CRect r1, r2;
    int a, b, c, d;

    r1.setcoord(100, 300, 50, 200);
    r1.getcoord(&a, &b, &c, &d);  	// ��ָ�������������ض�����
    cout << "left=" << a << '\t' << "top=" << b << endl;
    cout << "right=" << c << '\t' << "bottom=" << d << endl;
    r1.print();
    r2 = r1;      						// ��������帳ֵ
    r2.print();
    return 0;
}
