#include<iostream>
using namespace std;
int gcd(int &a,int &b){
	return b=0?a:gcd(b,a%b);
}
int lcm(int &a,int &b){
	return a*(b/gcd(a,b));
}
int main(){
	int a,b;
	cin>>a;
	cin>>b;
	cout<<gcd(a,b)<<endl;
	cout<<lcd(a,b)<<endl;
	return 0;
}