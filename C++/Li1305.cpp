#include <iostream>
#include <cstring>
using namespace std;

class Student
{
	char Num[10];   //ѧ�ţ�ע�⣺������ʵ��
	char Name[10];  //������ע�⣺������ʵ��
	int Score;       //�ɼ�
public:
	Student(char num[] = NULL, char name[] = NULL, int score = 0)
	{
		if (num)strcpy(Num, num);
		else Num[0] = '\0';
		if (name)strcpy(Name, name);
		else Name[0] = '\0';
		Score = score;
	}
	void Show()
	{
		cout << "Num=" << Num << '\t' << "Name=" << Name << '\t' << "Score=" << Score << endl;
	}
};
int main()
{
	Student stud1("01201", "Mary", 88), stud2;

	stud2 = stud1;                            //A
	stud1.Show();
	stud2.Show();
	return 0;
}
