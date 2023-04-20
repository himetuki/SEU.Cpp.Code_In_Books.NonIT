//��15.13��ʹ����ģ��ʵ�ֶ����������������Ĵ���Դ������ΪLi1513.cpp
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
		cout<< "�����±�Խ�����! " << endl;
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

	cout << "��������Ҫ������������Ԫ�ظ�����";
	cin >> num;

	Vector <int>     iVector(num);          //D������������������
	Vector <double>  dVector(num);         //E������˫���ȸ�������������
	Vector <char>    cVector(num);         //F�������ַ�����������

	for(i=0; i<num; i++)  
	{
		iVector[i] = i;	
		dVector[i] = i;	
	}

	cVector ='A';	
	cout.setf(ios::showpoint);        //��ʾ��������С������
	cout << setw(10) << "iVector" << setw(15) << "dVector" << "  " << "cVector" << endl;
	for(i=0; i<num; i++)  
	{
		cout << setw(10) << iVector[i] << setw(15) << dVector[i]<< "  " << cVector[i] << endl;
	}
	
	return 0;
}
