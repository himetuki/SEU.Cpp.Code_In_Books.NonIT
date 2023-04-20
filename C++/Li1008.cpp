#include <iostream>
using namespace std;

class  Date
{
    int Year, Month, Day;
public:
    void ShowDate()
    {
        cout << Year << '.' << Month << '.' << Day << endl;
    }
};
int main()
{
    Date d;                       // A 

    d.ShowDate();
    return 0;
}
