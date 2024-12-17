#include<iostream>
#include<fstream>
#include<string>
#include"myBookData.h"
using namespace std;

void setall(BookData &obj);
void showbook(BookData &obj);
void shouyin(BookData* obj,fstream &file,int a1,int a2,int a3);
void guanli(BookData* obj,fstream &file,int &ip);
void baobiao(BookData* obj,fstream &file);
void addbook(BookData* obj,fstream &file,int &ip);
void findbook(BookData* obj,fstream &file);
void editbook(BookData* obj,fstream &file);
void deletebook(BookData* obj,fstream &file);
void booklist(BookData* obj,fstream &file);
void retaillist(BookData* obj,fstream &file);
void wslist(BookData* obj,fstream &file);
void qtylist(BookData* obj,fstream &file);
void allwslist(BookData* obj,fstream &file);
void datelist(BookData* obj,fstream &file);
int getnum(BookData* obj);
int main()
{
	fstream dataFile;
	BookData* book;
	int choice1;
	int ip=0;
	book=new BookData[100];
	dataFile.open("visual3.txt",ios::out|ios::in|ios::trunc);
	if(!dataFile)
	{
		cout<<"���ļ�ʧ��!"<<endl;
		exit(0);
	}
	while(true)
	{
		cout<<"\n\t\txxxͼ�����ϵͳ"<<endl;
		cout<<"\t\t   ���˵�"<<endl;
		cout<<"1.����ģ��\n";
		cout<<"2.������ģ��\n";
		cout<<"3.����ģ��\n";
		cout<<"4.�˳�ϵͳ\n\n";
		do
		{
			cout<<"����ѡ��\n������1~4֮����� ";
			cin>>choice1;
			if(choice1<1||choice1>4)
			{
				cout<<"����������"<<endl;
			}
		}while(choice1<1||choice1>4);
		switch(choice1)
		{
			case 1:
				shouyin(book,dataFile,0,0,0);
				break;
			case 2:
				guanli(book,dataFile,ip);
				break;
			case 3:
				baobiao(book,dataFile);
				break;
			case 4:
				dataFile.close();
				exit(0);


		}
	}
	system("pause");
	return 0;
}
void setall(BookData &obj)
{
	char id[21]={'\0'},name[51]={'\0'};
	int num,price;
	char ator[51]={'\0'},adat[51]={'\0'},pub1[51]={'\0'};
	double ws=0;
	cout<<"�������ţ�";
	cin>>id;
	cout<<"������������";
	cin>>name;
	cout<<"�������棺";
	cin>>num;
	cout<<"���������ۼۣ�";
	cin>>price;
	cin.ignore();
	cout<<"��������������";
	cin.getline(ator,51);
	cout<<"����������磺";
	cin>>pub1;
	cout<<"�������������:";
	cin>>adat;
	cout<<"�����������ۣ�";
	cin>>ws;
	obj.setIsbn(id);
	obj.setBookTitle(name);
	obj.setQtyOnHand(num);
	obj.setRetail(price);
	obj.setAuthor(ator);
	obj.setPub(pub1);
	obj.setdateAdded(adat);
	obj.setwholeSale(ws);
}
void shouyin(BookData* obj,fstream &file,int a1,int a2,int a3)
{
	char id4[14]={'\0'};
	int j=0,c=0,k=0,sum1=a1,sum2=a2,sum3=a3;
	char judge;
	do
	{
		cout<<"��������ҵ���ı�ţ�";
		cin>>id4;
		while(j<100)
		{
			if(!strcmp(id4,obj[j].getIsbn())&&strlen(id4)==strlen(obj[j].getIsbn()))
			{
				cout<<"���ҵ�����"<<endl;
				cout<<"������Ҫ���������";
				cin>>c;
				k=1;
				break;
			}
			if(j==99)
			{
				cout<<"���޴���,�Ƿ��ٴβ��ң�Y/N)";
				cin>>judge;
				if(judge=='Y') break;
				else return;
			}
			else j++;
		}
		if(k==1)
		{
			cout<<"\n\t\tǰ̨����ģ��\n";
			cout<<"���ڣ�2021��12��26��\n";
			cout<<"����   ISBN��         ����         ����         ���\n";
			cout<<c<<"  \t"<<obj[j].getIsbn()<<"\t\t"<<obj[j].getBookTitle()<<"  \tRMB"<<obj[j].getRetail()<<"  \tRMB"<<c*obj[j].getRetail()<<endl;
			cout<<"------------------------------------------------"<<endl;
			float m=c*obj[j].getRetail();
			cout<<"���ۺϼ�RMB"<<m<<endl;
			cout<<"����˰RMB"<<0.06*m<<endl;
			cout<<"Ӧ�����RMB"<<1.06*m<<endl;
			cout<<"\nлл����!"<<endl;
			sum1+=m;
			sum2+=(0.6*m);
			sum3+=1.06*m;
			int q=obj[j].getQtyOnHand();
			q-=c;
			obj[j].setQtyOnHand(q);
			char pd;
			cout<<"���ʻ���Ҫ������(Y/N)";
			cin>>pd;
			if(pd=='Y')
			{
				j=0;
				shouyin(obj,file,sum1,sum2,sum3);
			}
			else
			{
				cout<<"�����ܶ�RMB"<<sum1<<endl;
				cout<<"����˰RMB"<<sum2<<endl;
				cout<<"�ܼ�RMB"<<sum3<<endl;
				break;
			}
		}
	}while(!strcmp(id4,obj[j].getIsbn()));
}

void guanli(BookData* obj,fstream &file,int &ip)
{
	int choice2;
	cout<<"\n\t\txxxͼ�����ϵͳ"<<endl;
	cout<<"\t\t   ������ģ��"<<endl;
	cout<<"\n1.����ĳ�������Ϣ\n";
	cout<<"2.������\n";
	cout<<"3.�޸������Ϣ\n";
	cout<<"4.ɾ����\n";
	cout<<"5.���ص����˵�\n\n";
	cout<<"����ѡ��: ";
	do
		{
			cout<<"����ѡ��\n������1~5֮����� ";
			cin>>choice2;
			if(choice2<1||choice2>5)
			{
				cout<<"����������"<<endl;
			}
		}while(choice2<1||choice2>5);
		switch(choice2)
		{
			case 1:
				findbook(obj,file);
				return;
			case 2:
				addbook(obj,file,ip);
				return;
			case 3:
				editbook(obj,file);
				return;
			case 4:
				deletebook(obj,file);
				return;
			case 5:
				return;


		}
}

void baobiao(BookData* obj,fstream &file)
{
	int choice4;
	cout<<"\n\t\txxxͼ�����ϵͳ"<<endl;
	cout<<"\t\t   ����ģ��"<<endl;
	cout<<"\n1.����б�\n";
	cout<<"2.���ۼ��б�\n";
	cout<<"3.�������б�\n";
	cout<<"4.������б�\n";
	cout<<"5.��ֵ���б�\n";
	cout<<"6.�����б�\n";
	cout<<"7.���ص����˵�\n\n";
	cout<<"����ѡ��: ";
	do
		{
			cout<<"����ѡ��\n������1~7֮����� ";
			cin>>choice4;
			if(choice4<1||choice4>7)
			{
				cout<<"����������"<<endl;
			}
		}while(choice4<1||choice4>7);
		switch(choice4)
		{
			case 1:
				booklist(obj,file);
				return;
			case 2:
				retaillist(obj,file);
				return;
			case 3:
				wslist(obj,file);
				return;
			case 4:
				qtylist(obj,file);
				return;
			case 5:
				allwslist(obj,file);
				return;
			case 6:
				datelist(obj,file);
			case 7:
				return;

		}
}
void addbook(BookData* obj,fstream &file,int &ip)
{
	setall(obj[ip]);
	file<<obj[ip].getIsbn()<<endl;
	file<<obj[ip].getBookTitle()<<endl;
	file<<obj[ip].getQtyOnHand()<<endl;
	file<<obj[ip].getRetail()<<endl;
	file<<obj[ip].getAuthor()<<endl;
	file<<obj[ip].getPub()<<endl;
	file<<obj[ip].getdateAdded()<<endl;
	file<<obj[ip].getwholeSale()<<endl;
	ip++;
}
void findbook(BookData* obj,fstream &file)
{
	char id1[14]={'\0'};
	int j=0,k=0;
	do
	{
		cout<<"��������ҵ���ı�ţ�";
		cin>>id1;
		while(j<100)
		{
			if(!strcmp(id1,obj[j].getIsbn())&&strlen(id1)==strlen(obj[j].getIsbn()))
			{
				cout<<"���ҵ�����"<<endl;
				showbook(obj[j]);
				k=1;
				break;
			}
			if(j==99)
			{
				cout<<"���޴���";
				break;
			}
			else j++;
		}
		if(k==1) break;
	}while(strcmp(id1,obj[j].getIsbn()));
}
void editbook(BookData* obj,fstream &file)
{
	int j=0,k=0;
	char id2[14]={'\0'};
	do
	{
		cout<<"����������ĵ���ı�ţ�";
		cin>>id2;
		while(j<100)
		{
			if(!strcmp(id2,obj[j].getIsbn())&&strlen(id2)==strlen(obj[j].getIsbn()))
			{
				cout<<"���ҵ�����"<<endl;
				showbook(obj[j]);
				delete [] obj[j].getIsbn();
				delete [] obj[j].getBookTitle();
				delete [] obj[j].getdTstring();
				(obj[j].getIsbn(),new char[14]);
				(obj[j].getBookTitle(),new char[51]);
				(obj[j].getdTstring(),new char[100]);
				setall(obj[j]);
				k=1;
				break;
			}
			if(j==99)
			{
				cout<<"���޴���";
				break;
			}
			else j++;
		}
		if(k==1) break;
	}while(strcmp(id2,obj[j].getIsbn()));
}
void deletebook(BookData* obj,fstream &file)
{
	char id3[14]={'\0'};
	int j=0,k=0;
	do
	{
		cout<<"������Ҫɾ������ı�ţ�";
		cin>>id3;
		while(j<100)
		{
			if(!strcmp(id3,obj[j].getIsbn())&&strlen(id3)==strlen(obj[j].getIsbn()))
			{
				cout<<"���ҵ�����"<<endl;
				showbook(obj[j]);
				delete [] obj[j].getIsbn();
				delete [] obj[j].getBookTitle();
				delete [] obj[j].getdTstring();
				(obj[j].getQtyOnHand(),0);
				(obj[j].getRetail(),0);
				cout<<"��ɾ��"<<endl;
				k=1;
				break;
			}
			if(j==99)
			{
				cout<<"���޴���";
				break;
			}
			else j++;
		}
		if(k==1) break;
	}while(strcmp(id3,obj[j].getIsbn()));
}
void showbook(BookData &obj)
{
	cout<<"ISBN�ţ�"<<obj.getIsbn()<<endl;
	cout<<"�� ��:"<<obj.getBookTitle()<<endl;
	cout<<"�������"<<obj.getQtyOnHand()<<endl;
	cout<<"���ۼۣ�"<<obj.getRetail()<<endl;
	cout<<"���ߣ�"<<obj.getAuthor()<<endl;
	cout<<"�����磺"<<obj.getPub()<<endl;
	cout<<"��������:"<<obj.getdateAdded()<<endl;
	cout<<"�����ۣ�"<<obj.getwholeSale()<<endl;
}
void booklist(BookData* obj,fstream &file)
{
	int i=0;
	do
	{
		if(!(obj[i].getRetail())) continue;
		else 
		{
			showbook(obj[i]);
			cout<<endl;
			i++;
		}
	}while(obj[i].getRetail()>0);
	
}
void retaillist(BookData* obj,fstream &file)
{
	int i=0;
	do
	{
		if(!(obj[i].getRetail())) continue;
		else 
		{
			cout<<"���ۼ�"<<i+1<<':';
			cout<<obj[i].getRetail();
			cout<<endl;
			i++;
		}
		
	}while(obj[i].getRetail()>0);
}
void wslist(BookData* obj,fstream &file)
{
	int i=0,sum=0;
	do
	{
		if(!(obj[i].getRetail())) continue;
		else 
		{
			cout<<"������"<<i+1<<':';
			cout<<obj[i].getwholeSale();
			cout<<endl;
			sum+=obj[i].getwholeSale();
			i++;
		}
		
	}while(obj[i].getRetail()>0);
	cout<<"�����ܶ�"<<sum<<endl;
}
int getnum(BookData* obj)
{
	int i=0;
	while(obj[i].getRetail()>0)
	{
		i++;
	}
	return i;
}
void qtylist(BookData* obj,fstream &file)
{
	int i,j,minindex;
	BookData t;
	for(i=0;i<getnum(obj)-1;i++)
	{
		minindex=i;
		for(j=i+1;j<getnum(obj);j++)
		{
			if(obj[j].getQtyOnHand()<obj[minindex].getQtyOnHand())
			{
				minindex=j;
			}
		}
		if(minindex!=i)
		{
			t=obj[minindex];
			obj[minindex]=obj[i];
			obj[i]=t;
		}
	}
	i=0;
	do
	{
		if(!(obj[i].getRetail()>0)) continue;
		else 
		{
			showbook(obj[i]);
			cout<<endl;
			i++;
		}
	}while(i<getnum(obj));
}
void allwslist(BookData* obj,fstream &file)
{
	int i,j,minindex;
	BookData t;
	for(i=0;i<getnum(obj)-1;i++)
	{
		minindex=i;
		for(j=i+1;j<getnum(obj);j++)
		{
			if(obj[j].getQtyOnHand()*obj[j].getwholeSale()<obj[minindex].getQtyOnHand()*obj[minindex].getwholeSale())
			{
				minindex=j;
			}
		}
		if(minindex!=i)
		{
			t=obj[minindex];
			obj[minindex]=obj[i];
			obj[i]=t;
		}
	}
	i=0;
	do
	{
		if(!(obj[i].getRetail()>0)) continue;
		else 
		{
			showbook(obj[i]);
			cout<<endl;
			i++;
		}
	}while(i<getnum(obj));
}
void datelist(BookData* obj,fstream &file)
{
	int i,j,minindex;
	BookData t;
	for(i=0;i<getnum(obj)-1;i++)
	{
		minindex=i;
		for(j=i+1;j<getnum(obj);j++)
		{
			if(strcmp(obj[j].getdateAdded(),obj[minindex].getdateAdded())==-1)
			{
				minindex=j;
			}
		}
		if(minindex!=i)
		{
			t=obj[minindex];
			obj[minindex]=obj[i];
			obj[i]=t;
		}
	}
	i=0;
	do
	{
		if(!(obj[i].getRetail()>0)) continue;
		else 
		{
			showbook(obj[i]);
			cout<<endl;
			i++;
		}
	}while(i<getnum(obj));
}