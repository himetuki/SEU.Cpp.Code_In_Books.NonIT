#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char buf[20], max[20];
	int cnum, mc = 0;

	while (cin.getline(buf, 20))     // A ��ȡһ���ַ�����ȡ��������β��־'\n' 
	{
		cnum = cin.gcount();      // B ��ȡA�е�getline( )ʵ�ʶ�ȡ���ַ�����
		if (cnum>mc)
		{
			mc = cnum;
			strcpy(max, buf);
		}
		cout << "len=" << cnum - 1 << "," << buf << endl;  // C 
	}
	cout << "max len=" << mc - 1 << "," << max << endl;   // D
	return 0;
}
