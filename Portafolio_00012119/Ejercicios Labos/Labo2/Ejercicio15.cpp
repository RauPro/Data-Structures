#include<iostream>
using namespace std;
void arregloF(int x[],int inicio,int final){
    for (int i=0;i<final;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void comparar(int *izq,int nIzq,int *der,int nDer,int *A){
    int i=0,j=0,k=0;
    while( ( i < nIzq ) && ( j < nDer ) ){
        if( izq[i] <= der[j]){
            A[k] = izq[i];
            i++;
        }
        else{
            A[k] = der[j];
            j++;
        }
        k++;
        }
        while(i < nIzq){
            A[k] = izq[i];
            i++;k++;
        }
        while(j < nDer){
            A[k] = der[j];
            j++;k++;
    }
}
void cortar(int *A,int n){
    if(n==1){return;}
    int mitad = n / 2;
    int *izq=new int[mitad];
    int *der=new int[n-mitad];
    for(int i=0;i<mitad;i++)
        izq[i] = A[i];
    for(int i=mitad;i<n;i++)
        der[i-mitad] = A[i];
    cortar(izq, mitad);
    cortar(der, n-mitad);
    comparar(izq, mitad, der, n-mitad, A);
}

int main(){
    int arreglo[15] = {25,17,13,16,41,32,12,115,95,84,54,63,78,21,10};
    arregloF(arreglo,0,15);
    cortar(arreglo,15);
    arregloF(arreglo,0,15);
    return 0;
}