#include <iostream>
using namespace std;

#define PI 3.14159

class Point
{
protected:                                                               // A
    int x, y;
public:
    Point(int a = 0, int b = 0){ x = a; y = b; }
    void ShowPoint(){ cout << "Point:(" << x << ',' << y << ")\n"; }
    int Getx() { return x; }
    int Gety() { return y; }
    void Setxy(int a, int b){ x = a; y = b; }
};

class Radius
{
protected:                                                                // B
    int r;
public:
    Radius(int ra = 0){ r = ra; }
    void Setr(int ra){ r = ra; }
    int Getr()	{ return r; }
};

class Circle : public Point, public Radius                         // C
{
public:
    Circle(int x, int y, int ra) : Point(x, y), Radius(ra) { }  // D

    double Area() { return PI*r*r; }				                   // E

    void Move(int x_offset, int y_offset)
    {
        x += x_offset; y += y_offset;                                  // F
    }

    void ShowCircle()
    {
        ShowPoint();
        cout << "Radius: " << r << '\t';
        cout << "Area: " << Area() << endl;
    }
};
int main()
{
    Circle c(0, 0, 2); // 0,0表示圆心坐标的初值，2表示半径的初值

    c.ShowCircle();
    c.Move(2, 2);
    c.ShowCircle();
    c.Setxy(0, 0);    // H，重新设置圆心坐标
    c.Setr(1);         // 重新置半径值
    c.ShowCircle();
    return 0;
}
