#include <iostream>
using namespace std;
void mostrarArreglo(const int[], int);
int busquedaBinaria(const int[], int, int);
void ordenarArreglo(int[], int);
void intercambiar(int&, int&);
int main(){
  int clave =0;
  int arreglo[8] = {1, 3, 4, 5, 17, 18, 31, 33};
  ordenarArreglo(arreglo,8);
  cout << "Elementos del arreglo: " << endl;
   for (int i = 0 ; i < 8 ; i++){
   	cout << arreglo[i] <<  " ";
   }
   cout<<endl;
    
  cout << "Indique un valor a buscar y se le devolvera el indice: " << endl;
  cin >> clave;
  cout<< "Su valor se encuentra en arreglo["<<busquedaBinaria(arreglo,8,clave)<<"]" << endl;
  return 0;
}
int busquedaBinaria(const int arreglo[], int tamano, int clave)
{
  int Iarriba = tamano-1;
  int Iabajo = 0;
  int Icentro;
  while (Iabajo <= Iarriba)
    {
      Icentro = (Iarriba + Iabajo)/2;
      if (arreglo[Icentro] == clave)
 return Icentro;
      else
 if (clave < arreglo[Icentro])
   Iarriba=Icentro-1;
 else
   Iabajo=Icentro+1;
    }
  return -1;
}
void ordenarArreglo(int arreglo[], int tamano)
{
  for (int i = 0; i< tamano -1 ; i++)
    for (int j = 0; j< tamano -1 ; j++)
      if (arreglo[j] > arreglo[j+1])
 intercambiar(arreglo[j],arreglo[j+1]);
}
void intercambiar(int &a, int &b)
{
  int tmp = b;
  b = a;
  a = tmp;
}
