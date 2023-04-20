//例15.9：使用重载模板函数实现求多种数据类型数据比较的最大值。源程序名为Li1509.cpp
#include  <iostream>
#include  <cstring>
using namespace std;

template  <typename T>  
T  myMax(T var1, T var2)  			//函数模板
{
	return  var1 > var2 ? var1 : var2;
}

char*  myMax(const char* str1, const char* str2)	//A，重载模板函数
{
	if(strcmp(str1,str2)>=0)
		return  (char*)str1;
	else
		return  (char*)str2;
}

int  main( )
{
    int     m1 = myMax(100, 200);  //函数模板生成myMax(int, int)模板函数
    double  m2 = myMax(7.8, 5.1); //函数模板生成myMax(double, double)模板函数
    char*   m3 = myMax("Mary","Kate"); //调用重载模板函数myMax(char*, char*) 

    cout << "The maximum of 100 and 200 is:  " << m1 << endl;
    cout << "The maximum of 7.8 and 5.1 is:  " << m2 << endl;
    cout << "The maximum of \"Mary\" and \"Kate\" is:  " << m3 << endl;
	
	return 0;
}




