#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char buf[20], max[20];
	int cnum, mc = 0;

	while (cin.get(buf, 20))        // 不提取'\n'
	{
		cnum = cin.gcount();
		cin.get();                // 提取（"吃掉"）每行结束的'\n'
		if (cnum>mc)
		{
			mc = cnum;
			strcpy(max, buf);
		}
		cout << "len=" << cnum << "," << buf << endl;   // cnum不需要减 1
	}
	cout << "max len=" << mc << "," << max << endl;
	return 0;
}