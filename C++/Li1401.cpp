#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x;
	cout << "Please input x:";  
	cin >> x;
	if (x<0)
		cerr << x << " is not a positive number!\n"; 
	else
		clog << "The square root of " << x << " is " << sqrt(x) << endl;  
	return 0;
}
