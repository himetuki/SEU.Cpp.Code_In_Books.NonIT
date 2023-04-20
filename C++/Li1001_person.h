class  Person
{
private:				// 此处，private可缺省
    char Name[20];	// 姓名
    char Sex;		// 性别 
    int  Age;			// 年龄
public:
    // 以下定义了四个成员函数
    void SetData(char na[], char s, int a)
    {
        strcpy(Name, na);	// 直接访问Name
        Sex = s;				// 直接访问Sex
        Age = a;			    // 直接访问Age
    }
    void GetName(char *na)
    {
        strcpy(na, Name);
    }
    char GetSex()
    {
        return Sex;
    }
    int GetAge()
    {
        return Age;
    }
};                 // 注意：类定义结束处必须有分号
