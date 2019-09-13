#include <iostream>
using namespace std;

void mediana(int *puntero,int n){
	cout << "Puntero: " << puntero << endl;
	if (n%2!=0){
		cout<<"La mediana es: "<<puntero[n/2];
	}
	else{
		cout<<"El primer valor es: "<<puntero[n/2]<<endl;
		cout<<"El segundo valor es: "<<puntero[(n/2)-1]<<endl;
		double m=((puntero[n/2]+puntero[(n/2)-1])*0.50);
		cout<<"La mediana es: "<< (double)m;
	}
}

int main()
{
	cout<<"Ingrese la cantidad de numeros a contener en el arreglo:  "<<endl;
	int n;
	cin>>n;
	int numeros[n];
	for(int i=0; i<n;i++){
		cout<<"Ingrese un dato para el arreglo: "<<endl;
		cin>>numeros[i];
	}
	
	cout << "Primer valor: " << *numeros << endl;
	cout << "Direccion: " << numeros << endl;
	
	mediana(numeros,n);
}
