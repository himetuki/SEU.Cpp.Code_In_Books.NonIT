//例15.3：使用函数模板实现对多种数据类型求两个数据的最大值。源程序名为Li1503.cpp
#include  <iostream>
using namespace std;

template  <typename T>        	//定义函数模板的<模板形参表>
T  myMax(T  var1, T  var2)   	//定义函数模板的<函数定义>
{    
	return  var1 > var2 ? var1 : var2;	
}

int  main( )
{
    int     m1 = myMax(100, 200);          //A
    double  m2 = myMax(7.8, 5.1);          //B
    char    m3 = myMax('T', 'M');  		   //C

    cout << "The maxium of 100 and 200 is:  " << m1 << endl;
    cout << "The maxium of 7.8 and 5.1 is:  " << m2 << endl;
    cout << "The maxium of 'T' and 'M' is:  " << m3 << endl;
	
	return 0;
}

























