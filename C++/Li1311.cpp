#include <iostream>
using namespace std;

class RMB                           //����һ��"�����"�� 
{
	int Yuan, Jiao, Fen;             //Ԫ���ǡ��� 
public:
	RMB(int y = 0, int j = 0, int f = 0)
	{
		Yuan = y; Jiao = j; Fen = f;
	}
	operator int()                   //ת��������ֵ(�����λ����)
	{
		return (Yuan * 100 + Jiao * 10 + Fen);
	}
	operator double()               //ת����ʵ��ֵ(�����λ��Ԫ)
	{
		return (Yuan + double(Jiao) / 10 + double(Fen) / 100);
	}
	int GetFen()                    //�ó�Ա����ת����"��"ֵ
	{
		return (Yuan * 100 + Jiao * 10 + Fen);
	}
};
int main()
{
	RMB  r(23, 8, 6);
	int r1, r2, r3;

	r1 = r;                          //A ����� r1 = int(r);������B��һ��
	r2 = int(r);                      //B ����� r2 = r.operator int( );
	r3 = r.GetFen();                 //C ���ó�Ա�����õ���ֵ 
	cout << "r1=" << r1 << endl;
	cout << "r2=" << r2 << endl;
	cout << "r3=" << r3 << endl;

	double d;

	d = r;                           //D ����� d = r.operator double( );
	cout << "d=" << d << endl;
	return 0;
}
