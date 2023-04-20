#include <iostream>
using namespace std;
class Point
{
protected:
    int x, y;                                             // ������Ա
public:
    Point(int a = 0, int b = 0) { x = a; y = b; }
    void Show()
    {
        cout << "point(" << x << ',' << y << ")\n";
    }
};

class Line : public Point                              // ���м̳�
{
protected:
    int x1, y1;
public:
    Line(int a, int b, int c, int d) : Point(a, b) //���û��๹�캯��
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
