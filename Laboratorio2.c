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

double selectPos(List* list,int row,int cols,int size);

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
    // printf("iniciando\n");
    if(listNode->header == NULL && listNode->footer == NULL){
        listNode->header = node;
        listNode->footer = node;
        listNode->size++;
        // printf("if\n");
    }else{
        listNode->footer->next = node;
        node->previous = listNode->footer;// se agrega anterior
        listNode->footer= node;
        listNode->size++;
        // printf("else\n");
    }
}

void insertList(List* list,ListNode* listNode, int row){
    List* listNew = (List*) malloc(sizeof(List));
    List* pointer = list;

    // if(list->next == NULL){
    //   printf("Es NULL next ");
    // }
    // if(list->previous == NULL){
    //   printf("Es NULL previous ");
    // }
    // if(list->listNode == NULL){
    //   printf("Es NULL listNode ");
    // }
    if(list->next == NULL && list->previous == NULL && list->listNode == NULL){
        list->listNode=listNode;
        list->row=0;
    }else{
        // printf("valor de row: %d\n",row);
        // printf("pasando por aqui!!\n");
        while(pointer->next != NULL){
          // printf("Valor de siguiente %p",pointer->next);
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
        // printf("num : %lf\n",num);

        if (num != 0){
          node= createNode(j,num);
          insertNode(listNode,node);

        }
        // printf("El valor de size : %d\n",listNode->size);
      }

      // printf("el valor de row enviado es %d\n",i);
      if(listNode->header){
        insertList(list,listNode,i);
        listNode = NULL;
      }
      listNode = NULL;

    }
  }
  return list;
}

int readSize(){
  int size;
  FILE* file = fopen("datos.in","rt");
  if(file != NULL){
    fscanf(file,"%d",&size);
  }else{
    printf("Hay un error al cargar el archivo, al obtener el tamaño");
  }
  return size;
}

int readPow(){
  int pow;
  FILE* file = fopen("datos.in","rt");
  if(file != NULL){
    fscanf(file,"%d",&pow);
    fscanf(file,"%d",&pow);
  }else{
    printf("Hay un error al cargar el archivo, al obtener el pow");
  }
  return pow;
}

void printList(List* list){
  List* pointer = list;
  Node* pointer2;
  printf("\n\n\nimprimiendo lista\n\n\n");
  while(pointer->next){
    pointer2 = pointer->listNode->header;
    while(pointer2->next){
      printf("%0.lf ",pointer2->num);
      pointer2= pointer2->next;
    }
    printf("%0.lf ", pointer2->num);
    // printf("%0.lf",pointer->listNode->header->num);
    printf("\n");
    pointer = pointer->next;

  }
  pointer2 = pointer->listNode->header;
  while(pointer2->next){
    printf("%0.lf ",pointer2->num);
    pointer2= pointer2->next;
  }
  printf("%0.lf \n", pointer2->num);
}

double calculate(List* list1, List* list2, int row,int col,int size){
  int i;
  double cal = 0;
  for(i=0;i<size;i++){
    cal = cal + selectPos(list1,row,i,size) * selectPos(list2,i,col,size);
  }
  return cal;
}

double selectPos(List* list,int row,int cols,int size){
  List* pointer = list;
  Node* pointer2;
  int zero;
  int i=0;
  int j=0;
  for(i=0;i<size;i++){
    if(pointer->row == row){
      zero = 1;
      i=size;
    }else{
      if(pointer->row > row){
        zero = 0;
      }else{
        pointer= pointer->next;
      }
    }
  }
  pointer2= pointer->listNode->header;

  if(zero == 1){
    for(i=0;i<size;i++){
      if(pointer2->col == cols){
        return pointer2->num;
      }else{
        if(pointer2->col >= cols){
          i=size;
        }else{
          if(pointer2->next){
            pointer2= pointer2->next;
          }else{
            i=size;
          }
        }
      }
    }
  }else{
  }
  return 0;
}

List* multiCal(List* list1,List* list2,int size){
  List* lN = createList();
  ListNode* listNode;
  Node* node;
  double num;
  int i,j;
  for(i=0;i<size;i++){
    listNode = createListNode();
    for(j=0;j<size;j++){
      num = calculate(list1,list2,i,j,size);
      if (num != 0){
        node= createNode(j,num);
        insertNode(listNode,node);
      }
    }

    if(listNode->header){
      insertList(lN,listNode,i);
      listNode = NULL;
    }
    listNode = NULL;

  }

  return lN;

}

List* calPow(List* list,int pow,int size){
  int i=0;
  List* lN = createList();
  lN = list;
  for(i=0;i<pow-1;i++){
    lN = multiCal(list,lN,size);
  }
  return lN;
}

void deleteListNode(ListNode* listNode){
  int next=0;
  ListNode* pointerListNode = listNode;
  Node* pointerTrash;

  while(next==0){
    if(pointerListNode->header->next){
      pointerTrash = pointerListNode->header;
      pointerListNode->header=pointerListNode->header->next;
      free(pointerTrash);
    }else{
      next=1;
      pointerTrash = listNode->footer;

      free(pointerTrash);
    }
  }
  free(listNode);
}

void deleteList(List* list){
  int next=0;
  List* pointer = list;
  List* pointerTrash;

  while(next==0){
    if(pointer->next){
      pointerTrash = list;
      pointer=pointer->next;
      deleteListNode(pointerTrash->listNode);
      free(pointerTrash);
    }else{
      next=1;
      deleteListNode(pointerTrash->listNode);
      free(pointer);
    }
  }
  free(list);
}

int sizeList(List* list){
  List* pointer = list;
  ListNode* pointerListNode;
  int sizeNode= sizeof(Node);
  int sizeListNode = sizeof(ListNode);
  int sizeList = 0;
  int count = 0;

  // printf("%d",pointer->row);
  while(pointer->next != NULL){
    pointerListNode=pointer->listNode;
    count=pointerListNode->size;
    // printf("columnas count %d\n",count);
    sizeList = sizeList + count * sizeNode + sizeListNode;
    // printf("tamaño de la fila %d\n",sizeList);
    pointer= pointer->next;
  }
    pointerListNode=pointer->listNode;
    count=pointerListNode->size;
    // printf("columnas count %d\n",count);
    sizeList = sizeList + count * sizeNode + sizeListNode;
    return sizeList;
}

void printListNode(ListNode* listNode,int size){
  Node* pointerNode = listNode->header; 
  int next2 = 0;
  int j=0;

  while(next2==0){
    if(pointerNode->next){
      if(pointerNode->col==j){
        printf(" %0.lf",pointerNode->num);
        pointerNode = pointerNode->next;
        j++;
      }else{
        printf(" %0.lf",0.0);
        j++;
      }
    }else{
      if(pointerNode->col==j){
        printf(" %0.lf",pointerNode->num);
        j++;
        if(j>=size){
          next2=1;
        }
      }else{
        printf(" %0.lf",0.0);
        j++;
        if(j>=size){
          next2=1;
        }
      }
    }
  }
}

void printListComplete(List* list, int size){
  int i,j;
  int next,next2;
  List* pointer;
  ListNode* pointer2;
  Node* pointerNode;
  pointer = list;
  i=0;
  next=0;
  while(next==0){
    j=0;
    next2=0;
    // printf("%d",pointer->row);
    if(pointer->next){
      if(pointer->row==i){
        // printf("panda");
        printListNode(pointer->listNode,size);
        pointer=pointer->next;
        i++;
      }else{
        for(j=0;j<size;j++){
          printf(" %lf",0.0);
          i++;
          pointer=pointer->next;
        }
      }
    }else{
      printListNode(pointer->listNode,size);
      next=1;
    }
    printf("\n");
  }

}


int main(){
  int size = readSize();
  int pow = readPow(); 
  welcome();
  List* l1 = readFile();
  List* lR = calPow(l1,pow,size);
  printListComplete(lR,size);
  printf("El espacio de la matriz dispersa, usando la estrutura de listas es: %d\n",sizeList(lR));
  printf("El espacio de la matriz habria sido la siguiente: %d \n",size*size*8);
  return 0;
}
