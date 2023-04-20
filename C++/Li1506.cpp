//例15.6：具有常规参数的函数模板的定义和使用。源程序名为Li1506.cpp
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
	cout << "计算结果：" << result << endl;
	
	return 0;
}
























