#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct student           	// 定义一个结构体类型
{
    char name[10];       	// 姓名
    char id[10];          	// 学号
    int score;            	// 分数
};

#define LEN  sizeof(student)

int  main()
{
    student st;
    fstream file("stud.dat", ios::out | ios::binary);// 以二进制方式打开输出文件

    if (!file)
    {
        cout << "Can not open output file: stud.dat" << endl;
        exit(1);
    }
    cin >> st.name;
    while (strcmp(st.name, "#") != 0)       // 循环输入时，以输入姓名为 "#" 结束
    {
        cin >> st.id >> st.score;             // 循环从键盘输入学生信息
        file.write((char *)&st, LEN);        // A，一次写出LEN字节的内存数据
        cin >> st.name;
    }
    file.close();                               // 关闭与file关联的文件

    student sts[100];
    int i = 0, j;

    file.open("stud.dat", ios::in | ios::binary);  // 重复使用file对象
    if (!file)
    {
        cout << "Can not open input file: stud.dat" << endl;
        exit(2);
    }
    while (file.read((char *)(sts + i), LEN))       // B，一次读入LEN字节的数据
        i++;                                 // 循环结束后，i是正确读入的结构体元素个数
    for (j = 0; j<i; j++)                               // 循环向屏幕输出学生信息
        cout << sts[j].name << '\t' << sts[j].id << '\t' << sts[j].score << endl;
    file.close();
    return 0;
}
