#include <iostream>
#include <cmath>
using namespace std;

class  CRect  //定义长方形类
{
private:
    int left, top, right, bottom;
public:
    void setcoord(int, int, int, int);
    void getcoord(int *L, int *T, int *R, int *B)  //注意：形参为指针变量
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
    r1.getcoord(&a, &b, &c, &d);  	// 用指针做参数，带回多个结果
    cout << "left=" << a << '\t' << "top=" << b << endl;
    cout << "right=" << c << '\t' << "bottom=" << d << endl;
    r1.print();
    r2 = r1;      						// 对象可整体赋值
    r2.print();
    return 0;
}
