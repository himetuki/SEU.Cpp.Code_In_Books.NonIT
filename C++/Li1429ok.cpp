/* ǰ����������� ----------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
    double aver = 0, a[5];

    for (int i = 0; i<5; i++)
    {
        cout << "�������" << i + 1 << "������";
        cin >> a[i];
        aver += a[i];
        cout << "a[" << i << "]=" << a[i] << endl;
    }
    aver /= 5;
    cout << "aver=" << aver << endl;

    return 0;
}

*/
#include <iostream>
using namespace std;

int main()
{
    double aver = 0, a[5];
    char temp[80];

    for (int i = 0; i<5; i++)
    {
        cout << "�������" << i + 1 << "������";
        cin >> a[i];
        while (cin.rdstate())     // �������д���
        {
            cin.clear();           // �������״̬��������������Ȼ�������뻺������
            cin.getline(temp, 80);//���������еĴ���������ͬ�س�һ����뵽temp������
            cout << temp << "Ϊ�Ƿ�����!\n";
            cout << "�����������" << i + 1 << "������";
            cin >> a[i];
        }
        aver += a[i];
    }
    aver /= 5;
    cout << "aver=" << aver << endl;
    return 0;
}
