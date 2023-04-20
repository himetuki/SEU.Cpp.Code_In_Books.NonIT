#include <iostream.h>
#include <cstring>

//using namespace std;
#include "Li1318.h"

void Test_IsIn(char c, String &s)      // ������ĳ�Ա����IsIn( )
{
    cout << "\'" << c << "\' in "; s.Show();
    if (s.IsIn(c))                  	// s.IsIn(c)���ص���c��һ����s�г��ֵĵ�ַ                   
        cout << "Yes: " << s.IsIn(c) << endl;
    else
        cout << "No��\n";
}
void Test_IsSubStr(char *sp, String &s)  // ������ĳ�Ա����IsSubStr( )
{
    cout << "\"" << sp << "\" in "; s.Show();
    if (s.IsSubStr(sp)) 
        cout << "Yes��\n";
    else
        cout << "No��\n";
}
int main(void)
{
    String s1("C++������� "), s2, s3("ѧ��ѧϰ ");
    String s, s5;

    s1.Show();
    s2 = s1;                                   // ���������"="
    s2.Show();
    s = s3 + s2;                              // ���������"+"�Լ������"="
    s.Show();
    s5 = s - s1;                              // �����ַ�����������"-"
    s5.Show();
    String s6 = "C++ programming! ";
    Test_IsIn('g', s6);                     // �ж�һ���ַ��Ƿ���"��"��
    Test_IsIn('k', s6);
    Test_IsSubStr("prog", s6);             // �ж��ַ����Ƿ���"��"���Ӵ�
    Test_IsSubStr("red", s6);
    cout << "s1 = "; s1.Show();
    cout << "s3 = "; s3.Show();
    if (s1>s3)                                // �ַ����Ƚ�
        cout << "s1 > s3\n";
    else if (s1<s3)                          // �ַ����Ƚ�
        cout << "s1 < s3\n";
    else if (s1 == s3)                      // �ַ����Ƚ�
        cout << "s1 == s3\n";

    const char *sp1, *sp3;
    sp1 = s1;                                  // F 
    sp3 = s3;
    cout << sp3 << sp1 << endl;
    cout << s3.GetString() << endl;
    return 0;
}
