//��15.6�����г�������ĺ���ģ��Ķ����ʹ�á�Դ������ΪLi1506.cpp
#include  <iostream>
using namespace std;

template < typename  T, int  k > 
T  fun(T  var1, T  var2)
{
	return  (var1+var2) / k;
}

int  main()
{
	float  a,b;

	cin >> a >> b;

	float  result = fun <float,5> (a,b);		//A
	cout << "��������" << result << endl;
	
	return 0;
}
























