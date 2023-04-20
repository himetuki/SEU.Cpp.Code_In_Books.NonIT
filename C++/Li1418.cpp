#include <iostream>
#include <cstring>
using namespace std;

class Date
{
	int year, month, day;                    // Äê¡¢ÔÂ¡¢ÈÕ
	void itoa(int n, char *s, int fixlen)   // A
	{
		int i, j, t;

		for (i = 0; n; n = n / 10, i++)
			s[i] = n % 10 + '0';
		for (; i<fixlen; i++)
			s[i] = '0';
		s[i] = '\0';

		for (j = 0; j<i / 2; j++)                // ÄæÖÃ
		{
			t = s[j]; s[j] = s[i - 1 - j]; s[i - 1 - j] = t;
		}
	}
	int atoi(char *s)                       // B
	{
		int n = 0;

		for (; *s; s++)	n = n * 10 + *s - '0';
		return(n);
	}
public:
	Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
	void InputDate(istream &in)
	{
		char y[10], m[10], d[10];

		in.getline(y, 10, '/');             // C
		in.getline(m, 10, '/');             // D
		in.getline(d, 10, '\n');            // E
		year = atoi(y);
		month = atoi(m);
		day = atoi(d);
	}
	void ShowDate(ostream &out)
	{
		char DateStr[20];
		char temp[10];

		itoa(year, DateStr, 4);
		itoa(month, temp, 2);
		strcat(DateStr, "/");
		strcat(DateStr, temp);
		itoa(day, temp, 2);
		strcat(DateStr, "/");
		strcat(DateStr, temp);
		out << DateStr;
	}
};
istream& operator>>(istream &in, Date &d)         // F
{
	d.InputDate(in);
	return in;
}
ostream& operator<<(ostream &out, Date &d)       // G
{
	d.ShowDate(out);
	return out;
}
int main()
{
	Date d1(1999, 3, 8), d2(2003, 5, 16);

	cout << d1 << endl << d2 << endl;
	cin >> d1;
	cout << d1 << endl;
	return 0;
}
----------------------------------------------------------
void  itoa(int n, char *s, int fixlen)
{
	int i;
	s[fixlen] = '\0';
	for (i = fixlen - 1; n>0; i--, n /= 10) s[i] = n % 10 + '0';
	for (; i >= 0; i--) s[i] = '0';
}
