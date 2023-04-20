#include <iostream.h>
#include <cstring>

//using namespace std;
#include "Li1318.h"

void Test_IsIn(char c, String &s)      // 测试类的成员函数IsIn( )
{
    cout << "\'" << c << "\' in "; s.Show();
    if (s.IsIn(c))                  	// s.IsIn(c)返回的是c第一次在s中出现的地址                   
        cout << "Yes: " << s.IsIn(c) << endl;
    else
        cout << "No！\n";
}
void Test_IsSubStr(char *sp, String &s)  // 测试类的成员函数IsSubStr( )
{
    cout << "\"" << sp << "\" in "; s.Show();
    if (s.IsSubStr(sp)) 
        cout << "Yes！\n";
    else
        cout << "No！\n";
}
int main(void)
{
    String s1("C++程序设计 "), s2, s3("学生学习 ");
    String s, s5;

    s1.Show();
    s2 = s1;                                   // 测试运算符"="
    s2.Show();
    s = s3 + s2;                              // 测试运算符"+"以及运算符"="
    s.Show();
    s5 = s - s1;                              // 测试字符串相减运算符"-"
    s5.Show();
    String s6 = "C++ programming! ";
    Test_IsIn('g', s6);                     // 判断一个字符是否在"串"中
    Test_IsIn('k', s6);
    Test_IsSubStr("prog", s6);             // 判断字符串是否是"串"的子串
    Test_IsSubStr("red", s6);
    cout << "s1 = "; s1.Show();
    cout << "s3 = "; s3.Show();
    if (s1>s3)                                // 字符串比较
        cout << "s1 > s3\n";
    else if (s1<s3)                          // 字符串比较
        cout << "s1 < s3\n";
    else if (s1 == s3)                      // 字符串比较
        cout << "s1 == s3\n";

    const char *sp1, *sp3;
    sp1 = s1;                                  // F 
    sp3 = s3;
    cout << sp3 << sp1 << endl;
    cout << s3.GetString() << endl;
    return 0;
}
