#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define linha 7
#define coluna 3

#define linhaT 3
#define colunaT 7

void gerar(int matrizA[linha][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      matrizA[i][j] = rand() % 25+1;
      printf("%d\t",matrizA[i][j]);
    }
    printf("\n");
  }
}
void calcular(int matrizA[linha][coluna],int matrizB[linha][coluna])
{
  int i,j,auxiliar;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      matrizB[i][j]=matrizA[i][j];
    }
  }
}
void imprimir(int matrizB[linha][coluna])
{
int i,j;
  printf("Matriz transposta:\n");
  for(i=0;i<linhaT;i++)
  {
    for (j=0;j<colunaT;j++)
    {
      printf("%d\t",matrizB[j][i]);
    }
    printf("\n");
  }
}
int main() {
  srand(time(NULL));
  int matrizA [linha][coluna];
  int matrizB [linha][coluna];
  gerar(matrizA);
  calcular(matrizA,matrizB);
  imprimir(matrizA);
  return 0;
}
