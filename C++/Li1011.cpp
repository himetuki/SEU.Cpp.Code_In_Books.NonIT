#include <iostream>
using namespace std;

#include "point.h"

Point move(Point p, int xoffset, int yoffset)  // 普通函数，不是类的成员函数 
{
    int x = p.Getx() + xoffset, y = p.Gety() + yoffset;
    Point t(x, y);

    return t;									// A
}
int main()
{
    Point p1(6, 8), p2;

    p2 = move(p1, 2, 4);							// B
    p2 = p1;        								// C 
    return 0;
}
