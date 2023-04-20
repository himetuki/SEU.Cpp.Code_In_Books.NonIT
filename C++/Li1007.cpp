#include <iostream>
using namespace std;

class  Date
{
    int Year, Month, Day;
public:
    Date(int y = 2000, int m = 1, int d = 1)//A，带参数，且所有参数都有默认值
    {
        Year = y; Month = m; Day = d;
        cout << "Constructor: ";
        ShowDate();
    }
    void ShowDate()
    {
        cout << Year << '.' << Month << '.' << Day << endl;
    }
    ~Date()
    {
        cout << "Destructor: ";
        ShowDate();
    }
};

Date d4(2016, 4, 4);      		//全局对象（静态的）

void fun()
{
    cout << "进入 fun( )函数!\n";

    static Date d2(2016, 2, 2);	//局部静态对象
    Date d3(2016, 3, 3);       	//局部动态对象

    cout << "退出 fun( )函数!\n";
}
int main()
{
    cout << "进入 main( )函数!\n";

    Date d1(2016, 1, 1);        	//局部动态对象

    fun();
    fun();
    cout << "退出 main( )函数!\n";
    return 0;
}
