#include <iostream> 
using namespace std; 
/* Nodo como enlace */
struct Node { 
    int data; 
    Node* next; 
};
/* Prototipos */
Node* SortedMerge(Node* a, Node* b); 
void cortarLista(Node* source, Node** frontRef, Node** backRef); 
/* ordena la lista vinculada cambiando los punteros (no datos) */
void MergeSort(Node** headRef) {
    Node* head = *headRef; 
    Node* a; 
    Node* b; 
    /* Caso base 0 elementos o 1 elemento */
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
    /* Dividimos en sub listas a y b */
    cortarLista(head, &a, &b);
    cout<<"----Datos despues de dividir----"<<endl;
    Node* c=b;
    Node* f=a;
    while (c!=NULL){
    	cout<<c->data<<" ";
    	c=c->next;
	}
	cout<<"Datos de B"<<endl;
    while (f!=NULL){
    	cout<<f->data<<" ";
    	f=f->next;
	}
	cout<<"Datos de A"<<endl;
    /* Ordenar las sublistas de forma recursiva */
    MergeSort(&a); 
    MergeSort(&b); 
    /* Para fusionar las dos listas ordenadas juntas */
    *headRef = SortedMerge(a, b); 
} 
  
/* Para Fusionar dos listas ordenadas */
Node* SortedMerge(Node* a, Node* b) 
{ 
    Node* result = NULL; 
  
    /* Casos base */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Elige A y B, repite */
    if (a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 
  
/* Funciones */
/* Divide los nodos de la lista dada en mitades delantera y trasera,
    y devuelve las dos listas usando los parámetros de referencia.
    Si la longitud es impar, el nodo adicional debe ir en la lista frontal.
    Utiliza la estrategia de puntero rápido / lento. */
void cortarLista(Node* source, Node** frontRef, Node** backRef) 
{ 
    Node* fast; 
    Node* slow; 
    slow = source; 
    fast = source->next; 
  
    /* Avance dos nodos 'fast' y avance un nodo 'slow' */
    while (fast != NULL) { 
        fast = fast->next;         
        if (fast != NULL) {
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    /* 'slow' está antes del punto medio de la lista, así que divídalo en dos
    en ese punto. */
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 
/* Funcion para imprimir los nodos*/
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 
  
/*  Insertar nodos */
void push(Node** head_ref, int new_data) 
{ 
    /* Asignar nodo */
    Node* new_node = new Node(); 
  
    /* poner datos */
    new_node->data = new_data; 
  
    /* 	Vincula la lista anterior al nuevo nodo */
    new_node->next = (*head_ref); 
  
    /* Mueve el inicio para apuntar al nuevo nodo */
    (*head_ref) = new_node; 
} 
  
int main() { 
    /* Empezamos con listas vacias */
    Node* a = NULL; 

    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
    printList(a);
    cout<<endl;
    /* ordenar la lista */
    MergeSort(&a); 
  
    cout << "Lista Ordenada \n"; 
    printList(a); 
  
    return 0; 
}
