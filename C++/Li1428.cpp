#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int  main()
{
    fstream  infile("data.bin", ios::in | ios::binary);
    if (!infile)
    {
        cout << "Can not open file: data.bin" << endl;
        exit(1);
    }

    int n, x, y, low, mid, high;
    streampos p1, p2 = -1;

    infile.read((char*)&n, sizeof(int));      // �������������ݸ��� 
    cout << "Please input x: ";
    cin >> x;                                       // ��������ҵ�x 
    low = 1; high = n;
    while (low <= high)
    {
        mid = (low + high) / 2;
        p1 = mid * 4;
        infile.seekg(p1);                        // ����дλ��ָ���Ƶ��м�������ʼλ��
        infile.read((char*)&y, sizeof(int));
        if (x == y){ p2 = p1; break; }        // �ҵ�x
        else if (x<y) high = mid - 1;
        else low = mid + 1;
    }
    if (p2>0) cout << "Position = " << p2 / 4 << endl;
    else cout << "Not found!\n";
    infile.close();
    return 0;
}
