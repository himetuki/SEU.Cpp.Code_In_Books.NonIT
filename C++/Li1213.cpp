#include <iostream>
#include <cmath>
using namespace std;

class Point
{
protected:
    int x, y;    //����x��yΪ������Ա����ʹ�ڹ����������п�ֱ�ӷ������� 
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

class Line : public Point                    			// ���м̳� 
{
protected:
    int x1, y1;
public:
    Line(int a, int b, int c, int d) : Point(a, b)	// ���û��๹�캯�� 
    {
        x1 = c; y1 = d;
    }
    double Length()
    {
        return sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
    }    // A�У�ֱ�ӷ��ʻ��ౣ����Աx��y 
    void Show()
    {
        Point::Show();                  				// ���ʻ����Ա����Show( ) 
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
