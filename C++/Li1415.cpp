#include <iostream>
using namespace std;

int main()
{
	char c;
	for (int i = 0; i<3; i++)
	{
		cin.ignore(2);     //����ǰ�����ַ�
		do
		{
			cin.get(c);
			cout.put(c);
		} while (c != '\n');
	}
	return 0;
}
