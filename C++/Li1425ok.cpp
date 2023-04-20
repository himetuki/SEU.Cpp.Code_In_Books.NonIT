#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct student           	// ����һ���ṹ������
{
    char name[10];       	// ����
    char id[10];          	// ѧ��
    int score;            	// ����
};

#define LEN  sizeof(student)

int  main()
{
    student st;
    fstream file("stud.dat", ios::out | ios::binary);// �Զ����Ʒ�ʽ������ļ�

    if (!file)
    {
        cout << "Can not open output file: stud.dat" << endl;
        exit(1);
    }
    cin >> st.name;
    while (strcmp(st.name, "#") != 0)       // ѭ������ʱ������������Ϊ "#" ����
    {
        cin >> st.id >> st.score;             // ѭ���Ӽ�������ѧ����Ϣ
        file.write((char *)&st, LEN);        // A��һ��д��LEN�ֽڵ��ڴ�����
        cin >> st.name;
    }
    file.close();                               // �ر���file�������ļ�

    student sts[100];
    int i = 0, j;

    file.open("stud.dat", ios::in | ios::binary);  // �ظ�ʹ��file����
    if (!file)
    {
        cout << "Can not open input file: stud.dat" << endl;
        exit(2);
    }
    while (file.read((char *)(sts + i), LEN))       // B��һ�ζ���LEN�ֽڵ�����
        i++;                                 // ѭ��������i����ȷ����Ľṹ��Ԫ�ظ���
    for (j = 0; j<i; j++)                               // ѭ������Ļ���ѧ����Ϣ
        cout << sts[j].name << '\t' << sts[j].id << '\t' << sts[j].score << endl;
    file.close();
    return 0;
}
