#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int vertice;
    int costo;
    struct Node* siguiente;
}Node;

typedef struct List{
    int vertice;
    struct Node* cabezera;
    struct Node* final;
    struct List* siguiente;
}List;

List* crearLista(int vertice){
    List* lista = (List*) malloc(sizeof(List));
    lista->vertice = vertice;
    lista->cabezera = NULL;
    lista->final = NULL;
    lista->siguiente = NULL;
    return lista;
}

Node* crearNodo(int vertice, int costo){
    Node* nodo = (Node*) malloc(sizeof(nodo));
    nodo->vertice = vertice;
    nodo->costo = costo;
    nodo->siguiente = NULL;
    return nodo;
}

void borrarNodo(Node* nodo){
    free(nodo);
}

void borrarLista(List* lista){
    free(lista);
}

void insertarNodo(List* lista, Node* nodo){
    if(lista->cabezera == NULL && lista->final == NULL){
        lista->cabezera=nodo;
        lista->final=nodo;
    }else{
        lista->final->siguiente= nodo;
        lista->final=nodo;
    }
}

void insertarNodoLista(List* lista, int vertice, int vertice2, int costo){
    int count=0;
    int find=0;
    List* puntero = lista;
    Node* nodo = crearNodo(vertice2,costo);

    

    if(lista){
        printf("no es ta vacia");
    }else{
        printf("eata vacia");
    }

    while(count==0){

        if(puntero){
        printf("p no es ta vacia");
    }else{
        printf("p eata vacia");
    }

        if(puntero->vertice==vertice){
            printf("agregando nodo\n");
            count=1;
            find=1;
            insertarNodo(puntero,nodo);
        }else{

            if(puntero->siguiente){
                puntero=puntero->siguiente;
            }else{
                count=1;
                
            }
        }

    }

    if(find==1){
        printf("Se insertar valor en la lista\n");
    }else{
        printf("No se encontro el vertice\n");
    }

}

void insertarLista(List* lista,int vertice){
    List* puntero;
    List* listaNueva = crearLista(vertice);
    while(puntero->siguiente){
        puntero=puntero->siguiente;
    }
    puntero->siguiente=listaNueva;
}

void imprimirNodo(Node* nodo){
    Node* puntero = nodo;
    int count = 0;

    if(puntero != NULL){
        while(count == 0){
            if(puntero->siguiente){
                // printf(" %d , %d",puntero->vertice,puntero->costo);
                printf(" %d",puntero->vertice);
                // printf(" - ");
                // printf(" %d",puntero->costo);
                puntero = puntero->siguiente;
            }else{
                // printf(" %d , %d",puntero->vertice,puntero->costo);
                printf(" %d",puntero->vertice);
                // printf(" - ");
                // printf(" %d",puntero->costo);
                count=1;
            }
        }
    }else{
        printf("No hay nodo en la lista\n");
    }

}

void imprimirLista(List* lista){
    int count = 0;
    List* puntero = lista;
    
    if(lista != NULL){

        while(count==0){
            printf("vertice: %d ",puntero->vertice);
            if(puntero->siguiente){
                imprimirNodo(puntero->cabezera);
                puntero=puntero->siguiente;
            }else{
                imprimirNodo(puntero->cabezera);
                count=1;
            }
            printf("\n");
        }
    }else{
        printf("Lista vacia\n");
    }
}



int main(){
    List* lista = crearLista(1);
    insertarLista(lista,2);
    insertarLista(lista,3);
    insertarNodoLista(lista,1,3,1);
    insertarNodoLista(lista,1,4,1);
    insertarNodoLista(lista,2,6,2);
    insertarNodoLista(lista,2,1,1);
    insertarNodoLista(lista,3,2,1);
    insertarNodoLista(lista,3,3,1);
    insertarNodoLista(lista,1,5,1);
    imprimirLista(lista);
    printf("crear lista");
    return 0;
}

