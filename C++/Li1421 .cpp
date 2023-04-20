#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    char filename[40], ch;
    fstream  infile;                             // A

    cout << "Please input a filename: ";
    cin >> filename;
    infile.open(filename, ios::in);          // B��һ��Ӧ�����ڶ���ʵ��
    if (!infile)
    {
        cout << "Can not open file: " << filename << endl;
        exit(1);
    }
    infile.unsetf(ios::skipws);                // C
    while (infile >> ch)                        // D
        cout << ch;
    infile.close();                             // F 
    return 0;
}
