#include <iostream>
using namespace std;

class RMB                           //定义一个"人民币"类 
{
	int Yuan, Jiao, Fen;             //元、角、分 
public:
	RMB(int y = 0, int j = 0, int f = 0)
	{
		Yuan = y; Jiao = j; Fen = f;
	}
	operator int()                   //转换成整数值(结果单位：分)
	{
		return (Yuan * 100 + Jiao * 10 + Fen);
	}
	operator double()               //转换成实数值(结果单位：元)
	{
		return (Yuan + double(Jiao) / 10 + double(Fen) / 100);
	}
	int GetFen()                    //用成员函数转换成"分"值
	{
		return (Yuan * 100 + Jiao * 10 + Fen);
	}
};
int main()
{
	RMB  r(23, 8, 6);
	int r1, r2, r3;

	r1 = r;                          //A 处理成 r1 = int(r);本质与B行一致
	r2 = int(r);                      //B 处理成 r2 = r.operator int( );
	r3 = r.GetFen();                 //C 调用成员函数得到分值 
	cout << "r1=" << r1 << endl;
	cout << "r2=" << r2 << endl;
	cout << "r3=" << r3 << endl;

	double d;

	d = r;                           //D 处理成 d = r.operator double( );
	cout << "d=" << d << endl;
	return 0;
}
