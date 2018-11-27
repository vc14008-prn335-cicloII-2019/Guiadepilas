/*
 * 
 * Autor: Elmer Antonio Martir
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo {
    int valor;
    struct _nodo *siguiente;
} Nodo;


typedef Nodo *TNodo;
typedef Nodo *Pila;

//creamos la pila
void app_pila(Pila *pila, int v) {

    TNodo nuevo;

    nuevo = (TNodo) malloc(sizeof (Nodo));
    nuevo->valor = v;

    nuevo->siguiente = *pila;

    *pila = nuevo;
}

int del_pila(Pila *pila) {
    TNodo nodo;
    int valor;

    nodo = *pila;

    if (!nodo) {
        return 0;
    }

    *pila = nodo->siguiente;

    valor = nodo->valor;

    free(nodo);
    return valor;
}
//funcion para reemplazar un dato
void remplazar(Pila *pila, int viejo, int nuevo) {
    TNodo nodo;
    int encontrado = 0;
    nodo = *pila;

    while (nodo) {
        if (nodo->valor == viejo) {
            encontrado++;
            nodo->valor = nuevo;
        }
        nodo = nodo->siguiente;
    }
    if (encontrado == 0) {
        printf("\nError!!\n");
    }
}

//funcion para mostrar un dato
void mostrar(Pila *pila) {
    TNodo nodo;

    nodo = *pila;

    while (nodo) {
        printf("[%d]", nodo->valor);
        nodo = nodo->siguiente;
    }
    printf("\n");
}

int pila_vacia(Pila *pila) {
    return (*pila) ? (1) : (0);
}

int main(int argc, char *argv[]) {

    int op, num, num2;
    Pila nueva_pila = NULL;



// aqui se muestra nuestro menu
    do {
		 printf("==============\n");
        printf("Elija una Opcion\n");
        printf("==============\n");
        printf("1)Insertar\n");
        printf("2)Remplazar\n");
        printf("3)Mostrar\n");
        printf("4)Salir\n");
printf("\n");
printf("\n");
        scanf("%d", &op);
        system("clear");
                switch (op) {
            case 1:
                do {
                    printf("Introduzca un Numero:\n >");
                    scanf("%d", &num);
                    if (num != 0) app_pila(&nueva_pila, num);
                } while (num != 0);
                break;

            case 2:
                if (pila_vacia(&nueva_pila)) {
                    printf("Introduzca el numero a buscar");
                    scanf("%d", &num);

                    printf("Introduce el numero a reemplazar");
                    scanf("%d", &num2);

                    remplazar(&nueva_pila, num, num2);
                } else {
                    printf("Pila Vacia\n");
                }
                break;

            case 3:
                if (pila_vacia(&nueva_pila)) {
                    mostrar(&nueva_pila);
                } else {
                    printf("Pila Vacia\n");
                }
                break;

            case 4:
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("Error\n");
                break;
        }
    } while (1);

    return 0;
}

