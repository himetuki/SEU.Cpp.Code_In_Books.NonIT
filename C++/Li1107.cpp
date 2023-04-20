#include <iostream>
using namespace std;

class B;     // 类的引用性说明

class A      // 类中默认访问权限是私有的
{
    int x;
    void Disp() { cout << "x=" << x << endl; }   // 私有成员函数 

    friend B;                               			// 将B类说明成A类的友元类
};

class B
{
public:
    void Set(int n)
    {
        A a;
        a.x = n;     //可访问A类对象的私有数据成员x
        a.Disp();    //可访问A类对象的私有成员函数Disp( )
    }
};

int main(void)
{
    B b;
    b.Set(3);
    return 0;
}
