#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, n, w;

	cout << "Please input an odd number: ";
	cin >> n;                                     // ����һ������
	for (i = 0; i<n; i++)
	{
		if (i<n / 2) w = n / 2 - i;
		else w = i - n / 2;
		if (i != n / 2)
			cout << setfill(' ') << setw(w) << ' ';   // ' '��ʾ�ո����ÿ�е�ǰ���ո� 
		if (i<n / 2) w = i * 2 + 1;
		else w = n - (i - n / 2) * 2;
		cout << setfill('*') << setw(w) << '*';       // ���ÿ�е�*��
		cout << endl;
	}
	return 0;
}
