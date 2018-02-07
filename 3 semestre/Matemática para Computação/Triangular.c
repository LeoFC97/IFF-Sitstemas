#include<stdio.h>
#include<stdlib.h>

#define TAM 3

void calcular(int matriz[TAM][TAM],float x[TAM],int b[TAM]);
void imprimir(int matriz[TAM][TAM],int b[TAM]);

int main(){
  int matriz[TAM][TAM]={2,0,0,1,4,0,1,1,1};
  float x[TAM]={0,0,0};
  int b[TAM]={2,-3,1};
  int i;
  imprimir(matriz,b);
  calcular(matriz,x,b);
  for(i=0;i<TAM;i++)
  printf("\nX%d = %.4f\n",i,x[i]);
}

void calcular(int matriz[TAM][TAM],float x[TAM],int b[TAM]){
  float soma=0;
  for(int i=0;i<TAM;i++){
    for(int j=0;j<i;j++){
      soma+=(matriz[i][j]*x[j]);
    }
    x[i]=(b[i]-(soma))/matriz[i][i];
    soma=0;
  }
}

void imprimir(int matriz[TAM][TAM],int b[TAM]){
  printf("\n\n->MATRIZ TRIANGULAR INFERIOR<-\n\n");
  for(int i=0;i<TAM;i++){
    for(int j=0;j<TAM;j++){
      printf("%4d",matriz[i][j]);
    }
    printf(" = %d \n",b[i]);
  }
}
