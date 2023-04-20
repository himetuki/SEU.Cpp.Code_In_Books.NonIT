#include <iostream>
using namespace std;

#include "person.h"    //包含例10.1或例10.2中的头文件

int main()
{
    Person a, *pa;
    char name[20];

    // 以下通过对象访问成员
    a.SetData("Cheng", 'F', 20);
    a.GetName(name);
    cout << "Name: " << name << '\t';
    cout << " Sex: " << a.GetSex() << '\t';
    cout << " Age: " << a.GetAge() << endl;

    // 以下通过指针访问成员
    pa = &a;
    pa->SetData("Zhang", 'M', 18);
    pa->GetName(name);
    cout << "Name: " << name << '\t';
    cout << " Sex: " << pa->GetSex() << '\t';
    cout << " Age: " << pa->GetAge() << endl;
    return 0;
}
