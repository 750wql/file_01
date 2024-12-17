#include"myBookData.h"
#include<string>
#include<stdlib.h>
void BookData::showall()
{
	char temp[55];
	strcat(getIsbn(),"/");
	strcat(getIsbn(),getBookTitle());
	strcpy(dTstring,getIsbn());
	strcat(dTstring,"/");
	strcat(dTstring,itoa(getQtyOnHand(),temp,10));
	strcat(dTstring,"/");
	strcat(dTstring,itoa(getRetail(),temp,10));
}