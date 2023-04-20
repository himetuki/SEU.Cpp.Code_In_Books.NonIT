#include <iostream>
using namespace std;

class Sample
{
    int x, y;
public:
    Sample(int a = 0, int b = 0) : x(a), y(b) { }
    void Show() {  cout << "x=" << x << ", y=" << y << "\n";  }
    friend int main();												// A 
};
int main()
{
    Sample s(3, 6);

    cout << "x=" << s.x << ", y=" << s.y << "\n";					// B 
    s.Show();
    return 0;
}
