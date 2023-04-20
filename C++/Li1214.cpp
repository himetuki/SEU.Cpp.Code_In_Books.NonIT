#include <iostream>
using namespace std;
class Point
{
protected:
    int x, y;                                             // 保护成员
public:
    Point(int a = 0, int b = 0) { x = a; y = b; }
    void Show()
    {
        cout << "point(" << x << ',' << y << ")\n";
    }
};

class Line : public Point                              // 公有继承
{
protected:
    int x1, y1;
public:
    Line(int a, int b, int c, int d) : Point(a, b) //调用基类构造函数
    {
        x1 = c; y1 = d;
    }
};

int main()
{
    Line line(2, 2, 6, 6);
    Point p;

    p = line;              // A
    p.Show();
    return 0;
}
