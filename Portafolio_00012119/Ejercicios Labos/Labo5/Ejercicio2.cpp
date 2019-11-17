#include <iostream>

using namespace std;

struct nodo {
	int info;
	struct nodo *izq;
	struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

struct Tlnodo {
	int dato;
	struct Tlnodo *sig;
};
typedef struct Tlnodo lnodo;
lnodo *pInicio = NULL;

Arbol crearArbol(int x) {
	Arbol p = new Nodo;
	p->info = x;
	p->izq = NULL;
	p->der = NULL;
	return p;
}

void agregaraarbol(Arbol p, int unDato) {
	if (unDato > p->info) {
		if (p->der == NULL) {
			p->der = crearArbol(unDato);
		}
		else {
			agregaraarbol(p->der, unDato);
		}
	}
	else if (unDato < p->info) {
		if (p->izq == NULL) {
			p->izq = crearArbol(unDato);
		}
		else {
			agregaraarbol(p->izq, unDato);
		}
	}
	else {
		return;
	}
}

void insertarInicio(int p) {
	lnodo *nuevo = new lnodo;
	nuevo->dato = p;
	nuevo->sig = pInicio;

	pInicio = nuevo;
}

void insertarFinal(int p) {
	lnodo *nuevo = new lnodo;
	nuevo->dato = p;
	nuevo->sig = NULL;

	if (pInicio == NULL) {
		pInicio = nuevo;
	}
	else {
		lnodo *p = pInicio;
		lnodo *q = NULL;
		while (p != NULL) {
			q = p;
			p = p->sig;
		}
		q->sig = nuevo;
	}
}

void insertarDespuesDe(int p) {
	int unnumero = 0;
	cout << "Numero de referencia: ";
	cin >> unnumero;

	lnodo *s = pInicio;

	while (s != NULL && s->dato != unnumero)
		s = s->sig;
	if (s == NULL) {
		cout << "Numero de referencia NO existe" << endl;
		return;
	}

	lnodo *nuevo = new lnodo;
	nuevo->dato = p;
	nuevo->sig = s->sig;

	s->sig = nuevo;
	cout << "Numero insertado con exito" << endl;
}

void insertarAntesDe(int p) {
	int unnumero = 0;
	cout << "Numer de referencia: ";
	cin >> unnumero;

	lnodo *s = pInicio, *q = NULL;

	while (s != NULL && s->dato != unnumero) {
		q = s;
		s = s->sig;
	}
	if (s == NULL) {
		cout << "Numero de referencia NO existe" << endl;
		return;
	}

	lnodo *nuevo = new lnodo;
	nuevo->dato = p;
	nuevo->sig = s;

	if (q == NULL)
		pInicio = nuevo;
	else
		q->sig = nuevo;
	cout << "Numero insertado con exito" << endl;
}

void agregaralista(int p) {
	bool continuar = true;
	do {
		int opcion = 0;
		cout << "\t1) Al principio\n\t2) Al final"
			<< "\n\t3) Despues de\n\t4) Antes de"
			<< "\n\tOpcion elegida: ";
		cin >> opcion;
		switch (opcion) {
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
	} while (continuar);
}

void recorrerlista() {
	lnodo *s = pInicio;
	while (s != NULL) {
		cout << s->dato << " ";
		s = s->sig;
	}
	cout << endl;
}

void preorden(Arbol a) {
	if (a != NULL) {
		cout << " " << a->info;
		preorden(a->izq);
		preorden(a->der);
	}
}

void inorden(Arbol a) {
	if (a != NULL) {
		inorden(a->izq);
		cout << " " << a->info;
		inorden(a->der);
	}
}

void postorden(Arbol a) {
	if (a != NULL) {
		postorden(a->izq);
		postorden(a->der);
		cout << " " << a->info;
	}
}

void recorrerArbol(Arbol a) {
	cout << "Recorrido PRE orden:"; preorden(a); cout << endl;
	cout << "Recorrido IN orden:"; inorden(a); cout << endl;
	cout << "Recorrido POST orden:"; postorden(a); cout << endl;
}

Arbol insertaLaA(Arbol a) {
	lnodo *q = new lnodo;
	q = pInicio;
	while (q != NULL) {		
		if (a == NULL) {
			a = crearArbol(q->dato);
			q = q->sig;
		}
		else {
			agregaraarbol(a, q->dato);
			q = q->sig;
		}		
	}
	return a;
}

int main() {
	Arbol arbol = NULL;
	bool continuar = true;
	int opcion, variable;
	do {
		opcion = 0;
		cout << "\n\tMenu: ";
		cout << "\n\t1) Agregar un valor a la lista";
		cout << "\n\t2) Agregar valores de lista a arbol ";
		cout << "\n\t3) Recorrer arbol ";
		cout << "\n\t4) Mostrar Lista ";
		cout << "\n\t5) Salir";
		cout << "\n\tOpcion elegida: "; cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "\nValor a ingresar: "; cin >> variable;
			agregaralista(variable);
			break;
		case 2:
			cout << "\nAgregando...";
			arbol=insertaLaA(arbol);
			break;
		case 3:
			recorrerArbol(arbol);
			break;
		case 4:
			recorrerlista();
			break;
		case 5:
			continuar = false;
			break;
		default:
			cout << "Opcion NO valida";
		}
	} while (continuar);
	return 0;
}
