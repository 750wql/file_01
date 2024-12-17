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
	BookData()
	{
		isbn=new char[14];
		bookTitle=new char[51];
		dTstring=new char[100];
		author=new char[51];
		pub=new char[51];
		dateAdded=new char[51];
		wholeSale=0;
		qtyOnHand=0;
		retail=0;
	}
	~BookData()
	{
		delete [] isbn;
		delete [] bookTitle;
		delete [] dTstring;
		delete [] author;
		delete [] pub;
		delete [] dateAdded;
	}
	void setIsbn(char* a){strcpy(isbn,a);}
	void setBookTitle(char* a){strcpy(bookTitle,a);}
	void setQtyOnHand(int a){qtyOnHand=a;}
	void setRetail(double a){retail=a;}
	char* getIsbn() const{return isbn;}
	char* getBookTitle() const{return bookTitle;}
	int getQtyOnHand() const{return qtyOnHand;}
	double getRetail() const{return retail;}
	char* getdTstring() const{return dTstring;}
	void showall();
	char getBookTitle1(){return bookTitle[0];}
	void setAuthor(char* a){strcpy(author,a);}
	void setPub(char* a){strcpy(pub,a);}
	void setdateAdded(char* a){strcpy(dateAdded,a);}
	void setwholeSale(double a){wholeSale=a;}
	char* getAuthor() const{return author;}
	char* getPub() const{return pub;}
	char* getdateAdded() const{return dateAdded;}
	double getwholeSale() const{return wholeSale;}
	void operator = (const BookData &right)
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
