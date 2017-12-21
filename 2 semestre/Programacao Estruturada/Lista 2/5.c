#include <stdio.h>

#define linha 3
#define coluna 4

void preencher(float matrizA[linha][coluna],float matrizB[linha][coluna])
{
  printf("Insira os valores para a matrizA:");
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
    scanf("%f", &matrizA[i][j]);
    }
  }
  printf("Insira os valores para a matrizB:");
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
    scanf("%f", &matrizB[i][j]);
    }
  }
}
void subtracao(float matrizA[linha][coluna],float matrizB[linha][coluna],float matrizC[linha][coluna])
  {
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
    matrizC[i][j]=matrizA[i][j]-matrizB[i][j];
    }
  }
}
void imprimir(float matrizC[linha][coluna]) {
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      printf("%.1f\t",matrizC[i][j]);
    }
    printf("\n");
  }
}

int main() {
  float matrizA [linha][coluna];
  float matrizB [linha][coluna];
  float matrizC [linha][coluna];
  preencher(matrizA,matrizB);
  subtracao (matrizA,matrizB,matrizC);
  imprimir(matrizC);
  return 0;
}
