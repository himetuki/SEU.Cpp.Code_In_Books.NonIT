#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void sort(int *a, int n)
{
    int i, j, p, t;
    for (i = 0; i<n - 1; i++)
    {
        p = i;
        for (j = i + 1; j<n; j++)
        if (a[j]<a[p]) p = j;
        if (p != i)
        {
            t = a[i]; a[i] = a[p]; a[p] = t;
        }
    }
}

int main()
{
    int a[100], i, n;
    fstream in, out;

    in.open("d:\\data\\source.txt", ios::in);           // A
    if (!in) 
    {
        cout << "Can not open source.txt!" << endl; 
        exit(1); 
    }
    out.open("d:\\data\\target.txt", ios::out);         // B
    if (!out)
    {
        cout << "Can not open target.txt!" << endl; 
        exit(2);
    }
    i = 0;
    while (in >> a[i]) i++;         // 循环结束后，i是已读入整数的个数
    n = i;
    sort(a, n);
    for (i = 0; i<n; i++)
        out << a[i] << "  ";
    out << endl;
    in.close();
    out.close();
    return 0;
}
