#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    char *Name;  						// ������ע�⣺��ָ��ʵ��
    int Age;      					// ����
public:
    Student(char *namep, int age)   	// ���캯��
    {
        Age = age;
        if (namep)        				// �ڹ��캯���У���̬����ռ�
        {
            Name = new char[strlen(namep) + 1]; // A
            strcpy(Name, namep);
        }
        else Name = NULL;
    }
    ~Student()	// ��Ϊ�ڹ��캯���ж�̬�����˿ռ䣬�������������У����ͷſռ�
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

Student::Student(const Student &s)  //"ǳ"�������캯��
{ 
    Name = s.Name;  					// D�� ע�⣺ֱ�Ӹ���ֵַ
    Age = s.Age;						// E
}
=================================================================
Student::Student(const Student &s)   //"��"�������캯��
{
    Age = s.Age;
    if(s.Name)
    {
        Name = new char[strlen(s.Name)+1];  // F
        strcpy(Name, s.Name);
    }
    else Name = NULL; 
}
