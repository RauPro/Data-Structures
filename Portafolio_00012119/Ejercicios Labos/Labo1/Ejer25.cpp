#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct numero{
    float real, imaginaria;
};
int main(){
	numero complejo;
	cout<<"Ingrese el comlejo: "<<endl;
    cout<<"Parte real: "; cin>>complejo.real;
    cout<<"Parte imaginaria: "; cin>>complejo.imaginaria;
    cout<<"El valor absoluto es: ";
    cout<<(sqrt(pow(complejo.real,2)+pow(complejo.imaginaria,2)));
}

