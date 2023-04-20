#include <iostream>
using namespace std;

class Point
{
    int x;
    const int y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) { }
    int fun();
    int fun() const;  			// 类中声明有关键字const 
};
int Point::fun()
{
    return x + y;
}
int Point::fun() const   		// 类外定义也必须有关键字const
{
    return x - y;
}
int main()
{
    Point p1(1, 8);
    const Point p2(1, 8);

    cout << p1.fun() << ',' ;	// p1调用的是第1个fun()函数
    cout << p2.fun() << endl;	// p2调用的是第2个fun()函数
    return 0;
}
