#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) { }
    void Show() { cout << "Point(" << x << ',' << y << ")\n"; }
    int Getx()	{ return x; }
    int Gety()	{ return y; }
};

double dist(Point &p1, Point &p2)// 注意：此函数是非成员函数，求两点之间的距离 
{
    return sqrt((p1.Getx() - p2.Getx())*(p1.Getx() - p2.Getx())
               +(p1.Gety() - p2.Gety())*(p1.Gety() - p2.Gety()));
}

int main()
{
    Point p1, p2(1, 1);

    cout << dist(p1, p2) << endl;
    return 0;
}
