#include <stdlib.h>
#include <stdio.h>


void array(int numero){
  int * array = malloc(10 * sizeof(int));

  if (NULL == array) {
    printf("El puntero es nulo");
  }
}


int** array2d(int n){
  int **matriz;
  int i;

  matriz = (int **)malloc (n*sizeof(int *));

  for (i=0;i<n;i++)
  {
    matriz[i] = (int *) malloc (n*sizeof(int));
  }

  return matriz;
}

int** array2dFill(int** matriz,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      matriz[i][j]=i*10+j+1;
    }
  }
  return matriz;
}

void mostrarMatriz(int** matriz,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }

}

int main() {
  int n=10;
  int ** matriz=array2d(n);
  array2dFill(matriz,n);
  mostrarMatriz(matriz,n);
  return 0;
}
