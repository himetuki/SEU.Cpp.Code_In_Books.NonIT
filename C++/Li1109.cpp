#include <iostream>
using namespace std;

class Point
{
    int x;
    const int y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) { }
    int fun();
    int fun() const;  			// ���������йؼ���const 
};
int Point::fun()
{
    return x + y;
}
int Point::fun() const   		// ���ⶨ��Ҳ�����йؼ���const
{
    return x - y;
}
int main()
{
    Point p1(1, 8);
    const Point p2(1, 8);

    cout << p1.fun() << ',' ;	// p1���õ��ǵ�1��fun()����
    cout << p2.fun() << endl;	// p2���õ��ǵ�2��fun()����
    return 0;
}
