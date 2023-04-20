#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double x = 12.3456789;

	cout << x << endl;
	cout << setprecision(4) << x << endl;
	cout.setf(ios::fixed, ios::floatfield);    // 设置以定点数格式输出
	cout << x << endl;
	cout.setf(ios::scientific, ios::floatfield);  // 设置以科学表示法格式输出
	cout << setprecision(2) << x << endl;
	return 0;
}
