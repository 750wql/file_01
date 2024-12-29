#include<bits/stdc++.h>
#include<cstddef>
#include<iostream>
using namespace std;
//STL standard template lib

typedef struct DoubleLinkList{
	int data;			//结点的数据域 
	DoubleLinkList* next;//下一个结点的指针域 
	DoubleLinkList* prev;//上一个结点的指针域 
}DoubleLinkList,DoubleLinkNode;

bool DoubleLinkListInit(DoubleLinkList* &L){		//构造一个空的双向链表 
	L=new DoubleLinkNode;	//生成新结点作为头结点，用头指针L指向新结点 
	if(!L) return false;	//生成结点失败 
	
	L->next=NULL;		//头结点的next指针域指空 
	L->prev=NULL;		//头结点的prev指针域指空 
	L->data=-1;
	
	return true;
}

//前插法 
bool DoubleLinkListInsertFront(DoubleLinkList*& L,DoubleLinkNode* node)
{
	if(!L||!node) return false;
	
	if(L->next == NULL)		//只有头结点 
	{
		node->next=NULL;
		node->prev=L;		//新结点的prev指针指向头结点 
		L->next=node; 		//头结点的next指针指向新结点 
	}
	else
	{
		L->next->prev=node;		//
		node->next = L->next;
		node->prev = L;
		L->next = node;
	}
	return true;
}

bool DoubleLinkListInsertBack(DoubleLinkList*& L,DoubleLinkNode* node)
{
	DoubleLinkNode* last=NULL;
	if(!L||!node) return false;
	last=L;
	while(last->next) last=last->next;
	
	node->next=NULL;
	node->prev=last;
	last->next=node;
	
	return true;
}

void DoubleLinkListPrint(DoubleLinkList* &L)
{
	DoubleLinkNode* p=L;
	if(!L)
	{
		cout<<"链表为空"<<endl;
		return;
	}
	cout<<p->data<<" ";
	while(p->next)
	{
		cout<<p->next->data<<" ";
		p=p->next;
	}
	
	cout<<endl<<"逆向打印"<<endl;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->prev;
	 } 
	 cout<<endl;
	 
	 return;
}

bool DoubleLinkListInsert(DoubleLinkList* L,int i,int e)
{
	if(!L||!L->next) return false;
	if(i<1) return false;
	
	int j=0;
	DoubleLinkList* p,* s;
	p=L;
	
	while(p&&j<i)
	{
		p=p->next;
		j++;
	 } 
	 
	 if(!p||j<i)
	 {
	 	p=p->next;
	 	j++;
	 }
	 if(!p||j!=i)
	 {
	 	cout<<"结点不存在"<<i<<endl;
	 	return false;
	 }
	 
	 s=new DoubleLinkNode;
	 s->data=e;
	 
	 s->next=p;
	 s->prev=p->prev;
	 
	 p->prev->next=s;
	 p->prev=s;
	 
	 return true;
}

bool DoubleLinkListGetElem(DoubleLinkList* &L,int i,int& e)
{
	int index;
	DoubleLinkList* p;
	
	if(!L||!L->next) return false;
	
	p=L->next;
	index=1;
	while(p||index<i)
	{
		p=p->next;
		index++;
	}
	if(!p||index>i)
	{
		return false;
	}
	e=p->data;
	
	return true;
}

bool DoubleLinkListDelete(DoubleLinkList*& L,int i)
{
	DoubleLinkList* p;
	int index=0;
	if(!L||!L->next)
	{
		cout<<"双向链表为空！"<<endl;
		return false;
	}
	if(i<1)
	{
		cout<<"不能删除头结点！"<<endl;
		return false;
	}
	p=L;
	while(p&&index<i)
	{
		p=p->next;
		index++;
	}
	if(!p) return false;
	
	p->prev->next=p->next;
	if(p->next!=NULL)
	{
		p->next->prev=p->prev;
	}
	delete p;
	
	return true;
}

void DoubleLinkListDestroy(DoubleLinkList* &L)
{
	DoubleLinkList* p=L;
	cout<<"销毁链表"<<endl;
	
	while(p)
	{
		L=L->next;
		delete p;
		p=L;
	}
}
int main()
{
	DoubleLinkList* L;
	DoubleLinkList* s;
	
	if(DoubleLinkListInit(L))
	{
		cout<<"初始化链表成功！"<<endl;
		}	
	else
	{
		cout<<"初始化链表失败！"<<endl;
	}
	
	int n;
	cout<<"使用前插法创建双向链表"<<endl;
	cout<<"请输入元素个数";
	cin>>n;
	cout<<endl<<"依次输入"<<n<<"个元素：";
	
	while(n>0)
	{
		s=new DoubleLinkNode;
		cin>>s->data;
		DoubleLinkListInsertFront(L,s);
		n--;
	}
	
	DoubleLinkListPrint(L);
	
	for(int j=0;j<3;j++)
	{
		int i,x;
		cout<<"请输入要插入的位置和元素（用空格隔开）：";
		cin>>i>>x;
		
		if(DoubleLinkListInsert(L,i,x))
		{
			cout<<"插入成功！"<<endl;
		 } 
		else
		{
			cout<<"插入失败！"<<endl;
		}
		DoubleLinkListPrint(L);
	}
	
	if(DoubleLinkListDelete(L,2))
	{
		cout<<"删除链表第2个元素成功"<<endl;
	}
	else 
	{
		cout<<"删除链表第2个元素失败"<<endl; 
	}
	
	DoubleLinkListPrint(L);
	
	DoubleLinkListDestroy(L);
	
	return 0;
}

 
