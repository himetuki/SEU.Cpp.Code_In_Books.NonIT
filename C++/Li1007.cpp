#include <iostream>
using namespace std;

class  Date
{
    int Year, Month, Day;
public:
    Date(int y = 2000, int m = 1, int d = 1)//A���������������в�������Ĭ��ֵ
    {
        Year = y; Month = m; Day = d;
        cout << "Constructor: ";
        ShowDate();
    }
    void ShowDate()
    {
        cout << Year << '.' << Month << '.' << Day << endl;
    }
    ~Date()
    {
        cout << "Destructor: ";
        ShowDate();
    }
};

Date d4(2016, 4, 4);      		//ȫ�ֶ��󣨾�̬�ģ�

void fun()
{
    cout << "���� fun( )����!\n";

    static Date d2(2016, 2, 2);	//�ֲ���̬����
    Date d3(2016, 3, 3);       	//�ֲ���̬����

    cout << "�˳� fun( )����!\n";
}
int main()
{
    cout << "���� main( )����!\n";

    Date d1(2016, 1, 1);        	//�ֲ���̬����

    fun();
    fun();
    cout << "�˳� main( )����!\n";
    return 0;
}
