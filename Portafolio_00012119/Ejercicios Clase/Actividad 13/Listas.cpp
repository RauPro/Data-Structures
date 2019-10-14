#include <iostream>
#include <string>
using namespace std;

enum generos{ciencia_ficcion,aventura,policial,romance,misterio};

struct TLibro{
    int isbn;
    string titulo;
    string autor;
    generos genero;
    bool espanol;
};
typedef struct TLibro Libro;

Libro solicitarLibro(){
    Libro p;
    
    //---Solicitar ISBN, Titulo y Autor---
    cout << "ISBN: "; cin >> p.isbn;
    cin.ignore();//Limpiando el buffer
    cout << "Titulo: "; getline(cin, p.titulo);
    cout << "Autor: "; getline(cin, p.autor);
    
    //---Solicitar genero del libro---
    bool continuar = true;
    do{
        char opcion = 0;
        cout << "Genero (c-ciencia|a-aventura|p-policial|r-romance|m-misterio): ";
        cin >> opcion;
        switch(opcion){
            case 'c': p.genero = ciencia_ficcion;   continuar = false;
                break;
            case 'a': p.genero = aventura;   continuar = false;
                break;
            case 'p': p.genero = policial;   continuar = false;
                break;
            case 'r': p.genero = romance;   continuar = false;
                break;
            case 'm': p.genero = misterio;   continuar = false;
                break;
            default: cout << "Opcion erronea!" << endl;
                break;
        }
    }while(continuar);
    
    //---Solicitar idioma del libro---
    continuar = true;
    do{
        char letra = 0;
        cout << "Espanol (s/n): ";
        cin >> letra;
        switch(letra){
            case 's':
            case 'S': p.espanol = true;   continuar = false;
                break;
            case 'n':
            case 'N': p.espanol = false;   continuar = false;
                break;
            default: cout << "Opcion erronea!" << endl;
                break;
        }
    }while(continuar);
    
    //---Devolver libro ya poblado---
    return p;
}

void mostrarLibro(Libro p){
    cout << "ISBN: " << p.isbn << endl;
    cout << "Titulo: " << p.titulo << endl;
    cout << "Autor: " << p.autor << endl;
    
    cout << "Genero: ";
    switch(p.genero){
        case ciencia_ficcion: cout << "Ciencia ficcion" << endl;
            break;
        case aventura: cout << "Aventura" << endl;
            break;
        case policial: cout << "Policial" << endl;
            break;
        case romance: cout << "Romance" << endl;
            break;
        case misterio: cout << "Misterio" << endl;
            break;
    }
    
    cout << "Idioma: " << (p.espanol ? "Espanol" : "Otro") << endl;
    cout << endl;
}

struct TNodo{
    Libro dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(Libro p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;
    
    pInicio = nuevo;
}

void insertarFinal(Libro p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;
    
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void insertarDespuesDe(Libro p) {
    int unISBN = 0;
    cout << "ISBN de libro de referencia: ";
    cin >> unISBN;
    
    Nodo *s = pInicio;
    
    while(s != NULL && (s->dato).isbn != unISBN)
        s = s->sig;
    if(s == NULL){
        cout << "Libro de referencia NO existe" << endl;
        return;
    }
    
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s->sig;
    
    s->sig = nuevo;
    cout << "Libro insertado con exito" << endl;
}

void insertarAntesDe(Libro p) {
    int unISBN = 0;
    cout << "ISBN de libro de referencia: ";
    cin >> unISBN;
    
    Nodo *s = pInicio, *q = NULL;
    
    while(s != NULL && (s->dato).isbn != unISBN){
        q = s;
        s = s->sig;
    }
    if(s == NULL){
        cout << "Libro de referencia NO existe" << endl;
        return;
    }
    
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s;
    
    if(q == NULL)
        pInicio = nuevo;
    else
        q->sig = nuevo;
    cout << "Libro insertado con exito" << endl;
}

void agregarLibro(){
    Libro p = solicitarLibro();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
        << "\n\t3) Despues de\n\t4) Antes de"
        << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);  continuar = false;
                break;
            case 2: insertarFinal(p);   continuar = false;
                break;
            case 3: insertarDespuesDe(p);   continuar = false;
                break;
            case 4: insertarAntesDe(p);   continuar = false;
                break;
            default: cout << "Opcion erronea!" << endl;
                break;
        }
    }while(continuar);
}

void mostrarLista() {
    Nodo *s = pInicio;
    
    while (s != NULL) {
        mostrarLibro(s->dato);
        s = s->sig;
    }
}

void eliminarLibro(){
    int unISBN = 0;
    cout << "ISBN de libro a eliminar: ";
    cin >> unISBN;
    
    Nodo *p = pInicio, *q = NULL;
    
    while(p != NULL && (p->dato).isbn != unISBN){
        q = p;
        p = p->sig;
    }
    if(p == NULL){
        cout << "Libro a borrar NO existe" << endl;
        return;
    }
    if(q == NULL)
        pInicio = p->sig;
    else
        q->sig = p->sig;
    delete(p);
    cout << "Libro borrado!" << endl;
}

bool buscarLibro() {
    int unISBN = 0;
    cout << "ISBN de libro a buscar: ";
    cin >> unISBN;
    
    Nodo *s = pInicio;
    
    while(s != NULL && (s->dato).isbn != unISBN)
        s = s->sig;
    
    //Si s!=NULL entonces el libro SI se encuentra
    //Si s==NULL entonces el libro NO se encuentra
    return (s != NULL);
}




//my code
bool existSpanish(){
    Nodo *s = pInicio;
    
    while(s != NULL && (s->dato).espanol != true)
        s = s->sig;
    
    return (s != NULL);
}

bool existSCIFI(){
    Nodo *s = pInicio;
    
    while(s != NULL && (s->dato).genero != ciencia_ficcion)
        s = s->sig;
    
    return (s != NULL);
}

bool removeMisterio(){
    Nodo *p = pInicio, *q = NULL;
    
    while(p != NULL && (p->dato).genero != misterio){
        q = p;
        p = p->sig;
    }
    if(p == NULL){
        return false;
    }
    if(q == NULL)
        pInicio = p->sig;
    else
        q->sig = p->sig;
    delete(p);
    removeMisterio();
    
    return true;
}

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Libro\n\t2) Ver Libros"
        << "\n\t3) Eliminar libro\n\t4) Buscar Libro"
        << "\n\t5) Buscar libro en español\n\t6) Buscar libro de ciencia ficción"
        << "\n\t7) Eliminar libros de misterio"
        << "\n\t8) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarLibro();
                break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
                break;
            case 3: cout << "Eliminando..." << endl;
                eliminarLibro();
                break;
            case 4: cout << "Buscando..." << endl;
                if(buscarLibro())
                    cout << "El libro SI se encuentra" << endl;
                else
                    cout << "El libro NO se encuentra" << endl;
                break;
            case 5: cout << "Buscando..." << endl;
                if(existSpanish())
                    cout << "Existe algún libro en español" << endl;
                else
                    cout << "No exite ningun libro en español" << endl;
                break;
            case 6: cout << "Buscando..." << endl;
                if(existSCIFI())
                    cout << "Existe algún libro de ciencia ficción" << endl;
                else
                    cout << "No exite ningun libro de ciencia ficción" << endl;
                break;
            case 7: cout << "Buscando..." << endl;
                if(removeMisterio())
                    cout << "Libros borrado!" << endl;
                else
                    cout << "No exite ningun libro de misterio para borrar" << endl;
                break;
            case 8: continuar = false;
                break;
            default: cout << "Opcion erronea!" << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
