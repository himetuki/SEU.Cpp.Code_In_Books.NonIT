#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char hh[10], mm[10], ss[10];

	cin>>ws;   // ���������е�ǰ���հ��ַ����������ĵ�һ����������Ч
	cin.getline(hh, 10, ':');
	cin.getline(mm, 10, ':');
	cin.getline(ss, 10, '\n');
	cout << hh << ':' << mm << ':' << ss << endl;
	return 0;
}
/*

VS2013 �� codeblocks�о�����

����	1	error C2039: ��eatwhite��: ���ǡ�std::basic_istream<char,std::char_traits<char>>���ĳ�Ա	e:\temp\consoleapplication1\consoleapplication1\Դ.cpp	18	1	ConsoleApplication1

  ��VS2013��û�� eatwhite()��

����������ò�������ʵ��eatwhite����

*/