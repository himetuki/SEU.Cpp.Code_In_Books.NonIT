#include <iostream.h>  //报错，新程序在下面，解决：将distance函数名改掉即可，改为 dist
#include <math.h>

class Point
{
	int x, y;
public:
	Point(int a=0, int b=0): x(a), y(b) { }  
	void Show( ) { cout<<"Point("<<x<<','<<y<<")\n"; }
	int Getx( )	{ return x; }
	int Gety( )	{ return y; }
	friend double distance(Point&, Point& );                // A
};

double distance(Point &p1, Point &p2 )
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));  // B
}

void main( )
{
	Point p1, p2(1,1);

	cout<<distance(p1,p2)<<endl;
}
--------------------------------------------------------
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) { }
    void Show() { cout << "Point(" << x << ',' << y << ")\n"; }
    int Getx() { return x; }
    int Gety() { return y; }
    friend double dist(Point&, Point&);                // A
};

double dist(Point &p1, Point &p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));//B
}

int main()
{
    Point p1, p2(1, 1);

    cout << dist(p1, p2) << endl;
    return 0;
}
