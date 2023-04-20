#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char hh[10], mm[10], ss[10];

	cin>>ws;   // 跳过输入中的前导空白字符，仅对其后的第一个输入项有效
	cin.getline(hh, 10, ':');
	cin.getline(mm, 10, ':');
	cin.getline(ss, 10, '\n');
	cout << hh << ':' << mm << ':' << ss << endl;
	return 0;
}
/*

VS2013 和 codeblocks中均报错

错误	1	error C2039: “eatwhite”: 不是“std::basic_istream<char,std::char_traits<char>>”的成员	e:\temp\consoleapplication1\consoleapplication1\源.cpp	18	1	ConsoleApplication1

  在VS2013中没有 eatwhite()？

解决方案：用操纵算子实现eatwhite（）

*/