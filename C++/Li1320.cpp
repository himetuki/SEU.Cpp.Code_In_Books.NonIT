#include <iostream>
using namespace std;

int add(int a, int b){ return(a + b); }				// ���غ���1

double add(double a, double b) { return(a + b); }		// ���غ���2

int main()
{
	cout << add(1, 2) << '\t';							// ����ʱȷ���������غ���1
	cout << add(1.1, 2.2) << '\n';						// ����ʱȷ���������غ���2
	return 0;
}
