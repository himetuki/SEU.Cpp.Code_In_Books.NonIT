#include <iostream>
using namespace std;

class N;     				 // A����N��������˵��

class M
{
    int a, b;
public:
    M(int x, int y) { a = x; b = y; }
    void Print(){ cout << "a=" << a << '\t' << "b=" << b << endl; }

    void Setab(N &); 	// B��Setab()��M��ĳ�Ա�������������N����������  
};

class N
{
    int c, d;
public:
    N(int x, int y) { c = x; d = y; }
    void Print() { cout << "c=" << c << '\t' << "d=" << d << endl; }

    friend void M::Setab(N&);	// C������M�ĳ�Ա����Setab()˵���ɱ������Ԫ����
};

void  M::Setab(N &obj)			// ��M�ĳ�Ա����Setab( )����N����Ԫ������
{
    a = obj.c;  				// D�������Setab( )�п�ֱ�ӷ�����N��˽�г�Ա��
    b = obj.d;
}
int main( )
{
    M m(25, 40);
    N n(55, 66);

    cout << "m: "; m.Print();
    cout << "n: "; n.Print();
    m.Setab(n);
    cout << "m: "; m.Print();
    return 0;
}
