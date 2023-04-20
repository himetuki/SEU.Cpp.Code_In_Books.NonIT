#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Matrix
{
	int Rows, Cols;		// ��ά���������������
	int *Mptr;			// ����ռ���ʼָ�루��һά�ռ��Ŷ�ά���飩
public:
	Matrix(int r = 0, int c = 0)
	{
		Rows = Cols = 0;
		Mptr = NULL;
		if (r && c)
		{
			Rows = r;
			Cols = c;
			Mptr = new int[r*c];
			memset(Mptr, 0, r*c*sizeof(int));
		}
	}
	~Matrix() { if (Mptr)delete[]Mptr; }

	int & operator ( )(int i, int j)  // ��������
	{
		if (i<0 || i >= Rows || j<0 || j >= Cols)
		{
			cout << "�±�Խ��!\n";
			exit(2);
		}
		return *(Mptr + i*Cols + j);     // A ���ض�ά�����i�е�j��Ԫ�ص�����
	}
	int GetRows() { return Rows; }
	int GetCols() { return Cols; }
};
int main()
{
	Matrix m(4, 4);
	int i, j;

	for (i = 1; i <= m.GetRows(); i++)
		for (j = 1; j <= m.GetCols(); j++)
			cin >> m(i, j);               // B
	for (i = 1; i <= m.GetRows(); i++)
	{
		for (j = 1; j <= m.GetCols(); j++)
			cout << m(i, j) << '\t';
		cout << endl;
	}
	return 0;
}

//-----------------------------------------
//�������޸�Ϊ��

int main()
{
	Matrix m(4, 4);
	int i, j;

	for (i = 0; i<m.GetRows(); i++)
		for (j = 0; j<m.GetCols(); j++)
			cin >> m(i, j);
	for (i = 0; i< m.GetRows(); i++)
	{
		for (j = 0; j<m.GetCols(); j++)
			cout << m(i, j) << '\t';
		cout << endl;
	}
	return 0;
}
