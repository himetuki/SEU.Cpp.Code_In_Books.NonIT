class  Person
{
private:				// �˴���private��ȱʡ
    char Name[20];	// ����
    char Sex;		// �Ա� 
    int  Age;			// ����
public:
    // ���¶������ĸ���Ա����
    void SetData(char na[], char s, int a)
    {
        strcpy(Name, na);	// ֱ�ӷ���Name
        Sex = s;				// ֱ�ӷ���Sex
        Age = a;			    // ֱ�ӷ���Age
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
};                 // ע�⣺�ඨ������������зֺ�
