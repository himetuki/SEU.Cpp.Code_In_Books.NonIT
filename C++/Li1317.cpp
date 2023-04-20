#include <iostream>
#include <cstring>
using namespace std;
class String
{
	int Length;
	char *Strp;
public:
	void * operator new(size_t size);           // 重载运算符new 函数1 
	void * operator new(size_t size, char *str);   // 重载运算符new 函数2 
	void * operator new(size_t size, String &s);  // 重载运算符new 函数3 
	void Print()
	{
		cout << "String=" << Strp << endl;
		cout << "Length=" << Length << endl;
	}
	void operator delete(void *p)             // A重载 delete 
	{
		if (p)
		{
			String *t = (String *)p;

			if (t->Strp) delete[](t->Strp);
			delete[](char *) p;
		}
		cout << "Delete \n";
	}
};
void * String::operator new(size_t size)    // B 
{
	String *p = (String *)new char[size];

	p->Length = 0;
	p->Strp = new char[p->Length + 1];
	*(p->Strp) = '\0';
	cout << "New 1\n";
	return (void *)p;
}
void * String::operator new(size_t size, char *str)    // C  
{
	String *p = (String *)new char[size];

	p->Length = strlen(str);
	p->Strp = new char[p->Length + 1];
	strcpy(p->Strp, str);
	cout << "New 2\n";
	return (void *)p;
}
void * String::operator new(size_t size, String &s)    // D 
{
	String *p = (String *)new char[size];

	p->Length = s.Length;
	p->Strp = new char[p->Length + 1];
	strcpy(p->Strp, s.Strp);
	cout << "New 3\n";
	return (void *)p;
}
int main()
{
	String *ptr1, *ptr2, *ptr3;

	ptr1 = new String;                           // E              
	ptr2 = new ("Student")String;                // F 
	ptr3 = new (*ptr2)String;                    // G 
	ptr1->Print();
	ptr2->Print();
	ptr3->Print();
	delete ptr1;                   				// H
	delete ptr2;
	delete ptr3;
	return 0;
}
运行结果：
New 1
New 2
New 3
String=
Length=0
String=Student
Length=7
String=Student
Length=7
Delete
Delete
Delete