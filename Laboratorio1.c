#include <stdlib.h>
#include <stdio.h>

int** readFile();
int** array2d(int n);
int max();
int**  reducirMatriz(int** matriz,int position,int size);
// int**  reducirMatriz(int** matriz,int size);

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

void mostrarMatriz(int** matriz,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }
}

// int determinante(int ** matriz,int max){
//   int i,j,k,x,det,count,count2;
//
//     det=1;
//     for (j=0;j<max;j++)
//     {
//       count=0;
//       for(i=0+j;i<max-1;i++){
//         if(count==0){
//           det=det*matriz[i][j];
//           printf("%d n",det);
//           count++;
//           count2=0+j;
//         }
//           printf("por aqui");
//           x=(matriz[i+1][j] * -1)/matriz[count2][j];
//           printf("%d r",x);
//           for(k=0+j;k<max;k++){
//             matriz[i+1][k+j]=matriz[i+1][k+j]+matriz[count2][k+j]*x;
//             printf("%d o",matriz[i+1][k+j]);
//         }
//       }
//     }
//
//   return det;
// }

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

  return matrizReducida;

}

double determinante(int **matriz,int position, int size){
  double det;
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
        printf("%lf :",det);
      }else{
        det=matriz[position][0] * -1;
        printf("%lf :",det);
      }
    }
  }


  return det * determinante(reducirMatriz(matriz,position,size),size-2,size-1) + determinante(matriz,position-1,size);
}

// double determinante(int** matriz,int size){
//   double det=0;
//   int i;
//   printf("hola");
//   if(size==2){
//     printf("calcular en 2 %d \n",matriz[0][0] * matriz[1][1] - matriz[1][0] * matriz[0][1]);
//     return matriz[0][0] * matriz[1][1] - matriz[1][0] * matriz[0][1];
//
//   }else{
//     for(i=size-1;i>=0;i--){
//       printf("primer paso\n");
//       printf("i : %d\n",i);
//       printf("A : %d\n",matriz[i][0]);
//       if(i%2==0){
//         det=det + matriz[i][0] * determinante(reducirMatriz(matriz,i,size),size-1);
//       }else{
//         det=det + -1 * matriz[i][0] * determinante(reducirMatriz(matriz,i,size),size-1);
//       }
//       printf("det : %lf\n",det);
//     }
//     return det;
//   }
// }

// determinante(reducirMatriz(matriz,i,size),size-1)

int main() {
  int maximo=max();
  int i,j;
  double det;
  int ** matriz = readFile();
  mostrarMatriz(matriz,maximo);
  det=determinante(matriz,maximo-1,maximo);
  printf("%lf ",det);
  return 0;
}
