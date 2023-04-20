#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    char infilename[40], outfilename[40], ch;            	// A 

    cout << "Please input an input file name: ";
    cin >> infilename;

    fstream  infile(infilename, ios::in);                  	// B 
    if (!infile)
    {
        cout << "Can not open input file: " << infilename << endl;
        exit(1);
    }
    cout << "Please input an output filename: ";
    cin >> outfilename;

    fstream  outfile(outfilename, ios::out);              	// C 
    if (!outfile)
    {
        cout << "Can not open output file: " << outfilename << endl;
        exit(2);
    }
    while (infile.get(ch))
        outfile << ch;                                         	// D 
    infile.close();
    outfile.close();
    return 0;
}
