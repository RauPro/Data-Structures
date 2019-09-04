#include <iostream>
#include <cmath>
using namespace std;
int main(){
	cout<<"Ingrese el tamaño del arreglo: "<<endl;
	int n;cin>>n;
  	int arreglo[n];
  	for (int i=0;i<n;i++){
  		cout<<"Ingrese el valor del arrelo; "<<endl;
  		cin>>arreglo[i];
	  }
	int tam=0;
	for(int i=0;i<n;i++){
		if(arreglo[i]>tam){
			tam=arreglo[i];
		}
	}
	cout<<tam;
    return 0;
}

