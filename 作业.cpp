#include<iostream>
using namespace std;

class Point
{
	int data;
public:
	int getdata();
	void setdata(int data);
};

int Point::getdata()
{
	return this->data;
}

void Point::setdata(int data)
{
	this->data = data;
}

class Stack{
	Point *top;
	Point base[100];
	int length;
	public:
		Stack();
		int top1();
		bool push(int data);
		bool pop();
		bool emp();
		int size();
		int clear(Stack *p);
};

Stack::Stack(){				//���캯�� 
	top = base;
	length = 0;
}

int Stack::top1(){			//��ȡջ��Ԫ�� 
	if(length==0)
	{
		return 0;
	}
	return (top-1)->getdata();
}

bool Stack::push(int data){  //��ջ 
	if(length==100)
	{
		return 0;
	}
	top->setdata(data);
	top++;
	length++;
	return 1;
}

bool Stack::pop(){			//��ջ 
	if(top==base)
	{
		return 0;
	}
	top--;
	length--;
	return 1;
}

bool Stack::emp(){			//����ջ�Ƿ�Ϊ�� 
	if(top == base)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Stack::size(){
	return length;
}

int Stack::clear(Stack *p)
{
	if(p->base==p->top)
	{
		return 1;
	}
	while(p->top>p->base)
	{
		p->top--;
	}
	return 1;
}

main(){
	Stack s = Stack();
	s.push(1);
	cout<<s.top1()<<endl;
	s.push(2);
	cout<<s.top1()<<endl;
	s.push(3);
	cout<<s.top1()<<endl;
	s.push(4);
	cout<<s.top1()<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<s.top1()<<endl;
		s.pop();
	}
	cout<<"������"<<s.clear(&s);
}
