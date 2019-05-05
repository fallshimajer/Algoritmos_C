#include <stdlib.h>
#include <stdio.h>

double** readFile();
double** array2d(int n);
int max();
double**  reducirMatriz(double** matriz,int position,int size);
double cleanMemory(double** matriz,int size);
// double**  reducirMatriz(double** matriz,int size);

double** readFile(){
  FILE* file = fopen("datos.in","rt");
  int count,i ,j;
  if(file == NULL){
    printf("El Archivo cargado es incorrecto.\n");
  }
  else{
    printf("El Archivo fue cargado con exito.\n");
    fscanf(file,"%d",&count);
    double** matriz=array2d(count);
    for(i=0;i<count;i++){
      for(j=0;j<count;j++){
        fscanf(file,"%lf",&matriz[i][j]);
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

double** array2d(int n){
  double **matriz;
  int i;

  matriz = (double **)malloc (n*sizeof(double *));

  for (i=0;i<n;i++)
  {
    matriz[i] = (double *) malloc (n*sizeof(double));
  }

  return matriz;
}

void mostrarMatriz(double** matriz,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%.0lf ",matriz[i][j]);
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

double**  reducirMatriz(double** matriz,int position,int size){
  int i,j;
  double **matrizReducida;
  matrizReducida = (double **)malloc ((size-1)*sizeof(double *));
  if (matrizReducida == NULL)
	{
		printf("No hay suficiente espacio en memoria");
	}
  for (i=0;i<(size-1);i++)
  {
    matrizReducida[i] = (double*) malloc ((size-1)*sizeof(double));
    if (matrizReducida[i] == NULL)
  	{
  		printf("No hay suficiente espacio en memoria");
  	}
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

// double determinante(double **matriz,int position, int size){
//   double det;
//   if(size==2){
//     return matriz[0][0] * matriz[1][1] - matriz[1][0] * matriz[0][1];
//   }else{
//     if(position<0){
//       return 0;
//     }else{
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

double cleanMemory(double** matriz,int size){
  int i;
  for(i=0;i<size;i++)
  {
    free(matriz[i]);
  }
  free(matriz);
  return 1;
}

double determinante(double** matriz,int size){
  double det=0;
  // double** reducida;
  int i;
  if(size==2){
    return (matriz[0][0] * matriz[1][1] - matriz[1][0] * matriz[0][1])*cleanMemory(matriz,size);

  }else{
    for(i=size-1;i>=0;i--){
      // reducida=reducirMatriz(matriz,i,size);
      if(i%2==0){
        det=det + matriz[i][0] * determinante(reducirMatriz(matriz,i,size),size-1);
      }else{
        det=det + -1 * matriz[i][0] * determinante(reducirMatriz(matriz,i,size),size-1);
      }
    }
    cleanMemory(matriz,size);
    return det;
  }
}

// determinante(reducirMatriz(matriz,i,size),size-1)

int main() {
  int maximo=max();
  int i,j;
  double det;
  double ** matriz = readFile();
  mostrarMatriz(matriz,maximo);
  // det=determinante(matriz,maximo-1,maximo);
  det=determinante(matriz,maximo);
  printf("%lf ",det);
  return 0;
}
