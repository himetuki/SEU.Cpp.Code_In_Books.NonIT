#include <iostream>
using namespace std;

class Point
{
    int x;			  	// һ�����ݳ�Ա
    const int y;	  		// �����ݳ�Ա
public:
    Point(int a = 0, int b = 0) : x(a), y(b) { }

    int fun()         		// A��һ���Ա����
    {
        x = 5;        		// �޸�һ�����ݳ�Աx���Ϸ�
        y = 6;        		// �޸ĳ����ݳ�Ա��	�Ƿ�
        return x + y;   	// ��ȡx��y��		�Ϸ�
    }
    int fun() const   	// B������Ա���� 
    {
        x = 5;        		// �޸�һ�����ݳ�Աx���Ƿ�
        y = 6;        		// �޸ĳ����ݳ�Ա��    �Ƿ�
        return x + y;   	// ��ȡx��y��		�Ϸ�
    }
};
