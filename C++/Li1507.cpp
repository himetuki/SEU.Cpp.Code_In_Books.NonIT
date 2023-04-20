//例15.7：使用函数模板计算数组中的最大值。源程序名为Li1507.cpp
#include  <iostream>
using namespace std;

template  < typename T >
T  Max(T* array, int size=0)
{
    T max = array[0];
    
    for(int i=1; i<size; i++)
       if(max < array[i]) 
			max = array[i];
    
	return  max;
}

int  main( )
{
	int     Array1[ ] = {1, 0, 32, 4, 5, 16, 7, 28, 9, 12};
	double  Array2[ ] = {1.2, 22.3, 3.4, 0.4, 5.6, 6.7, 17.8, 8.9, 7.9, 10.1};
	
	int     max1=Max(Array1, 10); //函数模板生成Max(int* array, int size) 模板函数
	double  max2=Max(Array2, 10); //函数模板生成Max(double* array, int size) 模板函数

    cout << "The maximum number in integer array is: " << max1 << endl;
    cout << "The maximum number in double floating array is: " << max2 << endl;
	
	return 0;
}



















