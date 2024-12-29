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

class Queue{
	int head;
	int tail;
	int length;
	Point q[100];
	public:
		Queue();
		int gethead(){
		return head;}
		int gettail(){
		return tail;}
		void settail(int t){
			tail = t;
		}
		bool push(int data);
		bool pop();
		int front();
		int back();
		bool emp();
		int size();
};

Queue::Queue(){
	head = 0;
	tail = 0;
	length = 0;
}

bool Queue::push(int data){
	if(length == 100)
	{
		return 0;
	}
	q[tail].setdata(data);
	tail = (tail+1)%100;
	length++;
	return 0;
}

bool Queue::pop()
{
	if(length == 0)
	{
		return 0;
	}
	head = (head+1)%100;
	length--;
	return 0;
}

int Queue::front(){
	return q[head].getdata();
}

int Queue::back(){
	return q[tail-1].getdata();
}

bool Queue::emp(){
	if(length == 0)
	{
		return 0;
	}
	else return 1;
}

int Queue::size(){
	return length;
}

int main(){
	Queue q = Queue();
	q.push(1);
	cout<<q.back()<<endl;
	q.push(3);
	cout<<q.back()<<endl;
	q.push(5);
	cout<<q.back()<<endl;
	q.push(7);
	cout<<q.back()<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<q.front()<<endl;
		q.pop();
	}
	cout<<"Çå³ıÍê±Ï"<<endl;
}
