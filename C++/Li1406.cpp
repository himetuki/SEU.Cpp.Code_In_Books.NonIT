#include <iostream>
using namespace std;

int main()
{
	char c1, c2, c3;

	cin.unsetf(ios::skipws);        		// A设置为不跳过空白字符 
	cin >> c1 >> c2 >> c3;             	        // B
	cout << c1 << c2 << c3 << '#' << endl;
	cin.setf(ios::skipws);               	// C 设置为跳过空白字符

	int x, y;

	cin.setf(ios::hex, ios::basefield);  		// 设置输入数据为十六进制数
	cin >> x >> y;
	cout << x << ',' << y << endl;
	return 0;
}

/*将C行删除，则输出结果与教材不同
a b c
a b#
-858993460,-858993460
*/
/* 虽然结果不同，但原理是对的 */