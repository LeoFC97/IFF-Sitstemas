#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define linha 4
#define coluna 4
#define range 10 + 1

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
int soma_diagonal_secundaria(int matriz[linha][coluna])
{
  int soma=0;
  int i,j;
  for(i=0;i<linha;i++)
  {
    for(j=0;j<coluna;j++)
    {
      if(i==coluna-1-j)
        soma = soma+matriz[i][j];
    }
  }
  return soma;
}
void imprimir(int matriz[linha][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      printf("%d\t",matriz[i][j]);
    }
    printf("\n");
  }
}
int main ()
{
  srand(time(NULL));
  int matriz [linha][coluna];
  gerar(matriz);
  imprimir(matriz);
  printf("resultado da soma da diagonal secundaria foi: %d\n",soma_diagonal_secundaria(matriz));

  return 0;
}
