#include <iostream>
#include <cmath>
using namespace std;

class Point
{
protected:
    int x, y;    //定义x、y为保护成员，以使在公有派生类中可直接访问它们 
public:
    Point(int a = 0, int b = 0)    { x = a; y = b; }
    void Setx(int a) { x = a; }
    void Sety(int a) { y = a; }
    int Getx() { return x; }
    int Gety() { return y; }
    void Show()
    {
        cout << "point(" << x << ',' << y << ")\n";
    }
};

class Line : public Point                    			// 公有继承 
{
protected:
    int x1, y1;
public:
    Line(int a, int b, int c, int d) : Point(a, b)	// 调用基类构造函数 
    {
        x1 = c; y1 = d;
    }
    double Length()
    {
        return sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
    }    // A行，直接访问基类保护成员x、y 
    void Show()
    {
        Point::Show();                  				// 访问基类成员函数Show( ) 
        cout << "point(" << x1 << ',' << y1 << ")\n";
        cout << "Length=" << Length() << endl;
    }
};
int main()
{
    Line  line(0, 0, 1, 1);

    line.Show();
    return 0;
}
