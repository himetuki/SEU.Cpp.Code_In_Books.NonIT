class Person
{
    char Name[20]; 	//����
    char Sex;      	//�Ա� 
    int  Age;      	//����
public:
    void SetData(char[], char, int);
    void GetName(char *);
    char GetSex();
    int GetAge();
};
void Person::SetData(char na[], char s, int a) // �����ⶨ���Ա����
{
    strcpy(Name, na);
    Sex = s;
    Age = a;
}
void Person::GetName(char *na) 			// �����ⶨ���Ա����
{
    strcpy(na, Name);
}
char Person::GetSex()           			// �����ⶨ���Ա����
{
    return Sex;
}
int Person::GetAge()            			// �����ⶨ���Ա����
{
    return Age;
}
