//��15.9��ʹ������ģ�庯��ʵ������������������ݱȽϵ����ֵ��Դ������ΪLi1509.cpp
#include  <iostream>
#include  <cstring>
using namespace std;

template  <typename T>  
T  myMax(T var1, T var2)  			//����ģ��
{
	return  var1 > var2 ? var1 : var2;
}

char*  myMax(const char* str1, const char* str2)	//A������ģ�庯��
{
	if(strcmp(str1,str2)>=0)
		return  (char*)str1;
	else
		return  (char*)str2;
}

int  main( )
{
    int     m1 = myMax(100, 200);  //����ģ������myMax(int, int)ģ�庯��
    double  m2 = myMax(7.8, 5.1); //����ģ������myMax(double, double)ģ�庯��
    char*   m3 = myMax("Mary","Kate"); //��������ģ�庯��myMax(char*, char*) 

    cout << "The maximum of 100 and 200 is:  " << m1 << endl;
    cout << "The maximum of 7.8 and 5.1 is:  " << m2 << endl;
    cout << "The maximum of \"Mary\" and \"Kate\" is:  " << m3 << endl;
	
	return 0;
}




