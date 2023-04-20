#include <iostream>
using namespace std;

class Point
{
protected:
	double x, y;											// 点的坐标值
public:
	Point(double a = 0, double b = 0){ x = a; y = b; }
	virtual double Area(){ return 0.0; }					// 虚函数1
};
class Rectangle :public Point                        // 定义长方形类，继承点类
{
protected:
	double x1, y1;        // 长方形右下角点的坐标值，基类中x, y为左上角坐标点
public:
	Rectangle(double a = 0, double b = 0, double c = 0, double d = 0) :Point(a, b)
	{
		x1 = c; y1 = d;
	}
	virtual double Area(){ return (x - x1)*(y - y1); }			// 虚函数2
};
class Circle :public Point
{
protected:
	double r;												// 半径，基类中x, y为圆心坐标点
public:
	Circle(double a = 0, double b = 0, double c = 0) :Point(a, b)
	{
		r = c;
	}
	virtual double Area(){ return 3.14*r*r; }				// 虚函数3
};
double CalcArea(Point &p)
{
	return(p.Area());
}									// A 
int main()
{
	Point p(1, 2);
	Rectangle r(0, 0, 1, 1);
	Circle c(0, 0, 1);

	cout << CalcArea(p) << '\t' << CalcArea(r) << '\t' << CalcArea(c) << '\n';
	return 0;
}
------------------------------------------------------

// ……                       // 类的定义部分一样，在此省略

double CalcArea(Point *p)     // 形参是基类对象的指针
{
	return(p->Area());       //通过指针调用成员函数
}
int main()
{
	Point p(1, 2);
	Rectangle r(0, 0, 1, 1);
	Circle c(0, 0, 1);

	cout << CalcArea(&p) << '\t' << CalcArea(&r) << '\t' << CalcArea(&c) << '\n';  // 实参是指针
	return 0;
}
