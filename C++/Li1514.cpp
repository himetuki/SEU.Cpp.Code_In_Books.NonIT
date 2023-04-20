//例15.14：使用类模板的友元函数实现多种数据类型向量的处理。源程序名为Li1514.cpp
#include  <iostream>
#include  <iomanip>
using namespace std;

template  < typename T >  
class  Vector
{
	template < typename TT > friend  ostream&  operator<<(ostream& os, Vector <TT> &array); 	// A 
private:
	T*  data;
	int    size;
public:
	Vector(int s);
	~Vector( );
	T&  operator [ ] (const  int  index);
	void  operator = (T  value);
};

template  <typename T>  
Vector <T> :: Vector(int s)
{
	size = s;
	data = new T[size];
	
	for(int i=0; i<size; i++)
		data[i] = 0;
}

template  <typename T> 
Vector  <T> :: ~Vector( )
{
	delete  [ ] data;         
}

template  <typename T>  
T&  Vector  <T> :: operator[ ](const int index)
{
	return  data[index];
}

template  <typename T>  
void  Vector  <T> :: operator = (T value)
{
	for(int i=0; i<size; i++)
		data[i] = value;
}

template  <typename TT> 
ostream&  operator << (ostream& os, Vector <TT> &array)
{
	for(int i=0; i<array.size; i++)
		os << array.data[i] << endl;
	return  os;
}

int  main( )
{
	int num;

	cout << "请输入需要建立的数组的元素个数：";
	cin >> num;

	Vector <int>     iVector(num);          // 建立整型向量对象
	Vector <double>  dVector(num);         // 建立双精度浮点型向量对象
	Vector <char>    cVector(num);         // 建立字符型向量对象

	iVector = 100;
	dVector = 7.56;
	cVector = 'A';

	cout.setf(ios::showpoint);               //显示浮点数的小数部分
	cout << "The integer type class:" << endl << iVector << endl;
	cout << "The double floating type class:" << endl << dVector << endl;
	cout << "The character type class:" << endl << cVector << endl;
	
	return 0;
}
