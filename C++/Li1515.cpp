//��15.15��ʹ����ģ����ر���ʵ�ֶ��ַ����ݵ����⴦��Դ������ΪLi1515.cpp
#include  <iostream>
using namespace std;

template  < typename T >  
class  Test
{
private:
	T  val;
public:
	Test(T  var):val(var){}
	friend  ostream&  operator << (ostream& os, Test<T> &value)
	{
		os<<value.val<<endl;
		return os;
	}
};

//��ģ����ر��࣬���Դ���char��������
template  < >
class  Test  <char>
{
private:
	char  val;
public:
	Test(char  var):val(var){}
	void  operator = (char var);
};

int  main( )
{
	Test<int>     t1(30);       //�����������Ͷ���
	Test<char>    t2('C');      //�����ַ����Ͷ���
	
	cout << t1;
	cout << t2;       		 //����char���ر���û�����ض���<<�����
	
	return 0;
}
