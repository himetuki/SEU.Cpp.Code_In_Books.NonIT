//例15.13：使用类模板实现多种数据类型向量的处理。源程序名为Li1513.cpp
#include  <iostream>
#include  <iomanip>
using namespace std;

template  < typename  T >  
class  Vector
{
private:
	T*  data;
	int    size;
public:
	Vector(const  int  s);
	~Vector( );
	T&  operator [ ] (const  int  index);		//A
	void  operator = (T value);				//B
};

template  <typename T>                      //C
Vector <T> :: Vector(const  int  s)
{
	if( s > 0 )
	{
		size = s;
		data = new T[size];
		for(int i=0; i<size; i++)data[i] = 0;
	}
}

template  <typename T>  
Vector  <T> :: ~Vector( )
{
	if( data )delete [] data;
}

template  <typename T>  
T&  Vector  <T> :: operator[ ](const  int  index)
{
	if(index>=size || index<0)
	{ 
		cout<< "向量下标越界错误! " << endl;
		exit(1);
	}
	else 
		return  data[index];      
}

template  <typename T>  
void  Vector  <T> :: operator = (T value)
{
	for(int i=0; i<size; i++)
		data[i] = value;
}

int  main( )
{
     int num,i;

	cout << "请输入需要建立的向量的元素个数：";
	cin >> num;

	Vector <int>     iVector(num);          //D，建立整型向量对象
	Vector <double>  dVector(num);         //E，建立双精度浮点型向量对象
	Vector <char>    cVector(num);         //F，建立字符型向量对象

	for(i=0; i<num; i++)  
	{
		iVector[i] = i;	
		dVector[i] = i;	
	}

	cVector ='A';	
	cout.setf(ios::showpoint);        //显示浮点数的小数部分
	cout << setw(10) << "iVector" << setw(15) << "dVector" << "  " << "cVector" << endl;
	for(i=0; i<num; i++)  
	{
		cout << setw(10) << iVector[i] << setw(15) << dVector[i]<< "  " << cVector[i] << endl;
	}
	
	return 0;
}
