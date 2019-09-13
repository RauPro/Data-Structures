#include <iostream>
#include <cmath>
using namespace std;
int suma(int n, int x,int acum);

int main(){
    cout<<"Ingrese el valor de n: "<<endl;
    int n;cin>>n;
    cout<<"Ingrese el valor de x: "<<endl;
    int x;cin>>x;
    int sumi=suma(n,x,0);
	cout<<sumi;
    return 0;
}
int sum=0;

int suma(int n, int x,int acum){
   
    if(acum==n+1){
        return sum;
    }
	else{
		sum=sum+(pow(x,acum));
        acum+=1;
        suma(n,x,acum);
    
	}
   
}
