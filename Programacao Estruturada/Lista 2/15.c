#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define linha 10
#define coluna 4
#define range 15 + 1

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
int soma_coluna_x(int matriz[linha][coluna],int x)
{
  int soma=0;
  int i,j;
  for(i=0;i<linha;i++)
  {
    for(j=0;j<coluna;j++)
    {
      if(j+1==x)
        soma = soma+matriz[i][j];
    }
  }
  return soma;
}
int main()
{
  srand(time(NULL));
  int x;
  printf("Insira a coluna para ser somada\n");
  scanf("%d",&x);
  int matriz [linha][coluna];
  gerar(matriz);
  printf("resultado da soma da coluna digitada  foi: %d\n",soma_coluna_x(matriz,x));


  return 0;
}
