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
  struct ListNode* listNode;
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

List* createList(){
  List* list = (List*) malloc(sizeof(List));
  list->row = 0;
  list->listNode = NULL;
  list->next = NULL;
  list->previous = NULL;
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
}

void insertList(List* list,ListNode* listNode, int row){
    List* listNew = (List*) malloc(sizeof(List));
    List* pointer = list;

    if(list->next == NULL){
      printf("Es NULL next ");
    }
    if(list->previous == NULL){
      printf("Es NULL previous ");
    }
    if(list->listNode == NULL){
      printf("Es NULL listNode ");
    }
    if(list->next == NULL && list->previous == NULL && list->listNode == NULL){
        list->listNode=listNode;
        list->row=0;
    }else{
        printf("valor de row: %d\n",row);
        printf("pasando por aqui!!\n");
        while(pointer->next != NULL){
          printf("Valor de siguiente %p",pointer->next);
          pointer = pointer->next;
        }
        pointer->next = listNew;
        listNew->listNode = listNode;
        listNew->row = row;
        listNew->next= NULL;
        listNew->previous = pointer;
    }
}

List* readFile(){
  List* list = createList();
  // ListNode* listNode = (ListNode*) malloc(sizeof(ListNode));
  ListNode* listNode;
  // Node* node = (Node*) malloc(sizeof(Node));
  Node* node;
  FILE* file = fopen("datos.in","rt");
  int count,pow,i,j;
  double num;
  if(file == NULL){
    printf("El archivo cargado presenta problemas");
  }else{
    printf("El archivo fue cargado con exito\n");
    fscanf(file,"%d",&count);
    fscanf(file,"%d",&pow);

    for(i=0;i<count;i++){
      listNode = createListNode();
      for(j=0;j<count;j++){
        fscanf(file,"%lf",&num);
        printf("num : %lf\n",num);
        node= createNode(j,num);
        insertNode(listNode,node);
        printf("El valor de size : %d\n",listNode->size);
      }
      printf("el valor de row enviado es %d\n",i);
      insertList(list,listNode,i);
      listNode = NULL;

    }
  }
  return list;
}

int main(){
  welcome();
  // ListNode* ln1 = createListNode();
  // int i,num;
  // Node* node;
  // for(i=0;i<10;i++){
  //   printf("ingresa un nuevo nodo : ");
  //   scanf("%d",&num);
  //   node = createNode(i,num);
  //   insertNode(ln1,node);
  //   // printf("Valor de size: %d",ln1->size);
  // }
  // List* list = createList();
  // insertList(list,ln1,0);
  // printf("La lista tiene una columna Row:%d y el tamanio de esa lista %d",list->row,list->listNode->size);
  // insertList(list,ln1,1);
  // printf("La lista tiene una columna Row:%d",list->next->row);
  // if(list->next == NULL){
  //   printf("Es nulo");
  // }


  List* l1 = readFile();
  printf("Finalizo\n");
  printf("%d\n",l1->listNode->size);
  printf("%.0lf\n",l1->next->next->next->listNode->header->num);
  // printf("El valor es %d",ln1->size);
  // printf("EL valor de la ultima posicion es: %lf",ln1->footer);
  return 0;
}
