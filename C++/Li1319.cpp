#include <iostream>
#include <cstring>
using namespace std;

#include "Li1318.h"                            // ע�Ȿ����������13.18��ͷ�ļ� 

class Str : public String
{
public:
    Str() :String(){ }                        // ���û��๹�캯��
    Str(char *ps) :String(ps){ }            // ���û��๹�캯��
    Str(Str &s) :String(s){ }                // ���û��๹�캯��
    Str operator+(Str &s)                     // A 
    {
        Str t;

        t.Length = Length + s.Length;
        t.Strp = new char[t.Length + 1];
        strcpy(t.Strp, Strp);
        strcat(t.Strp, s.Strp);
        return t;
    }
    Str operator = (Str &s)                    // B
    {
        if( this == & s ) return *this;        // �����ַ�������ֵ
		if (Strp) delete[] Strp;
        Length = s.Length;
        if (s.Strp)
        {
            Strp = new char[Length + 1];
            strcpy(Strp, s.Strp);
        }
        else Strp = NULL;
        return *this;
    }
};

int main(void)
{
    Str s1("ѧ��ѧϰ "), s2("C++������� ");
    Str s3(s2), s4, s5;

    cout << "s1 = "; s1.Show();
    cout << "s2 = " << s2 << endl;        // C�����ü̳�����"����ת��"����
    cout << "s3 = " << s3 << endl;
    s4 = s2;                                   // �ַ������帳ֵ��ʹ�����¶�������غ���
    cout << "s4 = s2 = " << s4 << endl;
    s5 = s1 + s2;                             // �ַ���ƴ�ӣ�ʹ�����¶�������غ���
    cout << "s5 = s1 + s2; s5 = " << s5 << endl;
    cout << "p = " << s2.IsIn('+') << endl; // ʹ�ü̳����ĳ�Ա����
    if (s2>s3)                                // ʹ�ü̳������ַ����Ƚ������>
        cout << "s2 > s3\n";
    else if (s2 < s3)                        // ʹ�ü̳������ַ����Ƚ������<
        cout << "s2 < s3\n";
    else if (s2 == s3)                       // ʹ�ü̳������ַ����Ƚ������==
        cout << "s2 == s3\n";
    return 0;
}
