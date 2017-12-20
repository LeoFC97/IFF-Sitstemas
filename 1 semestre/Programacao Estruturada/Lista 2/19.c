#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define linha 4
#define coluna 4
#define range 30 + 1

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
  int soma=0,i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      if((i!=j) &&(i!=coluna-1-j))
        soma = soma + matriz[i][j];
    }
  }
  return soma;
}
int main ()
{
  srand(time(NULL));
  int matriz [linha][coluna];
  gerar(matriz);
  imprimir(matriz);
  printf("resultado da soma da coluna digitada  foi: %d\n",soma(matriz));

  return 0;
}
