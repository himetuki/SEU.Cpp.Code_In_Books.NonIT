#include <iostream>
using namespace std;

int main()
{
	double x = 12.3456789;
	int pre = cout.precision();                 // ���ȱʡ���� 

	cout << "default precision = " << pre << endl;
	cout << x << endl;
	cout.precision(4);                           // A ���þ���
	cout << x << endl;
	cout.precision(6);
	cout.setf(ios::fixed, ios::floatfield);     // B �����Զ�������ʽ���
	cout << x << endl;
	cout.precision(2);
	cout << x << endl;
	cout.setf(ios::scientific, ios::floatfield);  // C �����Կ�ѧ��ʾ����ʽ���
	cout << x << endl;
	return 0;
}
