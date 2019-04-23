#include <stdlib.h>
#include <stdio.h>

int** readFile();
int** array2d(int n);
int max();

int** readFile(){
  FILE* file = fopen("datos.in","rt");
  int count,i ,j;
  if(file == NULL){
    printf("El Archivo cargado es incorrecto.\n");
  }
  else{
    printf("El Archivo fue cargado con exito.\n");
    fscanf(file,"%d",&count);
    int** matriz=array2d(count);
    for(i=0;i<count;i++){
      for(j=0;j<count;j++){
        fscanf(file,"%d",&matriz[i][j]);
      }
    }
    return matriz;
  }
}

int max(){
  int count;
  FILE* file = fopen("datos.in","rt");
  if(file == NULL){
    printf("El Archivo cargado es incorrecto.\n");
  }
  else{
    fscanf(file,"%d",&count);
  }
  return count;
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

// int sizeMatriz(int ** matriz){
//   int count,i,j;
//   while(matriz[i][j]=!"\0"){
//     count++;
//     j++;
//   }
//   return count;
// }

int determinante(int ** matriz,int max){
  int i,j,k,x,det,count,count2;

    det=1;
    for (j=0;j<max;j++)
    {
      count=0;
      for(i=0+j;i<max-1;i++){
        if(count==0){
          det=det*matriz[i][j];
          printf("%d n",det);
          count++;
          count2=0+j;
        }
          printf("por aqui");
          x=(matriz[i+1][j] * -1)/matriz[count2][j];
          printf("%d r",x);
          for(k=0+j;k<max;k++){
            matriz[i+1][k+j]=matriz[i+1][k+j]+matriz[count2][k+j]*x;
            printf("%d o",matriz[i+1][k+j]);
        }
      }
    }

  return det;
}

int main() {
  int maximo=max();
  int i,j;
  int ** matriz = readFile();
  for(i=0;i<maximo;i++){
    for(j=0;j<maximo;j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("%d ",determinante(matriz,maximo));
  return 0;
}
