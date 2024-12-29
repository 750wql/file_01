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

Stack::Stack(){				//构造函数 
	top = base;
	length = 0;
}

int Stack::top1(){			//读取栈顶元素 
	if(length==0)
	{
		return 0;
	}
	return (top-1)->getdata();
}

bool Stack::push(int data){  //进栈 
	if(length==100)
	{
		return 0;
	}
	top->setdata(data);
	top++;
	length++;
	return 1;
}

bool Stack::pop(){			//出栈 
	if(top==base)
	{
		return 0;
	}
	top--;
	length--;
	return 1;
}

bool Stack::emp(){			//检验栈是否为空 
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
	cout<<"清空完毕"<<s.clear(&s);
}
