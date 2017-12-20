#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define linha 5
#define coluna 5
#define range 40 + 1

void gerar(int matriz[linha][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      matriz[i][j] = rand() % range ;
    }
  }
}
int soma(int matriz[linha][coluna])
{
  int soma=0;
  int i,j;
  for(i=0;i<linha;i++)
  {
    for(j=0;j<coluna;j++)
    {
      if(j>i)
        soma = soma+matriz[i][j];
    }
  }
  return soma;
}
int main()
{
  srand(time(NULL));
  int matriz [linha][coluna];
  gerar(matriz);
  printf("resultado da soma: %d\n",soma(matriz));


  return 0;
}
