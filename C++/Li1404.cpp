#include <iostream>
using namespace std;

int  main()
{
	int x = 165, y = 142;

	cout.setf(ios::oct, ios::basefield);  	// A设置为输出数据为八进制数
	cout << x << ',' << y << endl;
	cout.setf(ios::showbase);         		// B
	cout << x << ',' << y << endl;
	cout.width(8);   						// C 设置输出域宽为8，只对其后第一个数据项有效
	cout.fill('*');                    		// 设置填充字符为 *
	cout.setf(ios::left, ios::adjustfield);	// 设置输出为左对齐
	cout << x << ',' << y << endl;
	cout.setf(ios::hex, ios::basefield);	// 设置为输出数据为十六进制数
	cout << x << ',' << y << endl;
	cout.unsetf(ios::showbase); 			// 设置输出的数据时，前面不带表示数制的前导字符
	cout << x << ',' << y << endl;
	return 0;
}
