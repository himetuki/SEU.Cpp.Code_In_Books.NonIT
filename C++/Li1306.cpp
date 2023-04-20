#include <iostream>
#include <cstring>
using namespace std;

class Student
{
	char *Nump; 	// ѧ�ţ�ע�⣺��ָ��ʵ��
	char *Namep;	// ������ע�⣺��ָ��ʵ��
	int Score;    	// �ɼ�
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
������������غ����������£�
--------------------------------------------------------------
Student & operator = (const Student &stud)         // ����ֵΪ������������� 
{
    if (this == &stud)                                  // B�������������ֵ
        return *this;
    if (Nump)delete[]Nump;                             // C���ͷŶ��������ԭ���ռ�
    if (Namep)delete[]Namep;                          // D���ͷŶ��������ԭ���ռ�
    if (stud.Nump)                    // ���ݸ�ֵ����Ŀռ��С������ֵ�������ռ� 
    {
        Nump = new char[strlen(stud.Nump) + 1];    // E 
        strcpy(Nump, stud.Nump);                      // F 
    }
    else Nump = NULL;
    if (stud.Namep)                    // ���ݸ�ֵ����Ŀռ��С������ֵ�������ռ�
    {
        Namep = new char[strlen(stud.Namep) + 1];  // G 
        strcpy(Namep, stud.Namep);                    // H 
    }
    else Namep = NULL;
    Score = stud.Score;
    return *this;                                       // *this�Ƕ������� 
}
