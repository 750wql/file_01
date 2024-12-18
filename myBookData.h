#include<cstring>
#ifndef MYBOOKDATA_H
#define MYBOOKDATA_H
class BookData
{
private:
	char* isbn;
	char* bookTitle;
	int qtyOnHand;
	double retail;
	char* dTstring;
	char* author;
	char* pub;
	char* dateAdded;
	double wholeSale;
public:
	BookData()//构造函数
	{
		isbn=new char[14];
		bookTitle=new char[51];
		dTstring=new char[100];
		author=new char[51];
		pub=new char[51];
		dateAdded=new char[51];
		wholeSale=-1;
		qtyOnHand=-1;
		retail=-1;
	}
	~BookData()//析构函数
	{
		delete [] isbn;
		delete [] bookTitle;
		delete [] dTstring;
		delete [] author;
		delete [] pub;
		delete [] dateAdded;
	}
	void setIsbn(char* a){strcpy(isbn,a);}//输入ISBN号
	void setBookTitle(char* a){strcpy(bookTitle,a);}//输入书名
	void setQtyOnHand(int a){qtyOnHand=a;}//输入库存
	void setRetail(double a){retail=a;}//输入零售价
	char* getIsbn() const{return isbn;}//获取ISBN号
	char* getBookTitle() const{return bookTitle;}//获取书名
	int getQtyOnHand() const{return qtyOnHand;}//获取库存
	double getRetail() const{return retail;}//获取零售价
	char* getdTstring() const{return dTstring;}//获取信息
	void showall();//显示全部
	char getBookTitle1(){return bookTitle[0];}//获取书名
	void setAuthor(char* a){strcpy(author,a);}//输入作者
	void setPub(char* a){strcpy(pub,a);}//输入出版社
	void setdateAdded(char* a){strcpy(dateAdded,a);}//输入进书日期
	void setwholeSale(double a){wholeSale=a;}//输入销售额
	char* getAuthor() const{return author;}//获取作者
	char* getPub() const{return pub;}//获取出版社
	char* getdateAdded() const{return dateAdded;}//获取进书日期
	double getwholeSale() const{return wholeSale;}//获取销售额
	void operator = (const BookData &right)//重载等于号实现交换
	{
		delete [] isbn;
		isbn=new char[strlen(right.getIsbn())+1];
		strcpy(isbn,right.getIsbn());
		delete [] bookTitle;
		bookTitle=new char[strlen(right.getBookTitle())+1];
		strcpy(bookTitle,right.getBookTitle());
		delete [] dTstring;
		dTstring=new char[strlen(right.getdTstring())+1];
		strcpy(dTstring,right.getdTstring());
		delete [] author;
		author=new char[strlen(right.getAuthor())+1];
		strcpy(author,right.getAuthor());
		delete [] pub;
		pub=new char[strlen(right.getPub())+1];
		strcpy(pub,right.getPub());
		delete [] dateAdded;
		dateAdded=new char[strlen(right.getdateAdded())+1];
		strcpy(dateAdded,right.getdateAdded());
		wholeSale=right.getwholeSale();
		qtyOnHand=right.getQtyOnHand();
		retail=right.getRetail();
	}
};
#endif
