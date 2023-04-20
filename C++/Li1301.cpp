#include <iostream>
#include <cstring>
using namespace std;

class String
{
	int Length;
	char *Strp;
public:
	String();				// ���ع��캯��1
	String(char *s);		// ���ع��캯��2
	String(String &s);		// ���ع��캯��3
	void Print()
	{
		cout << "String=" << Strp << endl;
		cout << "Length=" << Length << endl;
	}
	~String(){ if (Strp)delete[]Strp; }	// ��������
};
String::String()				// ���캯��1�����ַ�����ʼ��Ϊ�մ�""
{
	Length = 0;
	Strp = new char[Length + 1];
	*Strp = '\0';
}
String::String(char *s)			// ���캯��2����sָ��Ĵ���ʼ�������ַ��� 
{
	Length = strlen(s);
	Strp = new char[Length + 1];
	strcpy(Strp, s);
}
String::String(String &s)  		// ���캯��3���������캯��
{
	Length = s.Length;
	Strp = new char[Length + 1];
	strcpy(Strp, s.Strp);
}
int main()
{
	char *sp = "This is a string.";
	String str1;				// �������ع��캯��1
	String str2(sp);			// �������ع��캯��2
	String str3(str2);      	// �������ع��캯��3

	str1.Print();
	str2.Print();
	str3.Print();
	return 0;
}
