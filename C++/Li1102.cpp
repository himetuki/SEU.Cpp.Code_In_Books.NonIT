#include <iostream>
using namespace std;

class Sample
{
    int a;
    static int b;                           	// ����˽�о�̬���ݳ�Ա 
public:
    static int c;                      		// ���幫�о�̬���ݳ�Ա 
    Sample(int x) { a = x; b += x; }
    static void disp(Sample s)            // A�����徲̬��Ա���� 
    {
        cout << "a=" << s.a << ", b=" << b << endl;  // B
    }    							// ��ǰ�У����ʷǾ�̬���ݳ�Ա�;�̬���ݳ�Ա  
};

int Sample::b = 10; 				// C����ʼ����̬���ݳ�Ա 
int Sample::c = 20; 				// D����ʼ����̬���ݳ�Ա 

int main()
{
    Sample s1(2), s2(3);

    Sample::disp(s1);  		   	// E���ɸ�дΪs1.disp(s1);��s2.disp(s1);
    Sample::disp(s2);  		    	// F���ɸ�дΪs1.disp(s2);��s2.disp(s2);
    cout << "c=" << Sample::c << endl;	// G��Sample::c �ɸ�дΪ s1.c �� s2.c
    return 0;
}
