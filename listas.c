#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    int dato;
    struct nodo* siguiente;
}nodo;

typedef struct lista {
  nodo *cabeza;
  int tamanio;
}lista;

void crearLista(lista *l){
  l->cabeza = NULL;
  l->tamanio=0;
  struct nodo* siguiente;
}

void insertarCabeza(lista *l,int dato){
  nodo *nuevoNodo;

  if(l->cabeza==NULL && l->tamanio==0){
    nuevoNodo = (nodo*) malloc(sizeof(nodo));
    // nuevoNodo->dato=dato;
    l->cabeza = nuevoNodo;
    l->cabeza->dato =dato;
    l->tamanio++;
  }else{
    printf("Esta lista ya tiene una cabeza\n");
  }
}

int main(){
  lista l1;
  crearLista(&l1);
  insertarCabeza(&l1,2);
  printf("El valor del dato en la cabezera es: %d y su tamanio es %d\n",l1.cabeza->dato,l1.tamanio);

  return 0;
}
