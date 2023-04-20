#include <iostream>
using namespace std;

#define PI 3.14159

class Point 									// ����"��"��
{
    int x, y;								// "��"������
public:
    int z;
    Point(int a = 0, int b = 0) : x(a), y(b) { }
    int Getx() {  return x;  }
    int Gety() {  return y;  }
    void Setxy(int a, int b) { x = a; y = b; }
    void ShowPoint() { cout << "Point:(" << x << ',' << y << ")\n"; }
};

class Circle : public Point					// A������"Բ"��
{
    int r; 									//"Բ"�İ뾶 
public:
    Circle(int x, int y, int ra) : Point(x, y)	// B
    {
        r = ra;
    }
    void Setr(int ra) { r = ra; }			// ����Բ�İ뾶
    double Area() { return PI*r*r; }			// ��Բ�����

    void Move(int x_offset, int y_offset)	// ��Բ������ƽ��
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
    Circle c(0, 0, 2); // 0,0��ʾԲ������ĳ�ֵ��2��ʾ�뾶�ĳ�ֵ

    c.ShowCircle();
    c.Move(2, 2);
    c.ShowCircle();
    c.Setxy(0, 0);    // H����������Բ������
    c.Setr(1);         // �����ð뾶ֵ
    c.ShowCircle();
    return 0;
}
