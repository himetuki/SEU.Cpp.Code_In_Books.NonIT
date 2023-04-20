//例15.2：使用宏实现求两个数据的最大值中存在的问题。源程序名为Li1502.cpp
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