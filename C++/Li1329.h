// Li1329.h                   				// 链表的通用操作部分
#include <iostream>
#include <cstring>
using namespace std;

class Object                   			// 数据对象抽象类，用于派生实际数据对象
{
public:
	Object( ){}
	virtual int IsEqual(Object &)=0; 			// 纯虚函数，完成两个数据对象的比较
	virtual void Show( )=0;          		// 纯虚函数，显示数据对象
	virtual ~Object( ){}             		// 虚析构函数  
};

class Node                          		// 链表结点类
{
    Object *Info;                   		// 指向数据对象的指针
	Node *Prev, *Next;              		// 指向前、后链表结点的指针
public:
	Node( ){ Info=NULL; Prev=NULL; Next=NULL; }
	Node(Node &node)                		// 拷贝构造函数 
	{
		Info=node.Info;
		Prev=node.Prev;
		Next=node.Next;
	}
	void FillInfo(Object *obj)      			// 使Node结点的Info指针指向数据对象
	{ Info = obj; }
	friend class List;              			// 将List类定义为Node类的友元类
};

class List                          		// 双向链表类
{
	Node *Head, *Tail;              		// 链表首、尾指针
public:
	List( ){ Head=Tail=NULL; };     		// 置为空链表
	~List( ){ DeleteList( ); }
	void AddNode(Node*);            		// 在链表尾加入一个结点
	Node * DeleteNode(Node*);       		// 从链表中摘除一个结点，返回被摘除的结点指针
	Node * LookUp(Object&);         		// 在链表中查找指定结点
	void ShowList( );               		// 输出链表中全部结点的数据对象的信息
	void DeleteList( );             			// 释放链表中全部结点空间
};
void List::AddNode(Node * node)     			// 在链表尾加入一个结点
{
	if(Head==NULL)                  		// 条件成立，为空链表，此时插入第一个结点
	{
		Head=Tail=node;             		// 链首和链尾均指向该结点  
		node->Next=node->Prev=NULL;	// 将该结点的前、后指针置为空指针
	}
	else                            		// 链表不空，将该结点加入链表尾
	{	
		Tail->Next = node;         		// 原链表尾结点的后指针指向该结点
		node->Prev=Tail;           		// 该结点的前指针指向原链表尾结点
		node->Next=NULL;           	// 该结点的后指针为空指针
		Tail=node;                  		// 将链表的尾指针指向新加入的结点
	}
}
Node * List::DeleteNode(Node * node) 			// node是待删除结点的指针 
{                                   		// 从链表中摘除一个结点，返回被摘除的结点指针
	if(node==Head)                  		// 待摘除的结点是首结点
		if(node==Tail)              		// 此条件若成立，表示链表中只有一个结点
			Head=Tail=NULL;
		else    
		{
			Head = node->Next;      	// 摘除首结点
			Head->Prev = NULL;
		}
	else   
	{                              		// 待摘除的结点不是首结点
		node->Prev->Next = node->Next;	// 置其前一结点的后指针
		if(node == Tail)            		// 待摘除的结点是尾结点
			Tail = node->Prev;     		// 重置链表尾指针
		else 
			node->Next->Prev = node->Prev; // 置其后一结点的前指针 
	}
	node->Prev = node->Next = NULL;		// 将摘除结点的前、后指针置为空 
	return(node);                   		// 返回已摘除结点的首指针 
}
Node * List::LookUp(Object & obj)   			// A，在链表中查找值为obj的结点
{
	Node *pn=Head;
	while(pn)
	{
		if(pn->Info->IsEqual(obj)) 		// B，调用派生类的IsEqual(obj)函数
			return pn;               		// 若找到要查找的结点，返回链表中该结点的指针
		pn = pn->Next;
	}
	return NULL;                     		// 若找不到，则返回空指针
}
void List::ShowList( )               			// 输出链表中全部结点的值
{	
	Node *p = Head;
	while(p)
	{
		p->Info->Show( );         		// C，调用派生类的Show( )函数
		p = p->Next;
	}
}
void List::DeleteList( )             			// 释放链表中全部结点空间
{	
	Node *p1, *p2;
	
	p1 = Head;
	while(p1)
	{
		delete p1->Info;             		// D，先释放数据对象的动态空间
		p2 = p1;
		p1 = p1->Next;
		delete p2;                   		// 再释放Node结点的动态空间
	}
}
