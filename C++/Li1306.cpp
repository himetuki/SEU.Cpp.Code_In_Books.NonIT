#include <iostream>
#include <cstring>
using namespace std;

class Student
{
	char *Nump; 	// 学号，注意：用指针实现
	char *Namep;	// 姓名，注意：用指针实现
	int Score;    	// 成绩
public:
	Student(char *nump = NULL, char *namep = NULL, int score = 0)
	{
		if (nump)
		{
			Nump = new char[strlen(nump) + 1];
			strcpy(Nump, nump);
		}
		else Nump = NULL;
		if (namep)
		{
			Namep = new char[strlen(namep) + 1];
			strcpy(Namep, namep);
		}
		else Namep = NULL;
		Score = score;
	}
	~Student()
	{
		if (Nump)delete[]Nump;
		if (Namep)delete[]Namep;
	}
	void Show()
	{
		if (Nump) cout << "Num=" << Nump << '\t';
		if (Namep) cout << "Name=" << Namep << '\t';
		cout << "Score=" << Score << endl;
	}
};
int main()
{
	Student stud1("01201", "Mary", 88), stud2;

	stud2 = stud1;                   	// A
	stud1.Show();
	stud2.Show();
	return 0;
}

--------------------------------------------------------------
增加运算符重载函数定义如下：
--------------------------------------------------------------
Student & operator = (const Student &stud)         // 返回值为对象自身的引用 
{
    if (this == &stud)                                  // B，处理对象自身赋值
        return *this;
    if (Nump)delete[]Nump;                             // C，释放对象自身的原串空间
    if (Namep)delete[]Namep;                          // D，释放对象自身的原串空间
    if (stud.Nump)                    // 根据赋值对象的空间大小给被赋值对象分配空间 
    {
        Nump = new char[strlen(stud.Nump) + 1];    // E 
        strcpy(Nump, stud.Nump);                      // F 
    }
    else Nump = NULL;
    if (stud.Namep)                    // 根据赋值对象的空间大小给被赋值对象分配空间
    {
        Namep = new char[strlen(stud.Namep) + 1];  // G 
        strcpy(Namep, stud.Namep);                    // H 
    }
    else Namep = NULL;
    Score = stud.Score;
    return *this;                                       // *this是对象自身 
}
