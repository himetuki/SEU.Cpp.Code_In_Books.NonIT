//��15.3��ʹ�ú���ģ��ʵ�ֶԶ��������������������ݵ����ֵ��Դ������ΪLi1503.cpp
#include  <iostream>
using namespace std;

template  <typename T>        	//���庯��ģ���<ģ���βα�>
T  myMax(T  var1, T  var2)   	//���庯��ģ���<��������>
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

























