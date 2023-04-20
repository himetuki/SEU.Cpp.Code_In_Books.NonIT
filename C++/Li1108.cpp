#include <iostream>
using namespace std;

class Point
{
    int x;			  	// 一般数据成员
    const int y;	  		// 常数据成员
public:
    Point(int a = 0, int b = 0) : x(a), y(b) { }

    int fun()         		// A，一般成员函数
    {
        x = 5;        		// 修改一般数据成员x，合法
        y = 6;        		// 修改常数据成员，	非法
        return x + y;   	// 读取x和y，		合法
    }
    int fun() const   	// B，常成员函数 
    {
        x = 5;        		// 修改一般数据成员x，非法
        y = 6;        		// 修改常数据成员，    非法
        return x + y;   	// 读取x和y，		合法
    }
};
