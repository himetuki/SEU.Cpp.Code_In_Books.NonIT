#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double d1 = 12.3456789, d2 = 123456.789, d3 = 0.0000123456;

	cout << d1 << ',' << d2 << ',' << d3 << endl;
	cout << setw(10) << d1 << ',' << setw(10) << d2 << ',' << setw(10) << d3 << endl;   // A

	char s[10] = "abcd", c = 'k';

	cout << s << ',' << setw(4) << c << endl;
	return 0;
}