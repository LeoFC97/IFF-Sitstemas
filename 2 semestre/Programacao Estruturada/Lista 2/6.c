#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define linha 2
#define coluna 8

void gerar(int matrizA[linha][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      matrizA[i][j] = rand() % 29-0;
    }
  }
}
void mult(int matrizA[linha][coluna],int matrizB[linha][coluna],int x)
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
    matrizB[i][j]=matrizA[i][j]*x;
    }
  }
}
void imprimir(int matrizB[linha][coluna]) {
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      printf("%d\t",matrizB[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  int x;
  printf("Insira um numero para multiplicar a matriz aleatoria\n");
  scanf("%d",&x);
  int matrizA [linha][coluna];
  int matrizB [linha][coluna];
  gerar(matrizA);
  mult (matrizA,matrizB,x);
  imprimir(matrizB);
  return 0;
}
