//例15.1：使用函数重载实现对多种数据类型求两个数据的最大值。源程序名为Li1501.cpp
#include <iostream>
using namespace std;

int max(int num1, int num2) //重载函数① 
{ 
	return num1 > num2 ? num1 : num2; 
} 

double max(double d1, double d2) //重载函数② 
{ 
	return d1 > d2 ? d1 : d2; 
} 

char max(char ch1, char ch2) //重载函数③ 
{ 
	return ch1 > ch2 ? ch1 : ch2; 
} 

int main( ) 
{ 
	int m1 = max(100, 200);    //A 
	double m2 = max(7.8, 5.1); //B 
	char m3 = max('T', 'M');   //C 

	cout << "The maxium of 100 and 200 is: " << m1 << endl; 
	cout << "The maxium of 7.8 and 5.1 is: " << m2 << endl; 
	cout << "The maxium of 'T' and 'M' is: " << m3 << endl; 
	
	return 0;
} 
