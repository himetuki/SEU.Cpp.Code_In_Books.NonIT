#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    int x, y;
public:
    Point(int a = 0, int b = 0)	{ x = a; y = b; }
    void Setx(int a){ x = a; }
    void Sety(int a){ y = a; }
    int Getx(){ return x; }
    int Gety(){ return y; }
    void Show()
    {
        cout << "point(" << x << ',' << y << ")\n";
    }
};
class Line
{
    Point p1, p2;                            		// �����Ա
public:
    Line(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) // A
    { }
    double Length()
    {
        int x1, y1, x2, y2;

        x1 = p1.Getx(); y1 = p1.Gety();        // B�����ʶ����Աp1�ĳ�Ա
        x2 = p2.Getx(); y2 = p2.Gety();        // C�����ʶ����Աp2�ĳ�Ա
        return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    }
    void Show()
    {
        p1.Show();                				// D�����ʶ����Աp1�ĳ�Ա
        p2.Show();                				// E�����ʶ����Աp2�ĳ�Ա
        cout << "Length=" << Length() << endl;
    }
};
int main()
{
    Line  line(0, 0, 1, 1);

    line.Show();
    return 0;
}
