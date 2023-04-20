#include <iostream>
using namespace std;

int main()
{
	double x = 12.3456789;
	int pre = cout.precision();                 // 获得缺省精度 

	cout << "default precision = " << pre << endl;
	cout << x << endl;
	cout.precision(4);                           // A 设置精度
	cout << x << endl;
	cout.precision(6);
	cout.setf(ios::fixed, ios::floatfield);     // B 设置以定点数格式输出
	cout << x << endl;
	cout.precision(2);
	cout << x << endl;
	cout.setf(ios::scientific, ios::floatfield);  // C 设置以科学表示法格式输出
	cout << x << endl;
	return 0;
}
