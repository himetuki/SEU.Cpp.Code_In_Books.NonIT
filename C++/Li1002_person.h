class Person
{
    char Name[20]; 	//姓名
    char Sex;      	//性别 
    int  Age;      	//年龄
public:
    void SetData(char[], char, int);
    void GetName(char *);
    char GetSex();
    int GetAge();
};
void Person::SetData(char na[], char s, int a) // 类体外定义成员函数
{
    strcpy(Name, na);
    Sex = s;
    Age = a;
}
void Person::GetName(char *na) 			// 类体外定义成员函数
{
    strcpy(na, Name);
}
char Person::GetSex()           			// 类体外定义成员函数
{
    return Sex;
}
int Person::GetAge()            			// 类体外定义成员函数
{
    return Age;
}
