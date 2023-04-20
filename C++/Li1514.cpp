//��15.14��ʹ����ģ�����Ԫ����ʵ�ֶ����������������Ĵ���Դ������ΪLi1514.cpp
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

	cout << "��������Ҫ�����������Ԫ�ظ�����";
	cin >> num;

	Vector <int>     iVector(num);          // ����������������
	Vector <double>  dVector(num);         // ����˫���ȸ�������������
	Vector <char>    cVector(num);         // �����ַ�����������

	iVector = 100;
	dVector = 7.56;
	cVector = 'A';

	cout.setf(ios::showpoint);               //��ʾ��������С������
	cout << "The integer type class:" << endl << iVector << endl;
	cout << "The double floating type class:" << endl << dVector << endl;
	cout << "The character type class:" << endl << cVector << endl;
	
	return 0;
}
