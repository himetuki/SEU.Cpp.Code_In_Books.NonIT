#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    char filename[40], line[80];
    ifstream  infile;

    cout << "Please input a filename: ";
    cin >> filename;                                 // A 
    infile.open(filename);                          // B 
    if (!infile)                                      // C 
    {
        cout << "Can not open file: " << filename << endl;
        exit(1);                                       // D 
    }
    while (infile.getline(line, 80))              // E 
        cout << line << endl;
    infile.close();                                  // F 
    return 0;
}
