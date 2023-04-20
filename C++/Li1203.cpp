#include <iostream>
using namespace std;

class Base1
{
protected:
    int data1;
public:
    Base1(int a = 0)
    {
        data1 = a;
        cout << "Base1 Constructor\n";
    }
    ~Base1()
    {
        cout << "Base1 Destructor\n";
    }
};

class Base2
{
protected:
    int data2;
public:
    Base2(int a = 0)
    {
        data2 = a;
        cout << "Base2 Constructor\n";
    }
    ~Base2() {  cout << "Base2 Destructor\n";  }
};

class Derived : public Base1, public Base2                  // A
{
    int d;
public:
    Derived(int x, int y, int z) : Base1(x), Base2(y)      // B
    {
        d = z;  cout << "Derived Constructor\n";
    }

    ~Derived() {  cout << "Derived Destructor\n";  }

    void Show( )
    {
        cout << data1 << ',' << data2 << ',' << d << endl;
    }
};
int main()
{
    Derived  c(1, 2, 3);

    c.Show();
    return 0;
}
