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

double selectPos(List* list,int row,int cols);

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
        node->previous = listNode->footer;// se agrega anterior
        listNode->footer= node;
        listNode->size++;
        printf("else\n");
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
        printf("num : %lf\n",num);

        if (num != 0){
          node= createNode(j,num);
          insertNode(listNode,node);

        }
        // printf("El valor de size : %d\n",listNode->size);
      }

      printf("el valor de row enviado es %d\n",i);
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
  }else{
    printf("Hay un error al cargar el archivo, al obtener el pow");
  }
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

void deleteList(List* list){
  
}

// void printList(List* list){
//   int count;
//   List* pointer = list;
//   Node* pointer2;
//
//   do {
//       pointer2 = pointer->listNode->header;
//       do{
//         printf("%0.lf ",pointer2->num);
//         pointer2= pointer2->next;
//         printf("hola2");
//         if(count == 1){
//           count++;
//         }else{
//           if(pointer2->next == NULL){
//             count=1;
//           }
//         }
//       }while(count!=2);
//       count=0;
//       printf("\n");
//       pointer = pointer->next;
//       printf("hola");
//   }while(pointer->next);
//
//
// }

double calculate(List* list1, List* list2, int row,int col,int size){
  int i;
  double cal = 0;
  for(i=0;i<size;i++){
    cal = cal + selectPos(list1,row,i) * selectPos(list2,i,col);
  }
  return cal;
}

double selectPos(List* list,int row,int cols){
  List* pointer = list;
  Node* pointer2;
  Node* pointer3;
  int zero;
  int size=readSize();
  int i=0;
  int j=0;
  // for(i=0;i<row;i++){
  //   pointer= pointer->next;
  //   pointer2 = pointer->listNode->header;
  //   for(j=0;j<size;j++){
  //     printf("%lf ",pointer2->num);
  //     pointer2= pointer2->next;
  //   }
  // }
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
    // printf("Existe esa fila\n");
    for(i=0;i<size;i++){
      // printf("columna %d \n",pointer2->col);
      if(pointer2->col == cols){
        // printf("existe esa columna");
        return pointer2->num;
      }else{
        if(pointer2->col >= cols){
          // printf("Se exede el valor de la columna");
          i=size;
        }else{
          if(pointer2->next){
            // printf("No existe esa columan");
            pointer2= pointer2->next;
          }else{
            // printf("ERROR: NO HAY MAS NODOS EN ESTA LISTA: ERROR 300");
            i=size;
          }
        }
      }
    }
  }else{
    // printf("No existe esa fila\n");
  }


  // printf("finalizando");
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
      printf(" %lf",num);
      if (num != 0){
        node= createNode(j,num);
        insertNode(listNode,node);
      }
    }

    printf("el valor de row enviado es %d\n",i);
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
    printList(lN);
  }
  return lN;
}



int main(){
  int size= readSize();
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
  // printf("%d\n",l1->listNode->size);
  // printf("%.0lf\n",l1->next->next->next->listNode->header->num);

  printList(l1);
  printf("FInal\n");
  // double cal = selectPos(l1,2,0);
  // printf("finalizo");
  // printf("Imprimir cal:%lf",cal);
  // cal = calculate(l1,l1,2,2,size);
  // printf("\n\n imprimir cal:%lf\n\n",cal);
  // List* lN = multiCal(l1,l1,3);
  // printList(lN);
  List* lN2 = calPow(l1,3,3);
  printList(lN2);
  // printf("El valor es %d",ln1->size);
  // printf("EL valor de la ultima posicion es: %lf",ln1->footer);
  return 0;
}
