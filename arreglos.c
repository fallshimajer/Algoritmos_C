#include <stdio.h>
// #include <math.h>

void orden_maximo_arreglo(){

  int arreglo[10] = {0,1,2,3,12,5,6,7,8,9};
  int arregloMaximo[10];
  int valorMaximo=0;
  int maximo=10;
  int i,j, posicion;
  for(i=0;i<10;i++){

    for(j=0;j<10;j++){

      if(arreglo[j]>valorMaximo){
        // printf("El valor maximo %d \n",arreglo[j]);
        // printf("El valor J %d y de i %d \n",arreglo[j],j,i);
        valorMaximo=arreglo[j];
        arregloMaximo[i]=valorMaximo;
        posicion=j;
      }else{
        arregloMaximo[i]=valorMaximo;
      }
    }
    valorMaximo=0;
    // printf("posicion: %d\n",posicion);
    arreglo[posicion]=0;
  }
  // for(i=0;i<maximo;i++){
  //   printf("El valor de arreglo en %d es :%d \n",i,arreglo[i]);
  // }

  printf("La matriz ordena del valor maximo es:\n");

  for(i=0;i<maximo;i++){
    printf("%d ",arregloMaximo[i]);
  }

  printf("\n");
}

void invertir_arreglo(){
  int arreglo[10] = {0,1,2,3,12,5,6,7,8,9};
  int maximo = 10;
  int aux,i;

    for(i=0;i<maximo/2;i++){
        aux=arreglo[i];
        arreglo[i]=arreglo[maximo-i-1];
        arreglo[maximo-i-1]=aux;
    }

    printf("El valor de la matriz invertida es: \n");

    for(i=0;i<maximo;i++){
        printf("%d ",arreglo[i]);
    }

}

int main(){

  orden_maximo_arreglo();
  invertir_arreglo();

}