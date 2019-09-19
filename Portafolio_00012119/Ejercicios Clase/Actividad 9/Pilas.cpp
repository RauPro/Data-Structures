#include <iostream>
#include <time.h>
using namespace std;
struct nodo{
    float elemento;
    nodo *siguiente;
};
typedef struct nodo *Pila;
void inizialice(Pila *s){
	*s=NULL;
}
bool empty(Pila *s){
	return *s==NULL;
}
void push(Pila *s,float e){
	nodo* unNodo;
	//unNodo=(struct nodo*)malloc(sizeof(struct nodo));
	unNodo = new struct nodo;
	unNodo->elemento=e;
	unNodo->siguiente=*s;
	*s=unNodo;
}
float pop(Pila *s){
	if(!empty(s)){
		nodo *unNodo=*s;
		float e=(*s)->elemento;
		*s=(*s)->siguiente;
		delete(unNodo);
		return e;
	}
	else{
		return -1;
	}
}
float top(Pila *s){
	if(!empty(s)){
		float e=(*s)->elemento;
		return e;
	}
	else return -1;
}
int main(){
	Pila unaPila;
	inizialice(&unaPila);
	push(&unaPila,1);
	push(&unaPila,2);
	push(&unaPila,3);
	push(&unaPila,4);
	push(&unaPila,5);
	pop(&unaPila);
	cout<<"El segundo elemento en la Pila es : "<<top(&unaPila);
}
