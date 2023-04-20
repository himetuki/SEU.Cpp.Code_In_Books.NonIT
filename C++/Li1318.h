//Li1318.h
class String
{
protected:
	int Length;   //�ַ����ĳ��� 
	char *Strp;   //ָ���ַ�����ָ�� 
public:
	String( ){ Strp=NULL; Length=0; } //ȱʡ���캯��
	String(const char *s); //���캯��,���ַ�ָ����Ϊ����
	String(const String &);
//�������캯��,���ַ��������������Ϊ����
	~String( )
	{ if(Strp) delete [ ] Strp; }
	const char *IsIn( const char ) const; 
//���ز����ַ����ַ����е�һ�γ��ֵĵ�ַ
	bool IsSubStr(const char *) const; 
//�жϲ����ַ����Ƿ�Ϊ�Ӵ� 
	void Show( )                 //����ַ���
	{ cout << Strp << '\n'; }

	int GetLen( ) { return Length; } //�����ַ����ĳ���
	
const char * GetString( ) { return Strp; } 
//ȡ�ַ�����ָ��

	operator const char * ( ) const  
//A������ת������������ָ�������ַ���ָ��
	{ return (const char *) Strp; }

	String & operator = (String &); //���ظ�ֵ����� 
	friend String operator+(const String &, const String & );
                         //��Ԫʵ��+���� 
	friend String operator-(const String &, const char * );
                //��Ԫʵ�֣����� 
	int operator < ( const String &) const;
	int operator > ( const String &) const;
	int operator == ( const String &) const;
};

String::String(const char *s)  
//���캯�������ַ�ָ����Ϊ���� 
{	if(s)
	{	Length = strlen(s);
		Strp = new char[Length+1];
		strcpy(Strp, s);
	}
	else
	{ Strp = NULL; Length = 0; }
} 

String::String(const String &s) //�������캯�������ַ��������������Ϊ���� 
{	Length = s.Length;
	if(s.Strp)
	{	Strp = new char[Length+1];
		strcpy(Strp, s.Strp);
	}
	else Strp = NULL;
}

const char *String::IsIn( const char c) const // �ж��ַ�c�Ƿ����ַ�����, �����,�������һ�γ���ʱ�ĵ�ַ, ���򷵻ؿ�ָ��NULL
{	char *p=Strp;
	while(*p)
	  if(*p++ == c) return --p;
	return NULL;
}

bool String::IsSubStr(const char *s) const //�ж�s��ָ����ַ����Ƿ�Ϊ�����ַ������Ӵ������ǣ�����true�������ǣ�����false��
{
	if(strstr(Strp, s)) return true;  
// strstr( ) Ϊ�ַ�������⺯���������Ӵ��׵�ַ
	else return false;
}

String & String::operator = (String &s) //ʵ�ָ�ֵ����
{
	if( this == & s ) return *this;	//�����ַ�������ֵ
	if(Strp) delete [ ] Strp;   //�ͷŶ�������Ŀռ�
	Length = s.Length;
	if(s.Strp)
	{	Strp = new char[Length+1];
		strcpy(Strp, s.Strp);
	}
	else Strp = NULL;
	return *this;
}

String operator+(const String &s1, const String &s2 )
 //ƴ�������ַ���
{	String t;
	t.Length = s1.Length + s2.Length;
	t.Strp = new char [ t.Length + 1 ];
	strcpy(t.Strp, s1.Strp);
	strcat(t.Strp, s2.Strp);
	return t;
}

String operator-(const String &s1, const char *s2 ) // D  ɾ��s1�е�һ�γ��ֵ�s2
{	String t;
	char *p1=s1.Strp, *p2;
	int i=0, len=strlen(s2);
	if(p2=strstr(s1.Strp, s2)) // ������Ӵ�
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

int String::operator < ( const String &s) const // ʵ��С�ڱȽϣ���Ա����ʵ�� 
{ return(strcmp(Strp, s.Strp)<0 ); }

int String::operator > ( const String &s) const // ʵ�ִ��ڱȽϣ���Ա����ʵ��
{ return(strcmp(Strp, s.Strp)>0 ); }

int String::operator == ( const String &s) const // ʵ�ֺ���ڱȽϣ���Ա����ʵ��
{ return(strcmp(Strp, s.Strp)==0 ); }
