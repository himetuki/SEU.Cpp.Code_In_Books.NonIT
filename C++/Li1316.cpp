#include <iostream>
#include <cstring>
using namespace std;

class String
{
	int Length;
	char *Strp;           // 指向串的指针 
public:
	String();            // 重载构造函数1
	String(char *s);      // 重载构造函数2
	String(String &s);    // 重载构造函数3
	void Print()
	{
		cout << "String=" << Strp << endl;
		cout << "Length=" << Length << endl;
	}
	~String()             // 析构函数
	{
		if (Strp) delete[]Strp;
		cout << "Destructor\n";
	}
};
String::String()
{
	Length = 0;
	Strp = new char[Length + 1];
	*Strp = '\0';
	cout << "Constructor 1\n";
}
String::String(char *s)
{
	Length = strlen(s);
	Strp = new char[Length + 1];
	strcpy(Strp, s);
	cout << "Constructor 2\n";
}
String::String(String &s)
{
	Length = s.Length;
	Strp = new char[Length + 1];
	strcpy(Strp, s.Strp);
	cout << "Constructor 3\n";
}
int main()
{
	String *ptr1, *ptr2;

	ptr1 = new String("Student");  // 调用重载构造函数2 
	ptr2 = new String(*ptr1);      // 调用重载构造函数3 
	ptr1->Print();
	ptr2->Print();
	delete ptr1;
	delete ptr2;
	return 0;
}
