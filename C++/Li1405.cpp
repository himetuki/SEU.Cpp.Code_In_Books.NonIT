#include <iostream>
using namespace std;

int main()
{
	char c, str[80];
	int i = 0;

	cin >> c;                 // A   �ڴ���֮ǰ�������cin.unsetf(ios::skipws);
	while (c != '\n')
	{
		str[i++] = c;
		cin >> c;
	}
	str[i] = '\0';
	cout << str << endl;
	return 0;
}
