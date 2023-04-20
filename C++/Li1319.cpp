#include <iostream>
#include <cstring>
using namespace std;

#include "Li1318.h"                            // 注意本例包含了例13.18的头文件 

class Str : public String
{
public:
    Str() :String(){ }                        // 调用基类构造函数
    Str(char *ps) :String(ps){ }            // 调用基类构造函数
    Str(Str &s) :String(s){ }                // 调用基类构造函数
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
        if( this == & s ) return *this;        // 处理字符串自身赋值
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
    Str s1("学生学习 "), s2("C++程序设计 ");
    Str s3(s2), s4, s5;

    cout << "s1 = "; s1.Show();
    cout << "s2 = " << s2 << endl;        // C，调用继承来的"类型转换"函数
    cout << "s3 = " << s3 << endl;
    s4 = s2;                                   // 字符串整体赋值，使用重新定义的重载函数
    cout << "s4 = s2 = " << s4 << endl;
    s5 = s1 + s2;                             // 字符串拼接，使用重新定义的重载函数
    cout << "s5 = s1 + s2; s5 = " << s5 << endl;
    cout << "p = " << s2.IsIn('+') << endl; // 使用继承来的成员函数
    if (s2>s3)                                // 使用继承来的字符串比较运算符>
        cout << "s2 > s3\n";
    else if (s2 < s3)                        // 使用继承来的字符串比较运算符<
        cout << "s2 < s3\n";
    else if (s2 == s3)                       // 使用继承来的字符串比较运算符==
        cout << "s2 == s3\n";
    return 0;
}
