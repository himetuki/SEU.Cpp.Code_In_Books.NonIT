#include <iostream>
using namespace std;

class Point
{
protected:
	double x, y;									// 点的坐标值
public:
	Point(double a = 0, double b = 0) { x = a; y = b; }
	double Area() { return 0.0; }                   // 函数1
};
class Rectangle : public Point
{
protected:
	double x1, y1;			//长方形右下角点的坐标值，基类中x, y为左上角坐标点
public:
	Rectangle(double a = 0, double b = 0, double c = 0, double d = 0) :Point(a, b)
	{
		x1 = c; y1 = d;
	}
	double Area(){ return (x - x1)*(y - y1); }           // 函数2
};
class Circle : public Point
{
protected:
	double r; //半径，基类中x, y为圆心坐标点
public:
	Circle(double a = 0, double b = 0, double c = 0) :Point(a, b)
	{
		r = c;
	}
	double Area() { return 3.14*r*r; }              // 函数3
};
double CalcArea(Point &p)
{
	return(p.Area());                               // A  编译连接时确定调用函数1
}
int main()
{
	Rectangle r(0, 0, 1, 1);
	Circle c(0, 0, 1);

	cout << CalcArea(r) << '\t';
	cout << CalcArea(c) << '\n';
	return 0;
}
