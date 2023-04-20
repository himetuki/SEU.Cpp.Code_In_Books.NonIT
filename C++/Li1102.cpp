#include <iostream>
using namespace std;

class Sample
{
    int a;
    static int b;                           	// 定义私有静态数据成员 
public:
    static int c;                      		// 定义公有静态数据成员 
    Sample(int x) { a = x; b += x; }
    static void disp(Sample s)            // A，定义静态成员函数 
    {
        cout << "a=" << s.a << ", b=" << b << endl;  // B
    }    							// 续前行，访问非静态数据成员和静态数据成员  
};

int Sample::b = 10; 				// C，初始化静态数据成员 
int Sample::c = 20; 				// D，初始化静态数据成员 

int main()
{
    Sample s1(2), s2(3);

    Sample::disp(s1);  		   	// E，可改写为s1.disp(s1);或s2.disp(s1);
    Sample::disp(s2);  		    	// F，可改写为s1.disp(s2);或s2.disp(s2);
    cout << "c=" << Sample::c << endl;	// G，Sample::c 可改写为 s1.c 或 s2.c
    return 0;
}
