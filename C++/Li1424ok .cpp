#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    char ch1, ch2, temp[1000];   // ch1为当前字符，ch2为预读取的下一字符
    int state = 1;                 // state 为读写位置指针当前状态

    fstream  infile("test.cpp", ios::in);
    if (!infile)
    {
        cout << "Can not open source file: test.cpp" << endl;
        exit(1);
    }
    fstream  outfile("test1.cpp", ios::out);
    if (!outfile)
    {
        cout << "Can not open target file: test1.cpp" << endl;
        exit(2);
    }
    while (infile.get(ch1))
    {
        ch2 = infile.peek();                               // A 
        if (state == 1)
        {
            if (ch1 == '/' && ch2 == '*')
            {
                infile.get();
                state = 2;
            }
            else if (ch1 == '/' && ch2 == '/')
                infile.get(temp, sizeof(temp));             // B 
            else
                outfile.put(ch1);
        }
        else if (ch1 == '*' && ch2 == '/')
        {
            infile.get();
            state = 1;
        }
    }
    infile.close();
    outfile.close();
    return 0;
}

// test.cpp

/********************************
*    请思考此程序的功能？       *
********************************/
#include <iostream>
#include <cstring>
using namespace std;

void swap(char s1[], char s2[])
{
	char t;
	t = *s1; *s1 = *s2; *s2 = t;
}
int main()
{
	char s1[] = "BD", s2[] = "AB";
	if (strcmp(s1, s2)>0)   /* comment  */
		swap(s1, s2);
	cout << s1 << ',';      // comment1
	cout << s2 << endl;    // comment2
	return 0;
}

//test1.cpp


#include <iostream>
#include <cstring>
using namespace std;

void swap(char s1[], char s2[])
{
	char t;
	t = *s1; *s1 = *s2; *s2 = t;
}
int main()
{
	char s1[] = "BD", s2[] = "AB";
	if (strcmp(s1, s2)>0)
		swap(s1, s2);
	cout << s1 << ',';
	cout << s2 << endl;
	return 0;
}
