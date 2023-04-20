//Li1318.h
class String
{
protected:
	int Length;   //字符串的长度 
	char *Strp;   //指向字符串的指针 
public:
	String( ){ Strp=NULL; Length=0; } //缺省构造函数
	String(const char *s); //构造函数,以字符指针作为参数
	String(const String &);
//拷贝构造函数,以字符串对象的引用作为参数
	~String( )
	{ if(Strp) delete [ ] Strp; }
	const char *IsIn( const char ) const; 
//返回参数字符在字符串中第一次出现的地址
	bool IsSubStr(const char *) const; 
//判断参数字符串是否为子串 
	void Show( )                 //输出字符串
	{ cout << Strp << '\n'; }

	int GetLen( ) { return Length; } //返回字符串的长度
	
const char * GetString( ) { return Strp; } 
//取字符串首指针

	operator const char * ( ) const  
//A，类型转换函数，返回指向常量的字符串指针
	{ return (const char *) Strp; }

	String & operator = (String &); //重载赋值运算符 
	friend String operator+(const String &, const String & );
                         //友元实现+重载 
	friend String operator-(const String &, const char * );
                //友元实现－重载 
	int operator < ( const String &) const;
	int operator > ( const String &) const;
	int operator == ( const String &) const;
};

String::String(const char *s)  
//构造函数，以字符指针作为参数 
{	if(s)
	{	Length = strlen(s);
		Strp = new char[Length+1];
		strcpy(Strp, s);
	}
	else
	{ Strp = NULL; Length = 0; }
} 

String::String(const String &s) //拷贝构造函数，以字符串对象的引用作为参数 
{	Length = s.Length;
	if(s.Strp)
	{	Strp = new char[Length+1];
		strcpy(Strp, s.Strp);
	}
	else Strp = NULL;
}

const char *String::IsIn( const char c) const // 判断字符c是否在字符串中, 如果在,返回其第一次出现时的地址, 否则返回空指针NULL
{	char *p=Strp;
	while(*p)
	  if(*p++ == c) return --p;
	return NULL;
}

bool String::IsSubStr(const char *s) const //判断s所指向的字符串是否为类中字符串的子串。若是，返回true；若不是，返回false。
{
	if(strstr(Strp, s)) return true;  
// strstr( ) 为字符串处理库函数，返回子串首地址
	else return false;
}

String & String::operator = (String &s) //实现赋值运算
{
	if( this == & s ) return *this;	//处理字符串自身赋值
	if(Strp) delete [ ] Strp;   //释放对象自身的空间
	Length = s.Length;
	if(s.Strp)
	{	Strp = new char[Length+1];
		strcpy(Strp, s.Strp);
	}
	else Strp = NULL;
	return *this;
}

String operator+(const String &s1, const String &s2 )
 //拼接两个字符串
{	String t;
	t.Length = s1.Length + s2.Length;
	t.Strp = new char [ t.Length + 1 ];
	strcpy(t.Strp, s1.Strp);
	strcat(t.Strp, s2.Strp);
	return t;
}

String operator-(const String &s1, const char *s2 ) // D  删除s1中第一次出现的s2
{	String t;
	char *p1=s1.Strp, *p2;
	int i=0, len=strlen(s2);
	if(p2=strstr(s1.Strp, s2)) // 如果是子串
	{	t.Length=s1.Length - len;
		t.Strp = new char[t.Length+1];
		while(p1<p2)
			t.Strp[i++]=*p1++;
		p1+=len;
		while(t.Strp[i++]=*p1++);
	return t;
	}
	else 
		return s1 ; 
}

int String::operator < ( const String &s) const // 实现小于比较，成员函数实现 
{ return(strcmp(Strp, s.Strp)<0 ); }

int String::operator > ( const String &s) const // 实现大于比较，成员函数实现
{ return(strcmp(Strp, s.Strp)>0 ); }

int String::operator == ( const String &s) const // 实现恒等于比较，成员函数实现
{ return(strcmp(Strp, s.Strp)==0 ); }
