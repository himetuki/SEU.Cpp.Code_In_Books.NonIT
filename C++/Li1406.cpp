#include <iostream>
using namespace std;

int main()
{
	char c1, c2, c3;

	cin.unsetf(ios::skipws);        		// A����Ϊ�������հ��ַ� 
	cin >> c1 >> c2 >> c3;             	        // B
	cout << c1 << c2 << c3 << '#' << endl;
	cin.setf(ios::skipws);               	// C ����Ϊ�����հ��ַ�

	int x, y;

	cin.setf(ios::hex, ios::basefield);  		// ������������Ϊʮ��������
	cin >> x >> y;
	cout << x << ',' << y << endl;
	return 0;
}

/*��C��ɾ��������������̲Ĳ�ͬ
a b c
a b#
-858993460,-858993460
*/
/* ��Ȼ�����ͬ����ԭ���ǶԵ� */