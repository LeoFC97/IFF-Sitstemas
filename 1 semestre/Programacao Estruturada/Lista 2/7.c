#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define linha 6
#define coluna 6

void gerar(int matrizA[linha][coluna],int matrizB[linha][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      matrizA[i][j] = rand() % 50+1;
    }
  }
  for(j=0;j<coluna;j++)
  {
    for (i=0;i<linha;i++)
    {
    matrizB[j][i]=matrizA[i][j];
    }
  }
}
int verificar(int matrizA[linha][coluna],int matrizB[linha][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      if (matrizB[j][i]==matrizA[i][j])
      return 1;
    }
  }
  return 0;
}

int main() {
  srand(time(NULL));
  int k;
  int matrizA [linha][coluna];
  int matrizB [linha][coluna];
  gerar(matrizA,matrizB);
  if (verificar (matrizA,matrizB) ==0)
    printf("A matriz e simetrica\n");
  else
    printf("A matriz nao e simetrica\n");
  return 0;
}
