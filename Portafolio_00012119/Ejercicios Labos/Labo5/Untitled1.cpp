#include <iostream>
using namespace std;
#include <conio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
bool esPrimo(int numero);
int factorial(int numero);
int main(){
validar:
	string cad;
	cout << "Introduce un numero: ";
	cin >> cad; 
	bool ok = true;
	for(string::const_iterator it=cad.begin(); it!=cad.end() && ok; ++it )
	  ok = isdigit(*it);
	 int numero;
	if(ok)
	{
		cin.ignore();
		numero = atoi(cad.c_str());
	}
	else
	{
	  cout << "Error!!!\n Igrese un numero" << std::endl;
	  goto validar;
	}

	while (numero<=0){
		cout<<"Ingrese un numero valido."<<endl;
			cout<<"Ingrese un entero: ";
			cin>>numero;
	}
	if (esPrimo(numero)){
		cout<<"VERDADERO!\nFactorial: "<<factorial(numero);
		
	}
	else{
		cout<<"Falso\nFactorial: "<<factorial(numero);
	}
}
bool esPrimo(int numero) {
  if (numero == 0 || numero == 1 || numero == 4) return false;
  for (int x = 2; x < numero / 2; x++) {
    if (numero % x == 0) return false;
  }
  return true;
}
int fact=1;
int factorial(int numero){
	      for (int i = 1; i <= numero; i++){
          fact = fact*i;
      }
      return fact;
}
