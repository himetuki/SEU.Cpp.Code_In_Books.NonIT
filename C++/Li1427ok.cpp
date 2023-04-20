#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    fstream  iofile("fib.bin", ios::out | ios::binary);         // A
    iofile.close();                                                    // B

    iofile.open("fib.bin", ios::in | ios::out | ios::binary); // C 
    if (!iofile)
    {
        cout << "Can not open file: fib.bin" << endl;
        exit(1);
    }
    long pos = iofile.tellp();                                    // D
    cout << "Begin posi=" << pos << endl;

    int f1 = 1, f2 = 1, i;

    for (i = 0; i<20; i++)
    {
        iofile.write((char*)&f1, sizeof(int));
        iofile.write((char*)&f2, sizeof(int));
        f1 = f1 + f2;
        f2 = f2 + f1;
    }
    pos = iofile.tellp();                                           // E
    cout << "End posi=" << pos << endl;
    iofile.seekg(0);                                                 // F
    for (i = 0; i<20; i++)
    {
        iofile.read((char*)&f1, sizeof(int));                   // G
        iofile.seekg(sizeof(int), ios::cur);                    // H
        cout << setw(10) << f1;
        if ((i + 1) % 5 == 0) cout << endl;
    }
    iofile.close();
    return 0;
}
