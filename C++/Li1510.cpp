//例15.10：使用重载函数模板实现求不同数据类型数组的最大值。源程序名为Li1510.cpp
#include <iostream>
using namespace std;

template  <typename T>  
T  Max(T* array, int size=0)
{
	T m = array[0];

	for(int i=1; i<size; i++)
  		if(m < array[i])
    		m = array[i];
	
	return  m;
}

//重载函数模板
template  <typename T>  
T  Max(T* array1, T* array2, int size=0)
{
	T  m = array1[0];

	if(m < array2[0])    
		m = array2[0];
	
	for(int i=1; i<size; i++)
	{
   		if(m < array1[i])  m = array1[i];
   		if(m < array2[i])  m = array2[i];
	}
	
	return  m;
}

int  main( )
{
	int  Array1[ ] = {1, 0, 32, 4, 5, 16, 7, 28, 9, 12};
	int  Array2[ ] = {11, 120, 31, 14, 52, 16, 77, 18, -9, 20};
	double  Array3[ ] = {1.2, 22.3, 3.4, 0.4, 5.6, 6.7, 17.8, 8.9, 7.9, 10.1};

	int     max1 = Max(Array1, 10);
	double  max2 = Max(Array3, 10);
	int     max3 = Max(Array1, Array2, 10);

	cout << "The maximum number in integer array1 is: " << max1 << endl;
    cout << "The maximum number in double floating array is: " << max2 << endl;
    cout << "The maximum number in two integer arrays is: " << max3 << endl;
	
	return 0;
}
