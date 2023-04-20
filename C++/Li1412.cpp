#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char buf[20], max[20];
	int cnum, mc = 0;

	while (cin.getline(buf, 20))     // A 提取一行字符，读取并舍弃行尾标志'\n' 
	{
		cnum = cin.gcount();      // B 获取A行的getline( )实际读取的字符个数
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
