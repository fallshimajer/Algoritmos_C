#include <stdio.h>
#include <stdlib.h>
int determinante(int **matriz,int position, int size);

int **  reducirMatriz(int** matriz,int position,int size){
  int i,j;
  int **matrizReducida;
  matrizReducida = (int **)malloc ((size-1)*sizeof(int *));
  printf("pasando por aqui!!");
  for (i=0;i<(size-1);i++)
  {
    matrizReducida[i] = (int*) malloc ((size-1)*sizeof(int));
  }
  printf("Aqui!!\n");
  for(i=0;i<size;i++){
    for(j=1;j<size;j++){
      if(i<position){
        matrizReducida[i][j-1]=matriz[i][j];
        printf("%d ",matrizReducida[i][j-1]);
      }else{
        if(i>position){
          matrizReducida[i-1][j-1]=matriz[i][j];
          printf("%d ",matrizReducida[i-1][j-1]);
        }
      }
    }
    printf("\n");
  }

  // for(i=0;i<size;i++){
  //   free(matriz[i]);
  // }
  // free(matriz);

  return matrizReducida;

}

int determinante(int **matriz,int position, int size){
  int det;
  printf(" calculo %d ",position);
  if(size==2){
    return matriz[0][0] * matriz[1][1] - matriz[1][0] * matriz[0][1];
  }else{
    if(position<0){
      printf("ultimo paso\n");
      return 0;
    }else{
      if(position%2==0){
        det=matriz[position][0];
        printf("%d :",det);
      }else{
        det=matriz[position][0] * -1;
        printf("%d :",det);
      }
    }
  }


  return det * determinante(reducirMatriz(matriz,position,size),size-2,size-1) + determinante(matriz,position-1,size);
}

int main(){
  int i,j;
  int **matriz;
  int n=10;
  int det;
  matriz = (int **)malloc (n*sizeof(int *));
  for (i=0;i<n;i++)
  {
    matriz[i] = (int*) malloc (n*sizeof(int));
  }
  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
      matriz[i][j]=j+1+(i*10);
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }
  det=determinante(matriz,9,10);
  printf("%d ",det);
  // matriz=reducirMatriz(matriz,2,3);
  // for(i=0;i<2;i++){
  //   for(j=0;j<2;j++){
  //     printf("%d ",matriz[i][j]);
  //   }
  //   printf("\n");
  // }
}
