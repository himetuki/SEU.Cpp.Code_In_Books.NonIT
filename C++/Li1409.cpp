#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double x = 12.3456789;

	cout << x << endl;
	cout << setprecision(4) << x << endl;
	cout.setf(ios::fixed, ios::floatfield);    // �����Զ�������ʽ���
	cout << x << endl;
	cout.setf(ios::scientific, ios::floatfield);  // �����Կ�ѧ��ʾ����ʽ���
	cout << setprecision(2) << x << endl;
	return 0;
}
