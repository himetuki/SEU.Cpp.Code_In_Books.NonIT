#include <iostream>
using namespace std;

#include "person.h"    //������10.1����10.2�е�ͷ�ļ�

int main()
{
    Person a, *pa;
    char name[20];

    // ����ͨ��������ʳ�Ա
    a.SetData("Cheng", 'F', 20);
    a.GetName(name);
    cout << "Name: " << name << '\t';
    cout << " Sex: " << a.GetSex() << '\t';
    cout << " Age: " << a.GetAge() << endl;

    // ����ͨ��ָ����ʳ�Ա
    pa = &a;
    pa->SetData("Zhang", 'M', 18);
    pa->GetName(name);
    cout << "Name: " << name << '\t';
    cout << " Sex: " << pa->GetSex() << '\t';
    cout << " Age: " << pa->GetAge() << endl;
    return 0;
}
