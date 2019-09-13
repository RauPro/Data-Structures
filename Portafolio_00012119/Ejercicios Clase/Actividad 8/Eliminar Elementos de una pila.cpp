#include <iostream>
using namespace std;

struct Tpila{
    float elements[100];
    int top;
};
typedef struct Tpila Pila;

void initialize(Pila *s){
    s->top = -1;
}

bool empty(Pila *s){
    return s->top < 0;
}
void push(Pila *s, float e){
    if(s->top < 99){
        (s->top)++;
        s->elements[s->top] = e;
    }
}
float pop(Pila *s, float *e){
    if(s->top >= 0){
        *e = s->elements[s->top];
        (s->top)--;
        return *e;
    }
}
void eliminarElementos(Pila *s, float acum){
    pop(s,&acum);

}


int main() {
    Pila unaPila;
    Pila pila2;
    initialize(&unaPila);
    initialize(&pila2);
    float acum=0,acum2;
    int i;
    push(&unaPila, 8.2);
    push(&unaPila, 3.4);
    push(&unaPila, 7.4);
    push(&unaPila, 4.4);
    while (!empty(&unaPila))
    {
        i=pop(&unaPila,&acum);
        push(&pila2,i);
    }
    cout<<acum; 
	 while (!empty(&pila2)){
        i=pop(&pila2,&acum2);
        push(&unaPila,i);
    }
    //push(&unaPila, 5.6);
}
