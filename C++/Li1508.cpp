//例15.8：使用函数模板求不同数据类型数据的最大值。源程序名为Li1508.cpp
#include  <iostream>
using namespace std;

template  < typename T1, typename T2>  
T1  max(T1 var1, T2 var2)
{
	return  var1 > var2 ? var1 : var2;
}

int  main( )
{
	int  m1 = max(30,7.56);     //A，函数模板被解释成max(int, double) 模板函数
	int  m2 = max(70, 'k');     //B，函数模板被解释成max(int, char) 模板函数
	int  m3 = max(100,300);     //C，函数模板被解释成max(int, int) 模板函数

	cout << "The maxium of 30 and 7.56 is: " << m1 << endl;
	cout << "The maxium of 70 and 'k' is: " << m2 << endl;
	cout << "The maxium of 100 and 300 is: " << m3 << endl;
	
	return 0;
} 








