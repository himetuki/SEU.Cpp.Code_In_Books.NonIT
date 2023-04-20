#include <iostream>
using namespace std;

int add(int a, int b){ return(a + b); }				// 重载函数1

double add(double a, double b) { return(a + b); }		// 重载函数2

int main()
{
	cout << add(1, 2) << '\t';							// 编译时确定调用重载函数1
	cout << add(1.1, 2.2) << '\n';						// 编译时确定调用重载函数2
	return 0;
}
