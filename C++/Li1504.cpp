//例15.4：使用函数模板进行数据类型转换。源程序名为Li1504.cpp
#include  <iostream>
using namespace std;

template  <typename T, typename T1>  
T  cast(T1  x) 		
{    
	return  x;						
}

int  main( )
{
	int    a = 10;          
	float  b;
	
	b = cast <float, int> (a); 	//A
	cout << b << endl;
	
	return 0;
}













