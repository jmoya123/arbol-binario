#include <iostream>
#include <stdlib.h>
#include <cstring> // Incluye la biblioteca cstring para usar strcpy
using namespace std;

// Estructura del nodo para el árbol principal
struct NodoPrincipal {
    int codigoRNT;
    char nombre[100];
    
    NodoPrincipal* izq;
    NodoPrincipal* der;

    
};

// Estructura del nodo para el subárbol
struct NodoSubArbol {
    char fechaVencimientoRNT[100];
    char nombre[100];
    NodoSubArbol* izq;
    NodoSubArbol* der;
};

NodoPrincipal* raizPrincipal = NULL; // Raíz del árbol principal
NodoSubArbol* raizSubArbol = NULL; // Raíz del subárbol

// Función para insertar nodos en el árbol principal
NodoPrincipal* InsertarNodoPrincipal(NodoPrincipal* nodo, int codigoRNT, char nombre[]) {
    if (nodo == NULL) {
        nodo = (NodoPrincipal*) malloc(sizeof(NodoPrincipal));
        nodo->codigoRNT = codigoRNT;
        strcpy(nodo->nombre, nombre);
        nodo->izq = nodo->der = NULL;
    } else if (codigoRNT <= nodo->codigoRNT) {
        nodo->izq = InsertarNodoPrincipal(nodo->izq, codigoRNT, nombre);
    } else {
        nodo->der = InsertarNodoPrincipal(nodo->der, codigoRNT, nombre);
    }
    return nodo;
}

// Función para insertar nodos en el subárbol
NodoSubArbol* InsertarNodoSubArbol(NodoSubArbol* nodo, char fechaVencimientoRNT[], char nombre[]) {
    if (nodo == NULL) {
        nodo = (NodoSubArbol*) malloc(sizeof(NodoSubArbol));
        strcpy(nodo->fechaVencimientoRNT, fechaVencimientoRNT);
        strcpy(nodo->nombre, nombre);
        nodo->izq = nodo->der = NULL;
    } else if (strcmp(fechaVencimientoRNT, nodo->fechaVencimientoRNT) <= 0) {
        nodo->izq = InsertarNodoSubArbol(nodo->izq, fechaVencimientoRNT, nombre);
    } else {
        nodo->der = InsertarNodoSubArbol(nodo->der, fechaVencimientoRNT, nombre);
    }
    return nodo;
}

/*void MostrarInordenPrincipal(NodoPrincipal* nodo) {
    if (nodo == NULL) {
        return;
    }
    MostrarInordenPrincipal(nodo->izq); // Recorre el subárbol izquierdo
    cout << "Codigo RNT: " << nodo->codigoRNT << ", Nombre: " << nodo->nombre << endl; // Muestra el nodo
    MostrarInordenPrincipal(nodo->der); // Recorre el subárbol derecho
}

// Función para mostrar los nodos del subárbol en inorden
void MostrarInordenSubArbol(NodoSubArbol* nodo) {
    if (nodo == NULL) {
        return;
    }
    MostrarInordenSubArbol(nodo->izq); // Recorre el subárbol izquierdo
    cout << "Fecha de vencimiento RNT: " << nodo->fechaVencimientoRNT << ", Nombre: " << nodo->nombre << endl; // Muestra el nodo
    MostrarInordenSubArbol(nodo->der); // Recorre el subárbol derecho
}

// Función principal*/
// Función para mostrar los nodos del árbol principal en preorden
void MostrarPreordenPrincipal(NodoPrincipal* nodo) {
    if (nodo == NULL) {
        return;
    }
    cout << "Codigo RNT: " << nodo->codigoRNT << ", Nombre: " << nodo->nombre << endl; // Muestra el nodo
    MostrarPreordenPrincipal(nodo->izq); // Recorre el subárbol izquierdo
    MostrarPreordenPrincipal(nodo->der); // Recorre el subárbol derecho
}

// Función para mostrar los nodos del subárbol en preorden
void MostrarPreordenSubArbol(NodoSubArbol* nodo) {
    if (nodo == NULL) {
        return;
    }
    cout << "Fecha de vencimiento RNT: " << nodo->fechaVencimientoRNT << ", Nombre: " << nodo->nombre << endl; // Muestra el nodo
    MostrarPreordenSubArbol(nodo->izq); // Recorre el subárbol izquierdo
    MostrarPreordenSubArbol(nodo->der); // Recorre el subárbol derecho
}

void MostrarInordenPrincipal(NodoPrincipal* nodo) {
    if (nodo == NULL) {
        return;
    }
    MostrarInordenPrincipal(nodo->izq); // Recorre el subárbol izquierdo
    cout << "Codigo RNT: " << nodo->codigoRNT << ", Nombre: " << nodo->nombre << endl; // Muestra el nodo
    MostrarInordenPrincipal(nodo->der); // Recorre el subárbol derecho
}

// Función para mostrar los nodos del subárbol en inorden
void MostrarInordenSubArbol(NodoSubArbol* nodo) {
    if (nodo == NULL) {
        return;
    }
    MostrarInordenSubArbol(nodo->izq); // Recorre el subárbol izquierdo
    cout << "Fecha de vencimiento RNT: " << nodo->fechaVencimientoRNT << ", Nombre: " << nodo->nombre << endl; // Muestra el nodo
    MostrarInordenSubArbol(nodo->der); // Recorre el subárbol derecho
}


// Función para mostrar los nodos del árbol principal en posorden
void MostrarPosordenPrincipal(NodoPrincipal* nodo) {
    if (nodo == NULL) {
        return;
    }
    MostrarPosordenPrincipal(nodo->izq); // Recorre el subárbol izquierdo
    MostrarPosordenPrincipal(nodo->der); // Recorre el subárbol derecho
    cout << "Codigo RNT: " << nodo->codigoRNT << ", Nombre: " << nodo->nombre << endl; // Muestra el nodo
}

// Función para mostrar los nodos del subárbol en posorden
void MostrarPosordenSubArbol(NodoSubArbol* nodo) {
    if (nodo == NULL) {
        return;
    }
    MostrarPosordenSubArbol(nodo->izq); // Recorre el subárbol izquierdo
    MostrarPosordenSubArbol(nodo->der); // Recorre el subárbol derecho
    cout << "Fecha de vencimiento RNT: " << nodo->fechaVencimientoRNT << ", Nombre: " << nodo->nombre << endl; // Muestra el nodo
}

// Función para encontrar el mínimo valor en un árbol
NodoPrincipal* EncontrarMin(NodoPrincipal* nodo) {
    while (nodo->izq != NULL) nodo = nodo->izq;
    return nodo;
}

// Función para eliminar un nodo del árbol principal
NodoPrincipal* EliminarNodoPrincipal(NodoPrincipal* nodo, int codigoRNT) {
    if (nodo == NULL) return nodo;
    else if (codigoRNT < nodo->codigoRNT) nodo->izq = EliminarNodoPrincipal(nodo->izq, codigoRNT);
    else if (codigoRNT > nodo->codigoRNT) nodo->der = EliminarNodoPrincipal(nodo->der, codigoRNT);
    else {
        // Caso 1: No hay hijos
        if (nodo->izq == NULL && nodo->der == NULL) {
            free(nodo);
            nodo = NULL;
        }
        // Caso 2: Un hijo
        else if (nodo->izq == NULL) {
            NodoPrincipal* temp = nodo;
            nodo = nodo->der;
            free(temp);
        }
        else if (nodo->der == NULL) {
            NodoPrincipal* temp = nodo;
            nodo = nodo->izq;
            free(temp);
        }
        // Caso 3: Dos hijos
        else {
            NodoPrincipal* temp = EncontrarMin(nodo->der);
            nodo->codigoRNT = temp->codigoRNT;
            strcpy(nodo->nombre, temp->nombre);
            nodo->der = EliminarNodoPrincipal(nodo->der, temp->codigoRNT);
        }
    }
    return nodo;
}


int main() {
    

    int opcion;
    int codigoRNT;
    char nombre[100];
    char fechaVencimientoRNT[100];

    do {
        cout << "1. Insertar nodo en el árbol principal" << endl;
        cout << "2. Insertar nodo en el subárbol" << endl;
        cout << "3. Mostrar nodos del árbol principal en Preorden" << endl;
        cout << "4. Mostrar nodos del subárbol en Preorden" << endl;
        cout << "5. Mostrar nodos del árbol principal en Inorden" << endl;
        cout << "6. Mostrar nodos del SubArbol en Inorden" << endl;
        cout << "7. Mostrar nodos del árbol principal en Posorden" << endl;
        cout << "8. Mostrar nodos del SubArbol en Posorden" << endl;
        cout << "9. Ingrese el código RNT del nodo a eliminar: "<< endl;
        cout << "10. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el código RNT: ";
                cin >> codigoRNT;
                cout << "Ingrese el nombre: ";
                cin >> nombre;
                raizPrincipal = InsertarNodoPrincipal(raizPrincipal, codigoRNT, nombre);
                break;
            case 2:
                cout << "Ingrese la fecha de vencimiento RNT: ";
                cin >> fechaVencimientoRNT;
                cout << "Ingrese el nombre: ";
                cin >> nombre;
                raizSubArbol = InsertarNodoSubArbol(raizSubArbol, fechaVencimientoRNT, nombre);
                break;
            case 3:
                cout << "Nodos del árbol principal en preorden: " << endl;
                MostrarPreordenPrincipal(raizPrincipal);
                break;
			case 4:
                cout << "Nodos del subarbol en preorden: " << endl;
                MostrarPreordenSubArbol(raizSubArbol);
                break;	    
            case 5:
                cout << "Nodos del árbol principal en Inorden: " << endl;
                MostrarInordenPrincipal(raizPrincipal);
                break;
			case 6:
                cout << "Nodos del subárbol en Inorden: " << endl;
                MostrarInordenSubArbol(raizSubArbol);
                break;	    
            case 7:
                cout << "Nodos del árbol principal en Posorden: " << endl;
                MostrarPosordenPrincipal(raizPrincipal);
                break;
            case 8:
                cout << "Nodos del subárbol en Posorden:" << endl;
                MostrarPosordenSubArbol(raizSubArbol);
                break;
            case 9:
                cout << "Ingrese el código RNT del nodo a eliminar: ";
                cin >> codigoRNT;
                raizPrincipal = EliminarNodoPrincipal(raizPrincipal, codigoRNT);
                break;    
            case 10:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, intente de nuevo." << endl;
                break;
        }
    } while (opcion != 10);

    return 0;
}







