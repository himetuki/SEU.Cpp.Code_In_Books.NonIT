#include <iostream>
using namespace std;

int main()
{
	int x = 97, y = 98;
	char c1 = 'A', c2 = 'B';

	cout << c1 << c2 << char(x) << char(y) << endl;						// A 
	cout.put(c1).put(c2).put(char(x)).put(char(y)).put('\n');   // B

	char s[100] = "programming\nlanguage\n";

	cout.write(s, 5);                                  // C 
	cout.write(s + 5, 5);                                // D 
	cout.write(s + 10, 5);                               // E 
	cout << endl;
	return 0;
}
