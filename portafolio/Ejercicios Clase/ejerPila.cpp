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
void pop(Pila *s, float *e){
    if(s->top >= 0){
        *e = s->elements[s->top];
        (s->top)--;
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
    float acum=0;
    push(&unaPila, 8.2);
    push(&unaPila, 3.4);
    push(&unaPila, 7.4);
    push(&unaPila, 4.4);
    while (!empty(&unaPila))
    {
        pop(&unaPila,&acum);
        pila2->elements[pila2->top]
    }
    cout<<acum;   
    //push(&unaPila, 5.6);
}