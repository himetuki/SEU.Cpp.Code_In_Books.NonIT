#include <iostream>
using namespace std;

class Sample
{
    int n;
    static int sum;
public:
    Sample(int x) { n = x; }
    void add() { sum += n; }
    void disp() { cout << "n=" << n << ",sum=" << sum << endl; }
};

int Sample::sum = 0;      //静态数据成员初始化，或int Sample::sum;

int main()
{
    Sample a(2), b(3), c(5);

    a.add();    a.disp();
    b.add();    b.disp();
    c.add();    c.disp();
    // A
    cout << "sizeof(a) : " << sizeof(a) << endl;
    cout << "sizeof(b) : " << sizeof(b) << endl;
    cout << "sizeof(c) : " << sizeof(c) << endl;
    return 0;
}
