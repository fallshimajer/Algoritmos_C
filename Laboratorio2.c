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
