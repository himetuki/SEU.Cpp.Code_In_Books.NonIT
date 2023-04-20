#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, n, w;

	cout << "Please input an odd number: ";
	cin >> n;                                     // 输入一个奇数
	for (i = 0; i<n; i++)
	{
		if (i<n / 2) w = n / 2 - i;
		else w = i - n / 2;
		if (i != n / 2)
			cout << setfill(' ') << setw(w) << ' ';   // ' '表示空格，输出每行的前导空格 
		if (i<n / 2) w = i * 2 + 1;
		else w = n - (i - n / 2) * 2;
		cout << setfill('*') << setw(w) << '*';       // 输出每行的*号
		cout << endl;
	}
	return 0;
}
