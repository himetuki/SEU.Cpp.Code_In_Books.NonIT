#include <iostream>
#include <cstring>
using namespace std;

class String
{
	char *Strp;
public:
	String(char *s = 0)   // ���캯��
	{
		if (s)
		{
			Strp = new char[strlen(s) + 1];
			strcpy(Strp, s);
		}
		else Strp = 0;
	}
	String & operator = (String & s)     // A   ��ֵ��������غ���
	{
		if (this == &s) return *this;
		if (Strp) delete[]Strp;
		if (s.Strp)
		{
			Strp = new char[strlen(s.Strp) + 1];
			strcpy(Strp, s.Strp);
		}
		else Strp = 0;
		return *this;
	}
	~String()  // ��������
	{
		if (Strp) delete[]Strp;
	}
	void Show()
	{
		cout << Strp << endl;
	}
};
int main()
{
	String str1("Sample String1");
	String str2;

	str2 = str1;     // ����ֵ����
	str2.Show();  // ��� Sample String1
	return 0;
}
----------------------------------------------------------------------
	String(String & s)  // �������캯��
	{
		if (s.Strp)
		{
			Strp = new char[strlen(s.Strp) + 1];
			strcpy(Strp, s.Strp);
		}
		else Strp = 0;
	}
