#include <iostream>
#include <malloc.h>
using namespace std;

struct nodo {
    int codigoRNT;
    string nombre;
    string fechaVencimientoRNT;

    nodo *izq;
    nodo *der;
};

nodo *raiz, *aux, *aux2;

int posicionar() {
    if (aux->codigoRNT < aux2->codigoRNT) {
        if (aux2->izq == NULL) {
            aux2->izq = aux;
        } else {
            aux2 = aux2->izq;
            posicionar();
        }
    } else {
        if (aux2->der == NULL) {
            aux2->der = aux;
        } else {
            aux2 = aux2->der;
            posicionar();
        }
    }
    return 0;
}

int registrar() {
    aux = (nodo*)malloc(sizeof(struct nodo));
    cout << "Cual es el codigo RNT: " << endl;
    cin >> aux->codigoRNT;
    cout << "Cual es el nombre: " << endl;
    cin >> aux->nombre;
    cout << "Cual es la fecha de vencimiento del RNT: " << endl;
    cin >> aux->fechaVencimientoRNT;
    aux->izq = NULL;
    aux->der = NULL;

    if (!raiz) {
        raiz = aux;
    } else {
        aux2 = raiz;
        posicionar();
    }
    return 0;
}

void mostrar(nodo* temp) {
    if (temp != NULL) {
        mostrar(temp->izq);
        cout << "Codigo RNT: " << temp->codigoRNT << ", Nombre: " << temp->nombre << ", Fecha de vencimiento del RNT: " << temp->fechaVencimientoRNT << endl;
        mostrar(temp->der);
    }
}

int main() {
    int opc = 0;
    do {
        cout << "1. Registrar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "3. salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                registrar();
                break;
            case 2:
                if (raiz != NULL) {
                    cout << "Elementos del arbol: " << endl;
                    mostrar(raiz);
                    cout << endl;
                } else {
                    cout << "El arbol esta vacio." << endl;
                }
                break;
            case 3: 
                     cout << "Saliendo del progrma." << endl;
                break;
            default:
            cout << "Opcion invalida. Inyente de nuevo"<<endl;

        }
    } while (opc != 5);
    return 0;
}