/* 前面的引子例子 ----------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
    double aver = 0, a[5];

    for (int i = 0; i<5; i++)
    {
        cout << "请输入第" << i + 1 << "个数：";
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
        cout << "请输入第" << i + 1 << "个数：";
        cin >> a[i];
        while (cin.rdstate())     // 若输入有错误
        {
            cin.clear();           // 清除出错状态，但错误输入依然留在输入缓冲区中
            cin.getline(temp, 80);//将缓冲区中的错误输入连同回车一起读入到temp，丢弃
            cout << temp << "为非法输入!\n";
            cout << "请重新输入第" << i + 1 << "个数：";
            cin >> a[i];
        }
        aver += a[i];
    }
    aver /= 5;
    cout << "aver=" << aver << endl;
    return 0;
}
