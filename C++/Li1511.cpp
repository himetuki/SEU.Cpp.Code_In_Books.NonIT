//��15.11���������ṹ��ͬ���࣬�ֱ�ʵ�ֲ�ͬ������������Ĵ���Դ������ΪLi1511.cpp
#include  <iostream>
using namespace std;

class maxInt           // ��һ����̬�������������Ԫ�ص����ֵ
{
	int *a;
	int size;
public:
	maxInt(int *array=NULL, int n=0)
	{
		size=n;
		if(size>0)
		{
			a = new int[size];
			for(int i=0; i<size; i++) a[i]=array[i];
		}
		else
			a=NULL;
	}
	int maxValue()
	{
		int max = a[0];
		for(int i=1; i<size; i++)
			if(max < a[i]) max = a[i];
		return  max;
	}
	~maxInt() { if(a) delete[]a; }
};

class maxDouble          // ��һ����̬�����˫����ʵ������Ԫ�ص����ֵ
{
	double *a;
	int size;
public:
	maxDouble(double *array=NULL, int n=0)
	{
		size=n;
		if(size>0)
		{
			a = new double[size];
			for(int i=0; i<size; i++) a[i]=array[i];
		}
		else
			a=NULL;
	}
	double maxValue()
	{
		double max = a[0];
		for(int i=1; i<size; i++)
			if(max < a[i]) max = a[i];
		return  max;
	}
	~maxDouble() { if(a) delete[]a; }
};

int  main( )
{
	int  Array1[10] = {1, 0, 32, 4, 5, 16, 7, 28, 9, 12};
	double  Array2[8] = {1.2, 22.3, 3.4, 0.4, 5.6, 6.7, 17.8, 8.9};

	maxInt m1(Array1, 10);
	maxDouble m2(Array2, 8);

    cout << "The maximum in integer array is: " << m1.maxValue() << endl;
    cout << "The maximum in doublearray is: " << m2.maxValue() << endl;
	
	return 0;
}
