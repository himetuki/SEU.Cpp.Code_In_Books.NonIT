#include <iostream>
using namespace std;

#define PI 3.14159

class Point 									// 定义"点"类
{
    int x, y;								// "点"的坐标
public:
    int z;
    Point(int a = 0, int b = 0) : x(a), y(b) { }
    int Getx() {  return x;  }
    int Gety() {  return y;  }
    void Setxy(int a, int b) { x = a; y = b; }
    void ShowPoint() { cout << "Point:(" << x << ',' << y << ")\n"; }
};

class Circle : public Point					// A，定义"圆"类
{
    int r; 									//"圆"的半径 
public:
    Circle(int x, int y, int ra) : Point(x, y)	// B
    {
        r = ra;
    }
    void Setr(int ra) { r = ra; }			// 设置圆的半径
    double Area() { return PI*r*r; }			// 求圆的面积

    void Move(int x_offset, int y_offset)	// 将圆心坐标平移
    {
        int x1 = Getx();						// C
        int y1 = Gety(); 						// D

        x1 += x_offset;  y1 += y_offset;
        Setxy(x1, y1); 						// E
    }
    void ShowCircle()
    {
        ShowPoint();             				// F
        cout << "Radius: " << r << '\t';
        cout << "Area: " << Area() << endl;	// G
    }
    friend void fun();
};

void fun()
{
    Circle c(1, 1, 1);
    c.z;
}

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
