//��15.7��ʹ�ú���ģ����������е����ֵ��Դ������ΪLi1507.cpp
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
	
	int     max1=Max(Array1, 10); //����ģ������Max(int* array, int size) ģ�庯��
	double  max2=Max(Array2, 10); //����ģ������Max(double* array, int size) ģ�庯��

    cout << "The maximum number in integer array is: " << max1 << endl;
    cout << "The maximum number in double floating array is: " << max2 << endl;
	
	return 0;
}



















