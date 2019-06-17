#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calPivot(int other, int ppivot);

// float** escalonarArriba(float** matriz,int rows,int cols,int size,int position){
//   int i,j;
//   float pivot;
//   if(rows<position)
//   {
//     for(i=rows;i<size;i++){
//       pivot=calPivot(matriz[rows][cols],matriz[position][cols]);
//       printf("%f hola soy el pivot!!",pivot);
//       for(j=cols;j<size;j++){
//         matriz[i][j]=matriz[position][j]*pivot+matriz[i][j];
//         printf("%d o",matriz[i][j]);
//       }
//       printf("\n");
//
//     }
//
//   }
//   return matriz;
// }

float** escalonarArriba(float ** matriz,int cols, int rows, int size, int position){
  int i,j;
  float pivot,div;

  for(i=cols;i<position;i++){
    div=matriz[position][rows];
    pivot=matriz[i][rows] * -1;
    printf("el pivote es: %f",pivot);
    printf("estoy pasando \n");
    for(j=rows;j<size;j++){
      if(i<cols+1){
        matriz[position][j]=matriz[position][j]/div;
      }

      matriz[i][j]=matriz[position][cols]*pivot+matriz[i][j];

    }
  }

  return matriz;
}

float** escalonarAbajo(float ** matriz,int cols,int rows,int size,int position){
  int i,j;
  float pivot,div;

  for(i=position+1;i<size;i++){
    div=matriz[position][rows];
    pivot=matriz[i][rows] * -1;
    for(j=rows;j<size;j++){
      if(i<position+2){
        matriz[position][j]=matriz[position][j]/div;
      }
      matriz[i][j]=matriz[position][cols]*pivot+matriz[i][j];
    }
  }

  return matriz;
}

<<<<<<< HEAD
float** matrizReduccion(float ** matriz,int cols,int rows, int size){
=======
float** matrizReduccionArriba(float ** matriz,int cols,int rows, int size,int position){
>>>>>>> d480e202f1efa9447b9630a30c5b4830f9db2488
  int i,j;
  if(cols+1==size){
    printf("%f ",matriz[cols][rows]);
  }else {
<<<<<<< HEAD
    for(i=cols;i<size;i++){
=======
    for(i=cols;i<position;i++){
>>>>>>> d480e202f1efa9447b9630a30c5b4830f9db2488
      for(j=rows;j<size;j++){
        printf("%f ",matriz[i][j]);
      }
      printf("\n");
    }
<<<<<<< HEAD
    return matrizReduccion(matriz,cols+1,rows+1,size);
=======
    return matriz;
>>>>>>> d480e202f1efa9447b9630a30c5b4830f9db2488
  }
}


float calPivot(int other, int ppivot){
  printf("%d \n",other);
  printf("%d \n",ppivot);
  float pivot = (float) other / ppivot;
  pivot = pivot * -1;
  printf("%f eres un float",pivot);
  return pivot;
}

int main(){

  float **matriz;
  int n=3;
  matriz = (float **)malloc (n*sizeof(float *));
  int i,j;
  for (i=0;i<n;i++)
  {
    matriz[i] = (float*) malloc (n*sizeof(float));
  }

  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      matriz[i][j]=j+1+(i*3);
      printf("%f ",matriz[i][j]);
    }
    printf("\n");
  }

<<<<<<< HEAD
  matrizReduccion(matriz,0,0,3);
=======
  matrizReduccion(matriz,1,1,3);
>>>>>>> d480e202f1efa9447b9630a30c5b4830f9db2488
  // escalonarArriba(matriz,1,1,3,2);
  // escalonarAbajo(matriz,0,0,3,0);

  // printf("%f \n",calPivot(1,7));
  // float dividir= (float)3 / 5 *-1;
  // printf("%f",dividir);
  // for(i=0;i<3;i++){
  //   for(j=0;j<3;j++){
  //     printf("%f ",matriz[i][j]);
  //   }
  //   printf("\n");
  // }

  return 0;
}
