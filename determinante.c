#include <stdio.h>
#include <stdlib.h>
// double determinante(int **matriz,int position, int size);
double determinante(int** matriz,int size);

int **  reducirMatriz(int** matriz,int position,int size){
  int i,j;
  int **matrizReducida;
  matrizReducida = (int **)malloc ((size-1)*sizeof(int *));
  for (i=0;i<(size-1);i++)
  {
    matrizReducida[i] = (int*) malloc ((size-1)*sizeof(int));
  }
  for(i=0;i<size;i++){
    for(j=1;j<size;j++){
      if(i<position){
        matrizReducida[i][j-1]=matriz[i][j];
      }else{
        if(i>position){
          matrizReducida[i-1][j-1]=matriz[i][j];
        }
      }
    }
  }

  return matrizReducida;

}

// double determinante(int **matriz,int position, int size){
//   double det;
//   if(size==2){
//     return matriz[0][0] * matriz[1][1] - matriz[1][0] * matriz[0][1];
//   }else{
//     if(position<0){
//       return 0;
//     }else{
//
//       if(position%2==0){
//         det=matriz[position][0];
//       }else{
//         det=matriz[position][0] * -1;
//       }
//     }
//   }
//
//
//   return det * determinante(reducirMatriz(matriz,position,size),size-2,size-1) + determinante(matriz,position-1,size);
// }

double determinante(int **matriz, int size){
  int i;
  double det;
  printf("iniciando");
  printf("tamaño matriz %d\n",size);
  if(size==2){
    return matriz[0][0] * matriz[1][1] - matriz[1][0] * matriz[0][1];
  }else{
    printf("hacemos esto otro\n");

    for(i=size-1;i>0;i--){
      printf("o esto\n");
      det=det + matriz[0][1] * determinante(reducirMatriz(matriz,i,size),size-1);
      printf("det es: %d",det);
    }
  }
}

int main(){
  int i,j;
  int **matriz;
  int n=5;
  int det;
  matriz = (int **)malloc (n*sizeof(int *));
  for (i=0;i<n;i++)
  {
    matriz[i] = (int*) malloc (n*sizeof(int));
  }
<<<<<<< HEAD
  // for(i=0;i<n;i++){
  //   for(j=0;j<n;j++){
  //     matriz[i][j]=j+1+(i*n);
  //     printf("%d ",matriz[i][j]);
  //   }
  //   printf("\n");
  // }
  matriz[0][0]=-14;
  matriz[0][1]=-29;
  matriz[0][2]=72;
  matriz[0][3]=84;
  matriz[0][4]=19;
  matriz[1][0]=79;
  matriz[1][1]=-11;
  matriz[1][2]=-44;
  matriz[1][3]=19;
  matriz[1][4]=59;
  matriz[2][0]=20;
  matriz[2][1]=-49;
  matriz[2][2]=94;
  matriz[2][3]=38;
  matriz[2][4]=-1;
  matriz[3][0]=51;
  matriz[3][1]=-36;
  matriz[3][2]=98;
  matriz[3][3]=1;
  matriz[3][4]=-98;
  matriz[4][0]=-53;
  matriz[4][1]=-44;
  matriz[4][2]=21;
  matriz[4][3]=65;
  matriz[4][4]=22;
  det=determinante(matriz,n);
  printf("El determinante es %d",det);
  return 0;
=======
  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
      matriz[i][j]=j+1+(i*10);
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }
  det=determinante(matriz,9,10);
  printf("%d ",det);
>>>>>>> 25df477b776afeb9573abf3624c982391c256584
}
