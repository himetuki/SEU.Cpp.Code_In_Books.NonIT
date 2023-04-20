//��15.12������ģ��ʵ����15.11ͬ���Ĺ��ܡ�Դ������ΪLi1512.cpp
#include  <iostream>
using namespace std;

template <typename T>  
class maxElem     
{
	T *a;
	int size;
public:
	maxElem(T *array=NULL, int n=0)
	{
		size=n;
		if(size>0)
		{
			a = new T[size];
			for(int i=0; i<size; i++) a[i]=array[i];
		}
		else
			a=NULL;
	}
	T maxValue()
	{
		T max = a[0];
		for(int i=1; i<size; i++)
			if(max < a[i]) max = a[i];
		return  max;
	}
	~maxElem() { if(a) delete[]a; }
};

int  main( )
{
	int  Array1[10] = {1, 0, 32, 4, 5, 16, 7, 28, 9, 12};
	double  Array2[8] = {1.2, 22.3, 3.4, 0.4, 5.6, 6.7, 17.8, 8.9};

	maxElem <int>m1(Array1, 10);  //A�����������ʱ�������������͵�ʵ������ int 
	maxElem <double>m2(Array2, 8); //B�����������ʱ�������������͵�ʵ������ double 

    cout << "The maximum in integer array is: " << m1.maxValue() << endl;
    cout << "The maximum in doublearray is: " << m2.maxValue() << endl;
	
	return 0;
} 
