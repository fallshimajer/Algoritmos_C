#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  double num;
  int position;
  struct Node* next;
}Node;

typedef struct List {
  Node* first;
  Node* last;
  int row;
  int size;
}List;

typedef struct BigList {
  List* next;
  List* previous;
  int row;
  int size;
}BigList;

Node* createNode(double i_num, int i_pos){
  Node* node = (Node*) malloc(sizeof(Node));
  node->num=i_num;
  node->position=i_pos;
  node->next=NULL;
  return node;
}

void deleteNode(Node* node){
  free(node);
}

List* createList(int row){
  List* list = (List*) malloc(sizeof(List));
  list->row = row;
  return list;
}

// BigList createBigList(){
//   BigList* bigList = (BigList) malloc(sizeof(BigList));
//   return BigList;
// }

void insertFirst(List* list, double i_num, int i_pos){
  Node* node = createNode(i_num,i_pos);
  printf("hola\n");
  node->next = list->first;
  list->first = node;
  list->last = node;
}

void insertList(BigList* bList, List* list, int row){
  if()
  blist->createList()
}

void insertLast(List* list, double i_num, int i_pos){
  Node* node = createNode(i_num,i_pos);
  list->last->next = node;
  list->last = node;
}
void insertNode(List* list, double i_num,int i_pos){
  Node* node = createNode(i_num,i_pos);
  int position;
  Node* puntero;
  if (list->first!=NULL){
    list->first=node;
    list->last=node;
  }else{
    puntero = list->first;
    while(puntero->next){
      puntero = puntero->next;
      position++;
    }
    if(position+1==i_pos){
      puntero->next = node;
      list->last=node;
    }
  }
}

int main(){
  BigList bList;
  List lista;
  List* l1 = createList(0);
  List* l2 = createList(1);
  printf("El valor de l1 es %d", l1->row);
  printf("El valor de l1 es %d", l2->row);
  insertFirst(&lista,2,3);
  insertLast(&lista,3,1);
  printf("valor de: %lf\n",lista.first->num);
  printf("valor de: %lf\n",lista.first->next->num);
  printf("Hola Mundo");

}
