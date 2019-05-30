#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int col;
  double num;
  struct Node* next;
  struct Node* previous;
}Node;

typedef struct ListNode {
  struct Node* header;
  struct Node* footer;
  int size;
}ListNode;

typedef struct List {
  int row;
  struct List* next;
  struct List* previous;
  struct Node* header;
}List;

void welcome(){
  printf("Bienvenido\n");
  printf("Este programa te permitira calcular la potencia de Matriz\n");
}

Node* createNode(int col, double num){
  Node* node = (Node*) malloc(sizeof(Node));
  node->col=col;
  node->num=num;
  node->next=NULL;
  node->previous=NULL;
  return node;
}

ListNode* createListNode(){
  ListNode* listNode = (ListNode*) malloc(sizeof(ListNode));
  listNode->header= NULL;
  listNode->footer= NULL;
  listNode->size=0;
  return listNode;
}

List* createList(int row, Node* node){
  List* list = (List*) malloc(sizeof(List));
  list->next=NULL;
  list->previous=NULL;
  list->header=node;
  return list;
}

void insertNode(ListNode* listNode, Node* node){
    printf("iniciando\n");
    if(listNode->header == NULL && listNode->footer == NULL){
        listNode->header = node;
        listNode->footer = node;
        listNode->size++;
        printf("if\n");
    }else{
        listNode->footer->next = node;
        listNode->footer= node;
        listNode->size++;
        printf("else\n");
    }
    // if(listNode->header){
    //   printf("hola\n");
    // }else{
    //   printf("El valor de : %d\n",listNode->size);
    // }
}

int main(){
  welcome();
  ListNode* ln1 = createListNode();
  Node* node = createNode(0,1);
  Node* node2 = createNode(1,2);
  Node* node3 = createNode(2,4);
  insertNode(ln1,node);
  insertNode(ln1,node2);
  insertNode(ln1,node3);
  printf("El valor es %d",ln1->size);
  // if (ln1->header == NULL){
  //   printf("es null\n");
  // }else{
  //   printf("no es null\n");
  // }
  // insertNode(ln1,node2);
  // printf("el valor de size es %d \n",ln1->size);
  // Node* node = createNode(0,1);
  // printf("el valor es %lf",node->num);
  return 0;
}
