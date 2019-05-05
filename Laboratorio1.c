#include <stdlib.h>
#include <stdio.h>

double** readFile();
double** array2d(int n);
int max();
double**  reducirMatriz(double** matriz,int position,int size);
double cleanMemory(double** matriz,int size);

//Función para leer el archivo datos.#include "Salida: genera una matriz del archivo datos.in"

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

//Funcion para obtener el tamaño de la matriz, "Salida: valor con el tamaño de tipo int"

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

//Función para crear una matriz de dos dimensiones, "Entrada: entero con el tamaño de la matriz", "Salida: matriz dinamica"

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

//Imprime en pantalla la matriz, "Entrada: matriz,tamaño de matriz"

void mostrarMatriz(double** matriz,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%.0lf ",matriz[i][j]);
    }
    printf("\n");
  }
}

//Reduce en una dimensión, "Entrada: matriz,posición es la fila que no se considera para crear la matriz reducia, size es el tamaño de la matriz original"

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

// limpia la memoria de una matriz, "Entrada: matriz, tamaño de matriz"

double cleanMemory(double** matriz,int size){
  int i;
  for(i=0;i<size;i++)
  {
    free(matriz[i]);
  }
  free(matriz);
  return 1;
}

// Calcula el determinante como el metodo de laPlace, en el retorno obtiene el cofactor y lo multiplica por la función determinante con la matriz reducida
// "Entrada: matriz, tamaño de matriz", "Salida: retorna el calculo del determinante.", no admite
double determinante(double** matriz,int size){
  double det=0;
  int i;
  if(size==2){
    return (matriz[0][0] * matriz[1][1] - matriz[1][0] * matriz[0][1])*cleanMemory(matriz,size);
  }else{
    if(size==1){
      return matriz[0][0]*cleanMemory(matriz,size);
    }else{
      for(i=size-1;i>=0;i--){
        if(i%2==0){
          det=det + matriz[i][0] * determinante(reducirMatriz(matriz,i,size),size-1);
        }else{
          det=det + -1 * matriz[i][0] * determinante(reducirMatriz(matriz,i,size),size-1);
        }
      }

    }
    cleanMemory(matriz,size);
    return det;
  }
}


int main() {
  int maximo=max();
  int i,j;
  double det;
  double ** matriz = readFile();
  mostrarMatriz(matriz,maximo);
  printf("\n");
  det=determinante(matriz,maximo);
  printf("El valor del determinante es: %0.lf",det);
  return 0;
}
