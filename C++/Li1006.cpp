#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    char Num[10];	//学号，注意：用数组实现
    char *Name;  		//姓名，注意：用指针实现
    int Score;    	//成绩
public:
    Student(char *nump=NULL, char *namep=NULL, int score=0) //构造函数
    {
        if (nump)					//若nump不为0，则对应的实参给出了学号字符串
            strcpy(Num, nump);	//Num数组的空间系统自动分配，可直接存储学号字符串
        else
            strcpy(Num, "");
        if (namep)  				//若namep不为0，则对应的实参给出了姓名字符串
        {
            Name = new char[strlen(namep) + 1]; //A，动态申请存储姓名的存储空间
            strcpy(Name, namep);
        }
        else
            Name = NULL;
        Score = score;
        cout << "Constructor Called!\n";			//B
    }
    ~Student()   		//在析构函数中，需释放Name成员的空间
    {
        if (Name) delete[] Name;
        cout << "Destructor Called!\n";			//C
    }
    void Show()
    {
        cout << Num << '\t' << Name << '\t' << Score << endl;
    }
};
int main()
{
    Student a("040120518", "George", 80);		//D

    a.Show();
    return 0;
}												//E
