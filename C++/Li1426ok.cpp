#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int  main()
{
    int a[100], n = 0;
    ifstream  infile("data.txt");
    if (!infile)
    {
        cout << "Can not open input file: data.txt" << endl;
        exit(1);
    }
    while (!infile.eof())                                 // A 
        infile >> a[n++];
    infile.close();

    ofstream  outfile("data.bin", ios::out | ios::binary);

    if (!outfile)
    {
        cout << "Can not open output file: data.dat" << endl;
        exit(2);
    }
    outfile.write((char *)&n, sizeof(int));           // B
    outfile.write((char *)a, n*sizeof(int));          // C 
    outfile.close();

    int b[100], m = 0, i;
    infile.open("data.bin", ios::in | ios::binary);  // D
    infile.read((char *)&m, sizeof(int));              // E
    infile.read((char *)b, m*sizeof(int));             // F
    infile.close();
    for (i = 0; i < m; i++)
        cout << b[i] << "  ";
    cout << endl;

    return 0;
}
