#include <iostream>
using namespace std;
void calculos(int num,int *doble,int *triple){//Paso de para metros y punteros para modificarlos de forma global
	*doble=2*num;//Multiplicamos el numero por 2
	*triple=3*num;//Multiplicamos el numero por 3
}
int main(){
	int numero=2,doble=0,triple=0;//Declaramos la Variables
	calculos(numero,&doble,&triple);//Pasamos los parametros y doble y triple los pasamos como direccion de memoria para que se modifiquen de forma gobal
	cout<<"El doble de 2 es: "<<doble<<endl;//Imprimimos el doble
	cout<<"El triple de 2 es :  "<<triple<<endl;//imprimimos el triple
	//Imprimimos las direecions de memoria
	cout<<"La direccion de doble es: "<<&doble<<endl;
	cout<<"La direccion de triple es: "<<&triple<<endl;
	cout<<"La direccion de numero es: "<<&numero<<endl;
	return 0;
}
//Porque son importantes los punteros?
//Los puneros nos sirven para jugar con los espacios de memoria y hacer dinamico el codigo, interactuando de forma global con las variables...
