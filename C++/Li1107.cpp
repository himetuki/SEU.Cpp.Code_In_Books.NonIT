#include <iostream>
using namespace std;

class B;     // ���������˵��

class A      // ����Ĭ�Ϸ���Ȩ����˽�е�
{
    int x;
    void Disp() { cout << "x=" << x << endl; }   // ˽�г�Ա���� 

    friend B;                               			// ��B��˵����A�����Ԫ��
};

class B
{
public:
    void Set(int n)
    {
        A a;
        a.x = n;     //�ɷ���A������˽�����ݳ�Աx
        a.Disp();    //�ɷ���A������˽�г�Ա����Disp( )
    }
};

int main(void)
{
    B b;
    b.Set(3);
    return 0;
}
