#include <iostream>
using namespace std;

int  main()
{
	int x = 165, y = 142;

	cout.setf(ios::oct, ios::basefield);  	// A����Ϊ�������Ϊ�˽�����
	cout << x << ',' << y << endl;
	cout.setf(ios::showbase);         		// B
	cout << x << ',' << y << endl;
	cout.width(8);   						// C ����������Ϊ8��ֻ������һ����������Ч
	cout.fill('*');                    		// ��������ַ�Ϊ *
	cout.setf(ios::left, ios::adjustfield);	// �������Ϊ�����
	cout << x << ',' << y << endl;
	cout.setf(ios::hex, ios::basefield);	// ����Ϊ�������Ϊʮ��������
	cout << x << ',' << y << endl;
	cout.unsetf(ios::showbase); 			// �������������ʱ��ǰ�治����ʾ���Ƶ�ǰ���ַ�
	cout << x << ',' << y << endl;
	return 0;
}
