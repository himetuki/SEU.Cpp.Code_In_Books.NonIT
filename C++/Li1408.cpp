#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int x, y, a, b;

	cin >> hex >> x >> y;
	cin >> oct >> a >> b;
	cout << setw(8) << setfill('*') << x << ',' << setfill('$') << setw(4) << y << endl;
	cout << setiosflags(ios::left) << a << ',' << setw(8) << b << endl;
	return 0;
}
