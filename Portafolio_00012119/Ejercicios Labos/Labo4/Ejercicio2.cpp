#include <iostream>
using namespace std;

struct nodo
{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

Arbol crearArbol(int x)
{
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

void asignarIzq(Arbol a, int unDato)
{
    if (a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if (a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato)
{
    if (a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if (a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a)
{
    int numero = 0;
    cout << "Numero a agregar: ";
    cin >> numero;

    Arbol p = a;

    while (true)
    {
        if (numero == p->info)
        {
            cout << "Error: " << numero << " ya existe" << endl;
            return;
        }
        else if (numero < p->info)
        {
            if (p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else
        {
            if (p->der == NULL)
                break;
            else
                p = p->der;
        }
    }

    if (numero < p->info)
        asignarIzq(p, numero);
    else
        asignarDer(p, numero);
}

bool hijos(Arbol a)
{
    if (a->der != NULL || a->izq != NULL)
    {
        return true;
    }
}
void cantidadNiveles(Arbol a, int suma)
{
    if (a != NULL)
    {
        if (hijos(a))
        {
            suma += 1;
        }
        cantidadNiveles(a->izq, suma);
        cantidadNiveles(a->der, suma);
    }
    else
    {
        cout << "Suma de nodos es: " << suma << endl;
    }
}

void cantidadNodos(Arbol a, int suma)
{
    if (a != NULL)
    {
        suma += 1;
        cantidadNodos(a->izq, suma);
        cantidadNodos(a->der, suma);
    }
    else
    {
        cout << "Suma de nodos es: " << suma << endl;
    }
}

void sumaNodos(Arbol a, int suma)
{
    if (a != NULL)
    {
        suma += a->info;
        sumaNodos(a->izq, suma);
        sumaNodos(a->der, suma);
    }
    else
    {
        cout << "Suma de nodos es: " << suma << endl;
    }
}
void sumaNodosPares(Arbol a, int &suma)
{
    if (a != NULL)
    {
    	 if(a->info % 2 == 0){
        	        suma +=a->info;
		}
        sumaNodosPares(a->izq, suma);
        sumaNodosPares(a->der, suma);
        
       
    }
}
void sumaNodosImpares(Arbol a, int &suma)
{
    if (a != NULL)
    {
    	 if(a->info % 2 != 0){
        suma +=a->info;
		}
        sumaNodosImpares(a->izq, suma);
        sumaNodosImpares(a->der, suma);   
    }
}
void cantidadNodosParesImp(Arbol a, int &contador, int &contador2)
{
    if (a != NULL)
    {
    	if(a->info % 2 == 0){
    		contador += 1;
		}
		else if(a->info % 2 != 0){
			contador2 += 1;
		}
        cantidadNodosParesImp(a->izq, contador, contador2);
        cantidadNodosParesImp(a->der, contador, contador2);
    }
}
void cantidadNodosNegPosCeros(Arbol a, int &contador1, int &contador2, int &contador3)
{
    if (a != NULL)
    {
    	if(a->info < 0){
    		contador1 += 1;
		}
		else if(a->info > 0){
			contador2 += 1;
		}
		else if(a->info == 0){
			contador3 += 1;
		}
        cantidadNodosNegPosCeros(a->izq, contador1, contador2, contador3);
        cantidadNodosNegPosCeros(a->der, contador1, contador2, contador3);
    }
}


int main()
{
    int variable = 0;
    cout << "Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> variable;

    Arbol arbol = crearArbol(variable);

    bool continuar = true;
    do
    {
    	
    int suma,contador1, contador2, contador3;

        int opcion = 0;
        cout << "Menu: \n\t1) Agregar\n\t2) Suma de nodos pares\n\t3) Suma de nodos impares\n\t4) Saber cantidad de nodos pares\n\t5) Saber cuantos nodos, negativos, positivos e iguales a cero, hay "
             << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            agregarNodo(arbol);
            break;
        case 2:
        	suma = 0;
            sumaNodosPares(arbol, suma);
            cout<<"---------------------"<<endl;
            cout<<"Suma de nodos pares es: "<<suma<<endl;
            cout<<"---------------------"<<endl;
            break;
        case 3:
        	suma = 0;
            sumaNodosImpares(arbol, suma);
            cout<<"---------------------"<<endl;
            cout<<"Suma de nodos impares es: "<<suma<<endl;
            cout<<"---------------------"<<endl;
            break;
        case 4:
        	contador1 = 0;
        	contador2 = 0;
            cantidadNodosParesImp(arbol, contador1, contador2);
            cout<<"---------------------"<<endl;
            cout<<"Cantidad de nodos pares: "<<contador1<<endl;
            cout<<"---------------------"<<endl;
            cout<<"Cantidad de nodos impares: "<<contador2<<endl;
            cout<<"---------------------"<<endl;
            break;
            
        case 5:
        	contador1 = 0;
        	contador2 = 0;
        	contador3 = 0;
            cantidadNodosNegPosCeros(arbol, contador1, contador2, contador3);
            cout<<"---------------------"<<endl;
            cout<<"Cantidad de nodos negativos: "<<contador1<<endl;
            cout<<"---------------------"<<endl;
            cout<<"Cantidad de nodos positivos: "<<contador2<<endl;
            cout<<"---------------------"<<endl;
            cout<<"Cantidad de nodos iguales a cero: "<<contador3<<endl;
            cout<<"---------------------"<<endl;
            break;
                
        default:
            cout << "Opcion erronea!" << endl;
            break;
        }
    } while (continuar);

    return 0;
}
