//��15.8��ʹ�ú���ģ����ͬ�����������ݵ����ֵ��Դ������ΪLi1508.cpp
#include  <iostream>
using namespace std;

template  < typename T1, typename T2>  
T1  max(T1 var1, T2 var2)
{
	return  var1 > var2 ? var1 : var2;
}

int  main( )
{
	int  m1 = max(30,7.56);     //A������ģ�屻���ͳ�max(int, double) ģ�庯��
	int  m2 = max(70, 'k');     //B������ģ�屻���ͳ�max(int, char) ģ�庯��
	int  m3 = max(100,300);     //C������ģ�屻���ͳ�max(int, int) ģ�庯��

	cout << "The maxium of 30 and 7.56 is: " << m1 << endl;
	cout << "The maxium of 70 and 'k' is: " << m2 << endl;
	cout << "The maxium of 100 and 300 is: " << m3 << endl;
	
	return 0;
} 








