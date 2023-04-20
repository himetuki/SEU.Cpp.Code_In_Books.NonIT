#include <iostream>
#include <cstring>
using namespace std;

class String
{
	int Length;
	char *Strp;
public:
	String();				// 重载构造函数1
	String(char *s);		// 重载构造函数2
	String(String &s);		// 重载构造函数3
	void Print()
	{
		cout << "String=" << Strp << endl;
		cout << "Length=" << Length << endl;
	}
	~String(){ if (Strp)delete[]Strp; }	// 析构函数
};
String::String()				// 构造函数1：将字符串初始化为空串""
{
	Length = 0;
	Strp = new char[Length + 1];
	*Strp = '\0';
}
String::String(char *s)			// 构造函数2：用s指向的串初始化本类字符串 
{
	Length = strlen(s);
	Strp = new char[Length + 1];
	strcpy(Strp, s);
}
String::String(String &s)  		// 构造函数3：拷贝构造函数
{
	Length = s.Length;
	Strp = new char[Length + 1];
	strcpy(Strp, s.Strp);
}
int main()
{
	char *sp = "This is a string.";
	String str1;				// 调用重载构造函数1
	String str2(sp);			// 调用重载构造函数2
	String str3(str2);      	// 调用重载构造函数3

	str1.Print();
	str2.Print();
	str3.Print();
	return 0;
}
