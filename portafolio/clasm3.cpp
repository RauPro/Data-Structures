#include<iostream>
using namespace std;
int buscador(int x,int low, int high);
int arreglo[8]={1,3,4,5,17,18,31,33};
int main(){
	
	int low=0;
	int high=7;
	cout<<"Ingrese el numero a buscar"<<endl;
	int x;cin>>x;
	while(x<0){
		cout<<"Ingrese el numero a buscar"<<endl;
		cin>>x;
	}
	int i=buscador(x,low,high);
	cout<<i;
	return 0;
}
int buscador(int x,int low, int high){
	if(low>high){
		return -1;
	}
	int mid= (low+high)/2;
	if (x==arreglo[mid]){
		return mid;
	}
	if (x<arreglo[mid]){
		buscador(x,low,mid-1);
	}
	else{
		buscador(x,mid+1,high);
	}
	
}

