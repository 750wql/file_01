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
		cout<<"打开文件失败!"<<endl;
		exit(0);
	}
	while(true)
	{
		cout<<"\n\t\txxx图书管理系统"<<endl;
		cout<<"\t\t   主菜单"<<endl;
		cout<<"1.收银模块\n";
		cout<<"2.书库管理模块\n";
		cout<<"3.报表模块\n";
		cout<<"4.退出系统\n\n";
		do
		{
			cout<<"输入选择\n请输入1~4之间的数 ";
			cin>>choice1;
			if(choice1<1||choice1>4)
			{
				cout<<"请重新输入"<<endl;
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
	cout<<"请输入编号：";
	cin>>id;
	cout<<"请输入书名：";
	cin>>name;
	cout<<"请输入库存：";
	cin>>num;
	cout<<"请输入零售价：";
	cin>>price;
	cin.ignore();
	cout<<"请输入作者名：";
	cin.getline(ator,51);
	cout<<"请输入出版社：";
	cin>>pub1;
	cout<<"请输入进书日期:";
	cin>>adat;
	cout<<"请输入批发价：";
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
		cout<<"请输入查找的书的编号：";
		cin>>id4;
		while(j<100)
		{
			if(!strcmp(id4,obj[j].getIsbn())&&strlen(id4)==strlen(obj[j].getIsbn()))
			{
				cout<<"已找到该书"<<endl;
				cout<<"请输入要买的数量：";
				cin>>c;
				k=1;
				break;
			}
			if(j==99)
			{
				cout<<"查无此书,是否再次查找（Y/N)";
				cin>>judge;
				if(judge=='Y') break;
				else return;
			}
			else j++;
		}
		if(k==1)
		{
			cout<<"\n\t\t前台销售模块\n";
			cout<<"日期：2021年12月26日\n";
			cout<<"数量   ISBN号         书名         单价         金额\n";
			cout<<c<<"  \t"<<obj[j].getIsbn()<<"\t\t"<<obj[j].getBookTitle()<<"  \tRMB"<<obj[j].getRetail()<<"  \tRMB"<<c*obj[j].getRetail()<<endl;
			cout<<"------------------------------------------------"<<endl;
			float m=c*obj[j].getRetail();
			cout<<"销售合计RMB"<<m<<endl;
			cout<<"零售税RMB"<<0.06*m<<endl;
			cout<<"应付金额RMB"<<1.06*m<<endl;
			cout<<"\n谢谢光临!"<<endl;
			sum1+=m;
			sum2+=(0.6*m);
			sum3+=1.06*m;
			int q=obj[j].getQtyOnHand();
			q-=c;
			obj[j].setQtyOnHand(q);
			char pd;
			cout<<"请问还需要买别的吗？(Y/N)";
			cin>>pd;
			if(pd=='Y')
			{
				j=0;
				shouyin(obj,file,sum1,sum2,sum3);
			}
			else
			{
				cout<<"销售总额RMB"<<sum1<<endl;
				cout<<"零售税RMB"<<sum2<<endl;
				cout<<"总价RMB"<<sum3<<endl;
				break;
			}
		}
	}while(!strcmp(id4,obj[j].getIsbn()));
}

void guanli(BookData* obj,fstream &file,int &ip)
{
	int choice2;
	cout<<"\n\t\txxx图书管理系统"<<endl;
	cout<<"\t\t   书库管理模块"<<endl;
	cout<<"\n1.查找某本书的信息\n";
	cout<<"2.增加书\n";
	cout<<"3.修改书的信息\n";
	cout<<"4.删除书\n";
	cout<<"5.返回到主菜单\n\n";
	cout<<"输入选择: ";
	do
		{
			cout<<"输入选择\n请输入1~5之间的数 ";
			cin>>choice2;
			if(choice2<1||choice2>5)
			{
				cout<<"请重新输入"<<endl;
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
	cout<<"\n\t\txxx图书管理系统"<<endl;
	cout<<"\t\t   报表模块"<<endl;
	cout<<"\n1.书库列表\n";
	cout<<"2.零售价列表\n";
	cout<<"3.批发价列表\n";
	cout<<"4.库存量列表\n";
	cout<<"5.价值额列表\n";
	cout<<"6.日期列表\n";
	cout<<"7.返回到主菜单\n\n";
	cout<<"输入选择: ";
	do
		{
			cout<<"输入选择\n请输入1~7之间的数 ";
			cin>>choice4;
			if(choice4<1||choice4>7)
			{
				cout<<"请重新输入"<<endl;
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
		cout<<"请输入查找的书的编号：";
		cin>>id1;
		while(j<100)
		{
			if(!strcmp(id1,obj[j].getIsbn())&&strlen(id1)==strlen(obj[j].getIsbn()))
			{
				cout<<"已找到该书"<<endl;
				showbook(obj[j]);
				k=1;
				break;
			}
			if(j==99)
			{
				cout<<"查无此书";
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
		cout<<"请输入你想改的书的编号：";
		cin>>id2;
		while(j<100)
		{
			if(!strcmp(id2,obj[j].getIsbn())&&strlen(id2)==strlen(obj[j].getIsbn()))
			{
				cout<<"已找到该书"<<endl;
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
				cout<<"查无此书";
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
		cout<<"请输入要删除的书的编号：";
		cin>>id3;
		while(j<100)
		{
			if(!strcmp(id3,obj[j].getIsbn())&&strlen(id3)==strlen(obj[j].getIsbn()))
			{
				cout<<"已找到该书"<<endl;
				showbook(obj[j]);
				delete [] obj[j].getIsbn();
				delete [] obj[j].getBookTitle();
				delete [] obj[j].getdTstring();
				(obj[j].getQtyOnHand(),0);
				(obj[j].getRetail(),0);
				cout<<"已删除"<<endl;
				k=1;
				break;
			}
			if(j==99)
			{
				cout<<"查无此书";
				break;
			}
			else j++;
		}
		if(k==1) break;
	}while(strcmp(id3,obj[j].getIsbn()));
}
void showbook(BookData &obj)
{
	cout<<"ISBN号："<<obj.getIsbn()<<endl;
	cout<<"书 名:"<<obj.getBookTitle()<<endl;
	cout<<"库存量："<<obj.getQtyOnHand()<<endl;
	cout<<"零售价："<<obj.getRetail()<<endl;
	cout<<"作者："<<obj.getAuthor()<<endl;
	cout<<"出版社："<<obj.getPub()<<endl;
	cout<<"进书日期:"<<obj.getdateAdded()<<endl;
	cout<<"批发价："<<obj.getwholeSale()<<endl;
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
			cout<<"零售价"<<i+1<<':';
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
			cout<<"批发价"<<i+1<<':';
			cout<<obj[i].getwholeSale();
			cout<<endl;
			sum+=obj[i].getwholeSale();
			i++;
		}
		
	}while(obj[i].getRetail()>0);
	cout<<"批发总额"<<sum<<endl;
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