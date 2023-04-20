// Li1329.h                   				// �����ͨ�ò�������
#include <iostream>
#include <cstring>
using namespace std;

class Object                   			// ���ݶ�������࣬��������ʵ�����ݶ���
{
public:
	Object( ){}
	virtual int IsEqual(Object &)=0; 			// ���麯��������������ݶ���ıȽ�
	virtual void Show( )=0;          		// ���麯������ʾ���ݶ���
	virtual ~Object( ){}             		// ����������  
};

class Node                          		// ��������
{
    Object *Info;                   		// ָ�����ݶ����ָ��
	Node *Prev, *Next;              		// ָ��ǰ�����������ָ��
public:
	Node( ){ Info=NULL; Prev=NULL; Next=NULL; }
	Node(Node &node)                		// �������캯�� 
	{
		Info=node.Info;
		Prev=node.Prev;
		Next=node.Next;
	}
	void FillInfo(Object *obj)      			// ʹNode����Infoָ��ָ�����ݶ���
	{ Info = obj; }
	friend class List;              			// ��List�ඨ��ΪNode�����Ԫ��
};

class List                          		// ˫��������
{
	Node *Head, *Tail;              		// �����ס�βָ��
public:
	List( ){ Head=Tail=NULL; };     		// ��Ϊ������
	~List( ){ DeleteList( ); }
	void AddNode(Node*);            		// ������β����һ�����
	Node * DeleteNode(Node*);       		// ��������ժ��һ����㣬���ر�ժ���Ľ��ָ��
	Node * LookUp(Object&);         		// �������в���ָ�����
	void ShowList( );               		// ���������ȫ���������ݶ������Ϣ
	void DeleteList( );             			// �ͷ�������ȫ�����ռ�
};
void List::AddNode(Node * node)     			// ������β����һ�����
{
	if(Head==NULL)                  		// ����������Ϊ��������ʱ�����һ�����
	{
		Head=Tail=node;             		// ���׺���β��ָ��ý��  
		node->Next=node->Prev=NULL;	// ���ý���ǰ����ָ����Ϊ��ָ��
	}
	else                            		// �����գ����ý���������β
	{	
		Tail->Next = node;         		// ԭ����β���ĺ�ָ��ָ��ý��
		node->Prev=Tail;           		// �ý���ǰָ��ָ��ԭ����β���
		node->Next=NULL;           	// �ý��ĺ�ָ��Ϊ��ָ��
		Tail=node;                  		// �������βָ��ָ���¼���Ľ��
	}
}
Node * List::DeleteNode(Node * node) 			// node�Ǵ�ɾ������ָ�� 
{                                   		// ��������ժ��һ����㣬���ر�ժ���Ľ��ָ��
	if(node==Head)                  		// ��ժ���Ľ�����׽��
		if(node==Tail)              		// ����������������ʾ������ֻ��һ�����
			Head=Tail=NULL;
		else    
		{
			Head = node->Next;      	// ժ���׽��
			Head->Prev = NULL;
		}
	else   
	{                              		// ��ժ���Ľ�㲻���׽��
		node->Prev->Next = node->Next;	// ����ǰһ���ĺ�ָ��
		if(node == Tail)            		// ��ժ���Ľ����β���
			Tail = node->Prev;     		// ��������βָ��
		else 
			node->Next->Prev = node->Prev; // �����һ����ǰָ�� 
	}
	node->Prev = node->Next = NULL;		// ��ժ������ǰ����ָ����Ϊ�� 
	return(node);                   		// ������ժ��������ָ�� 
}
Node * List::LookUp(Object & obj)   			// A���������в���ֵΪobj�Ľ��
{
	Node *pn=Head;
	while(pn)
	{
		if(pn->Info->IsEqual(obj)) 		// B�������������IsEqual(obj)����
			return pn;               		// ���ҵ�Ҫ���ҵĽ�㣬���������иý���ָ��
		pn = pn->Next;
	}
	return NULL;                     		// ���Ҳ������򷵻ؿ�ָ��
}
void List::ShowList( )               			// ���������ȫ������ֵ
{	
	Node *p = Head;
	while(p)
	{
		p->Info->Show( );         		// C�������������Show( )����
		p = p->Next;
	}
}
void List::DeleteList( )             			// �ͷ�������ȫ�����ռ�
{	
	Node *p1, *p2;
	
	p1 = Head;
	while(p1)
	{
		delete p1->Info;             		// D�����ͷ����ݶ���Ķ�̬�ռ�
		p2 = p1;
		p1 = p1->Next;
		delete p2;                   		// ���ͷ�Node���Ķ�̬�ռ�
	}
}
