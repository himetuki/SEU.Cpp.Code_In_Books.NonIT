#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char buf[20], max[20];
	int cnum, mc = 0;

	while (cin.get(buf, 20))        // ����ȡ'\n'
	{
		cnum = cin.gcount();
		cin.get();                // ��ȡ��"�Ե�"��ÿ�н�����'\n'
		if (cnum>mc)
		{
			mc = cnum;
			strcpy(max, buf);
		}
		cout << "len=" << cnum << "," << buf << endl;   // cnum����Ҫ�� 1
	}
	cout << "max len=" << mc << "," << max << endl;
	return 0;
}