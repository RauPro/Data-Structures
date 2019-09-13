#include<iostream>
#include <math.h>
using namespace std;
int multi(int a ,int b);
int main() {
	int a;
	int b;
	cout<<"ingrese los dos numeros que deseea: "<<endl;
	cin>>a>>b;	
	cout<<"  la multiplicacion 	"<<multi(a, b);	
	return 0 ;
}
int multi(int a,int b){
	int aux ;
	int x;
	int y;
	if(b==1){
	cout <<"b= "<<b<<"  caso base "<<endl ;
	return a;	
	}
	else{
		if(b>1){	
		x=a+a*(b-1);
		b-=1;
		y=multi (x ,b);	
		cout<<"x= "<<x<< "	a="<<a<<"	b= "<<b<<endl ;	
		return x;
	}	
	}
		
}
