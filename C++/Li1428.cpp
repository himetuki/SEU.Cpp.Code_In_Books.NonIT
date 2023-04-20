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

    infile.read((char*)&n, sizeof(int));      // 读入序列中数据个数 
    cout << "Please input x: ";
    cin >> x;                                       // 输入待查找的x 
    low = 1; high = n;
    while (low <= high)
    {
        mid = (low + high) / 2;
        p1 = mid * 4;
        infile.seekg(p1);                        // 将读写位置指针移到中间数据起始位置
        infile.read((char*)&y, sizeof(int));
        if (x == y){ p2 = p1; break; }        // 找到x
        else if (x<y) high = mid - 1;
        else low = mid + 1;
    }
    if (p2>0) cout << "Position = " << p2 / 4 << endl;
    else cout << "Not found!\n";
    infile.close();
    return 0;
}
