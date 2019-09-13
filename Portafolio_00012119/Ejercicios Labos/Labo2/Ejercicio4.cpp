#include <iostream>
#include <cmath>
using namespace std;
float funcion(int k, int n){
    float pi = 4*((pow(-1,k))/(2*k + 1));
    if(n>0){
        return pi + funcion(k+1, n-1);
    }
    return pi;
}
int main()
{
    int n;
    cout<<"Ingrese la cantidad de Iteraciones: ";
	cin>>n;
    cout<<"Aproximacion: "<<funcion(0,n);
    return 0;
}
