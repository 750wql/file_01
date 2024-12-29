#include<bits/stdc++.h>
#include<cstddef>
#include<iostream>
using namespace std;
//STL standard template lib

typedef struct DoubleLinkList{
	int data;			//���������� 
	DoubleLinkList* next;//��һ������ָ���� 
	DoubleLinkList* prev;//��һ������ָ���� 
}DoubleLinkList,DoubleLinkNode;

bool DoubleLinkListInit(DoubleLinkList* &L){		//����һ���յ�˫������ 
	L=new DoubleLinkNode;	//�����½����Ϊͷ��㣬��ͷָ��Lָ���½�� 
	if(!L) return false;	//���ɽ��ʧ�� 
	
	L->next=NULL;		//ͷ����nextָ����ָ�� 
	L->prev=NULL;		//ͷ����prevָ����ָ�� 
	L->data=-1;
	
	return true;
}

//ǰ�巨 
bool DoubleLinkListInsertFront(DoubleLinkList*& L,DoubleLinkNode* node)
{
	if(!L||!node) return false;
	
	if(L->next == NULL)		//ֻ��ͷ��� 
	{
		node->next=NULL;
		node->prev=L;		//�½���prevָ��ָ��ͷ��� 
		L->next=node; 		//ͷ����nextָ��ָ���½�� 
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
		cout<<"����Ϊ��"<<endl;
		return;
	}
	cout<<p->data<<" ";
	while(p->next)
	{
		cout<<p->next->data<<" ";
		p=p->next;
	}
	
	cout<<endl<<"�����ӡ"<<endl;
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
	 	cout<<"��㲻����"<<i<<endl;
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
		cout<<"˫������Ϊ�գ�"<<endl;
		return false;
	}
	if(i<1)
	{
		cout<<"����ɾ��ͷ��㣡"<<endl;
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
	cout<<"��������"<<endl;
	
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
		cout<<"��ʼ������ɹ���"<<endl;
		}	
	else
	{
		cout<<"��ʼ������ʧ�ܣ�"<<endl;
	}
	
	int n;
	cout<<"ʹ��ǰ�巨����˫������"<<endl;
	cout<<"������Ԫ�ظ���";
	cin>>n;
	cout<<endl<<"��������"<<n<<"��Ԫ�أ�";
	
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
		cout<<"������Ҫ�����λ�ú�Ԫ�أ��ÿո��������";
		cin>>i>>x;
		
		if(DoubleLinkListInsert(L,i,x))
		{
			cout<<"����ɹ���"<<endl;
		 } 
		else
		{
			cout<<"����ʧ�ܣ�"<<endl;
		}
		DoubleLinkListPrint(L);
	}
	
	if(DoubleLinkListDelete(L,2))
	{
		cout<<"ɾ�������2��Ԫ�سɹ�"<<endl;
	}
	else 
	{
		cout<<"ɾ�������2��Ԫ��ʧ��"<<endl; 
	}
	
	DoubleLinkListPrint(L);
	
	DoubleLinkListDestroy(L);
	
	return 0;
}

 
