#include <iostream>
using namespace std;

class F
{
public:
	double operator( )(double x, double y)
	{
		return (x + 5)*y;
	}
};
int main()
{
	F f;

	cout << "f(1.5, 2.2)=" << f(1.5, 2.2) << endl;  //A
	cout << "f(1.2, 9.3)=" << f(1.2, 9.3) << endl;  //B
	return 0;
}
