#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura del nodo
struct Nodo
{
    char *dato;  // Cambiado de int a char *
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

// Función para crear un nuevo nodo
struct Nodo *crearNodo(char *dato)
{
    struct Nodo *nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nodo->dato = strdup(dato);  // Usa strdup para copiar la cadena
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

// Función para insertar un nuevo nodo en el árbol
struct Nodo *insertar(struct Nodo *raiz, char *dato)
{
    if (raiz == NULL)
    {
        return crearNodo(dato);
    }

    int comparacion = strcmp(dato, raiz->dato);

    if (comparacion < 0)
    {
        raiz->izquierda = insertar(raiz->izquierda, dato);
    }
    else if (comparacion > 0)
    {
        raiz->derecha = insertar(raiz->derecha, dato);
    }

    return raiz;
}

// Función para encontrar el nodo con el valor mínimo en un árbol
struct Nodo *encontrarMinimo(struct Nodo *nodo)
{
    while (nodo->izquierda != NULL)
    {
        nodo = nodo->izquierda;
    }
    return nodo;
}

// Función para borrar un nodo del árbol
struct Nodo *borrar(struct Nodo *raiz, char *dato)
{
    if (raiz == NULL)
    {
        return raiz;
    }

    int comparacion = strcmp(dato, raiz->dato);

    if (comparacion < 0)
    {
        raiz->izquierda = borrar(raiz->izquierda, dato);
    }
    else if (comparacion > 0)
    {
        raiz->derecha = borrar(raiz->derecha, dato);
    }
    else
    {
        // Nodo con un solo hijo o sin hijos
        if (raiz->izquierda == NULL)
        {
            struct Nodo *temp = raiz->derecha;
            free(raiz->dato);
            free(raiz);
            return temp;
        }
        else if (raiz->derecha == NULL)
        {
            struct Nodo *temp = raiz->izquierda;
            free(raiz->dato);
            free(raiz);
            return temp;
        }

        // Nodo con dos hijos: obtener el sucesor inorden (nodo mínimo en el subárbol derecho)
        struct Nodo *temp = encontrarMinimo(raiz->derecha);

        // Copiar el contenido del sucesor inorden al nodo actual
        free(raiz->dato);
        raiz->dato = strdup(temp->dato);

        // Borrar el sucesor inorden
        raiz->derecha = borrar(raiz->derecha, temp->dato);
    }

    return raiz;
}


// Función para buscar un nodo con un valor dado
struct Nodo *buscar(struct Nodo *raiz, char *dato)
{
    if (raiz == NULL || strcmp(raiz->dato, dato) == 0)
    {
        return raiz;
    }

    if (strcmp(dato, raiz->dato) < 0)
    {
        return buscar(raiz->izquierda, dato);
    }
    else
    {
        return buscar(raiz->derecha, dato);
    }
}


// Función para mostrar el árbol en preorden
void preorden(struct Nodo *raiz)
{
    if (raiz != NULL)
    {
        printf("%s ", raiz->dato);
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

// Función para mostrar el árbol en inorden
void inorden(struct Nodo *raiz)
{
    if (raiz != NULL)
    {
        inorden(raiz->izquierda);
        printf("%s ", raiz->dato);
        inorden(raiz->derecha);
    }
}

// Función para mostrar el árbol en postorden
void postorden(struct Nodo *raiz)
{
    if (raiz != NULL)
    {
        postorden(raiz->izquierda);
        postorden(raiz->derecha);
        printf("%s ", raiz->dato);
    }
}


// Función principal
int main()
{
     struct Nodo *raiz = NULL;

    raiz = insertar(raiz, "Perro");
    raiz = insertar(raiz, "Gato");
    raiz = insertar(raiz, "Elefante");
    raiz = insertar(raiz, "León");
    raiz = insertar(raiz, "Tigre");
    raiz = insertar(raiz, "Zorro");
    raiz = insertar(raiz, "Jirafa");

    printf("Árbol en preorden: ");
    preorden(raiz);
    printf("\n");

    printf("Árbol en inorden: ");
    inorden(raiz);
    printf("\n");

    printf("Árbol en postorden: ");
    postorden(raiz);
    printf("\n");

    char *datoBuscado = "Tigre";
    if (buscar(raiz, datoBuscado) != NULL)
    {
        printf("El nodo con el valor %s se encuentra en el árbol.\n", datoBuscado);
    }
    else
    {
        printf("El nodo con el valor %s no se encuentra en el árbol.\n", datoBuscado);
    }

    char *datoBorrar = "Gato";
    raiz = borrar(raiz, datoBorrar);

    printf("Árbol después de borrar el nodo con el valor %s en inorden: ", datoBorrar);
    inorden(raiz);
    printf("\n");

    return 0;
}
