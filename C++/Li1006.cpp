#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    char Num[10];	//ѧ�ţ�ע�⣺������ʵ��
    char *Name;  		//������ע�⣺��ָ��ʵ��
    int Score;    	//�ɼ�
public:
    Student(char *nump=NULL, char *namep=NULL, int score=0) //���캯��
    {
        if (nump)					//��nump��Ϊ0�����Ӧ��ʵ�θ�����ѧ���ַ���
            strcpy(Num, nump);	//Num����Ŀռ�ϵͳ�Զ����䣬��ֱ�Ӵ洢ѧ���ַ���
        else
            strcpy(Num, "");
        if (namep)  				//��namep��Ϊ0�����Ӧ��ʵ�θ����������ַ���
        {
            Name = new char[strlen(namep) + 1]; //A����̬����洢�����Ĵ洢�ռ�
            strcpy(Name, namep);
        }
        else
            Name = NULL;
        Score = score;
        cout << "Constructor Called!\n";			//B
    }
    ~Student()   		//�����������У����ͷ�Name��Ա�Ŀռ�
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
