#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	double x;
	ofstream out;                       // ����һ�����������

	out.open("sqrttable.txt");          // ���ı��ļ�sqrttable.txt
	for (x = 1; x <= 100; x++)
		out << x << '\t' << sqrt(x) << endl;    // �����д���ļ�
	out.close();                       // �ر��ļ�
	return 0;
}
