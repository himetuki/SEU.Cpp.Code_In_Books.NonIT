//��15.2��ʹ�ú�ʵ�����������ݵ����ֵ�д��ڵ����⡣Դ������ΪLi1502.cpp
#include  <iostream>
using namespace std;

#define  max(x,y)  ( ((x) > (y))  ? (x) : (y) )

int  main()
{
	float a,b;
	char c;

	cin >> a >> c;
	b = max( a, c );		//A
	cout << b << endl;
	
	return 0;
}