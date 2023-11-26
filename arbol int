#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct Nodo {
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int dato) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

// Función para insertar un nuevo nodo en el árbol
struct Nodo* insertar(struct Nodo* raiz, int dato) {
    if (raiz == NULL) {
        return crearNodo(dato);
    }

    if (dato < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, dato);
    } else if (dato > raiz->dato) {
        raiz->derecha = insertar(raiz->derecha, dato);
    }

    return raiz;
}

// Función para encontrar el nodo con el valor mínimo en un árbol
struct Nodo* encontrarMinimo(struct Nodo* nodo) {
    while (nodo->izquierda != NULL) {
        nodo = nodo->izquierda;
    }
    return nodo;
}

// Función para borrar un nodo del árbol
struct Nodo* borrar(struct Nodo* raiz, int dato) {
    if (raiz == NULL) {
        return raiz;
    }

    if (dato < raiz->dato) {
        raiz->izquierda = borrar(raiz->izquierda, dato);
    } else if (dato > raiz->dato) {
        raiz->derecha = borrar(raiz->derecha, dato);
    } else {
        // Nodo con un solo hijo o sin hijos
        if (raiz->izquierda == NULL) {
            struct Nodo* temp = raiz->derecha;
            free(raiz);
            return temp;
        } else if (raiz->derecha == NULL) {
            struct Nodo* temp = raiz->izquierda;
            free(raiz);
            return temp;
        }

        // Nodo con dos hijos: obtener el sucesor inorden (nodo mínimo en el subárbol derecho)
        struct Nodo* temp = encontrarMinimo(raiz->derecha);

        // Copiar el contenido del sucesor inorden al nodo actual
        raiz->dato = temp->dato;

        // Borrar el sucesor inorden
        raiz->derecha = borrar(raiz->derecha, temp->dato);
    }

    return raiz;
}

// Función para buscar un nodo con un valor dado
struct Nodo* buscar(struct Nodo* raiz, int dato) {
    if (raiz == NULL || raiz->dato == dato) {
        return raiz;
    }

    if (dato < raiz->dato) {
        return buscar(raiz->izquierda, dato);
    }

    return buscar(raiz->derecha, dato);
}

// Función para mostrar el árbol en preorden
void preorden(struct Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dato);
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

// Función para mostrar el árbol en inorden
void inorden(struct Nodo* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierda);
        printf("%d ", raiz->dato);
        inorden(raiz->derecha);
    }
}

// Función para mostrar el árbol en postorden
void postorden(struct Nodo* raiz) {
    if (raiz != NULL) {
        postorden(raiz->izquierda);
        postorden(raiz->derecha);
        printf("%d ", raiz->dato);
    }
}

// Función principal
int main() {
    struct Nodo* raiz = NULL;

    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    printf("Árbol en preorden: ");
    preorden(raiz);
    printf("\n");

    printf("Árbol en inorden: ");
    inorden(raiz);
    printf("\n");

    printf("Árbol en postorden: ");
    postorden(raiz);
    printf("\n");

    int datoBuscado = 40;
    if (buscar(raiz, datoBuscado) != NULL) {
        printf("El nodo con el valor %d se encuentra en el árbol.\n", datoBuscado);
    } else {
        printf("El nodo con el valor %d no se encuentra en el árbol.\n", datoBuscado);
    }

    int datoBorrar = 30;
    raiz = borrar(raiz, datoBorrar);

    printf("Árbol después de borrar el nodo con el valor %d en inorden: ", datoBorrar);
    inorden(raiz);
    printf("\n");

    return 0;
}

