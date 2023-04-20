#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    char *Name;  						// 姓名，注意：用指针实现
    int Age;      					// 年龄
public:
    Student(char *namep, int age)   	// 构造函数
    {
        Age = age;
        if (namep)        				// 在构造函数中，动态申请空间
        {
            Name = new char[strlen(namep) + 1]; // A
            strcpy(Name, namep);
        }
        else Name = NULL;
    }
    ~Student()	// 因为在构造函数中动态申请了空间，则在析构函数中，需释放空间
    {
        if (Name) delete[] Name;
    }
    void Show()
    {
        cout << Name << ',' << Age << endl;
    }
};

int main()
{
    Student a("George", 20);		// B
    Student b = a;                 // C

    b.Show();
    return 0;
}

=================================================================

Student::Student(const Student &s)  //"浅"拷贝构造函数
{ 
    Name = s.Name;  					// D， 注意：直接赋地址值
    Age = s.Age;						// E
}
=================================================================
Student::Student(const Student &s)   //"深"拷贝构造函数
{
    Age = s.Age;
    if(s.Name)
    {
        Name = new char[strlen(s.Name)+1];  // F
        strcpy(Name, s.Name);
    }
    else Name = NULL; 
}
