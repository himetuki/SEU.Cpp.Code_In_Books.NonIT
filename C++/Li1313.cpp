#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Array
{
	int Length;                                            	// 数组元素个数
	int *Arrp;                                             	// 数组首指针 
public:
	Array(int size = 0);
	~Array() { if (Arrp) delete[]Arrp; }
	int GetLen() { return Length; }
	int & operator[](int index);
	void operator=(Array &arr);
};
Array::Array(int size)
{
	Length = size;
	Arrp = NULL;
	if (Length)
	{
		Arrp = new int[Length];
		memset(Arrp, 0, sizeof(int)*Length);         	// A 
	}
}
int & Array::operator[](int index)                   	// B，返回引用
{
	if (index >= Length || index<0)
	{
		cout << "Error: 下标 " << index << " 越界\n";	// C
		exit(1);
	}
	return Arrp[index];
}
void Array::operator=(Array &arr)					// D
{
	if (this == &arr)
	{
		cout << "数组自身赋值" << endl;
	}
	if (Arrp)delete[]Arrp;
	Length = arr.Length;
	Arrp = NULL;
	if (Length)
	{
		Arrp = new int[Length];
		for (int i = 0; i<arr.GetLen(); i++)
			Arrp[i] = arr.Arrp[i];
	}
}
int main()
{
	int size, i;

	cin >> size;                                         	// 输入数组的大小 
	Array arr1(size), arr2;
	for (i = 0; i<size; i++)
		cin >> arr1[i];                                 	// E 
	arr2 = arr1;                                         	// F，数组整体赋值 
	for (i = 0; i<arr2.GetLen(); i++)
		cout << arr2[i] << '\t';                      	// G 
	cout << endl;
	cout.flush();
	arr2[5] = 3;                                        	// H 
	cout << arr2[5] << endl;
	arr2 = arr2;                                           // I
	return 0;
}
