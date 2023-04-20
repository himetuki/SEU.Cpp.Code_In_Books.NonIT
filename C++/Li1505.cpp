//例15.5：使用函数模板进行平均成绩的计算。源程序名为Li1505.cpp
#include  <iostream>
using namespace std;

template  <typename T >     
T  average(float  a[], int  n) 
{    
	float  ave = 0;

	for(int i = 0; i < n; i++ )
		ave += a[i];
	
	return  ave/n;						
}

int  main( )
{
	float   score[] = {65, 70, 53, 90, 84.5, 99, 81, 72, 43.5, 77 };          
	int  aver;
	
	aver = average < int > (score, 10); 			//A
	cout << "平均成绩：" << aver << endl;
	
	return 0;
}

























