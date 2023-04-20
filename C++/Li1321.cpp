#include <iostream>
using namespace std;

class Point
{
protected:
	double x, y;									// �������ֵ
public:
	Point(double a = 0, double b = 0) { x = a; y = b; }
	double Area() { return 0.0; }                   // ����1
};
class Rectangle : public Point
{
protected:
	double x1, y1;			//���������½ǵ������ֵ��������x, yΪ���Ͻ������
public:
	Rectangle(double a = 0, double b = 0, double c = 0, double d = 0) :Point(a, b)
	{
		x1 = c; y1 = d;
	}
	double Area(){ return (x - x1)*(y - y1); }           // ����2
};
class Circle : public Point
{
protected:
	double r; //�뾶��������x, yΪԲ�������
public:
	Circle(double a = 0, double b = 0, double c = 0) :Point(a, b)
	{
		r = c;
	}
	double Area() { return 3.14*r*r; }              // ����3
};
double CalcArea(Point &p)
{
	return(p.Area());                               // A  ��������ʱȷ�����ú���1
}
int main()
{
	Rectangle r(0, 0, 1, 1);
	Circle c(0, 0, 1);

	cout << CalcArea(r) << '\t';
	cout << CalcArea(c) << '\n';
	return 0;
}
