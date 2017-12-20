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
int multiplicacao(int matriz[linha][coluna])
{
  int soma=1;
  int i,j;
  for(i=0;i<linha;i++)
  {
    for(j=0;j<coluna;j++)
    {
      if(j<i)
        soma = soma*matriz[i][j];
    }
  }
  return soma;
}
int main()
{
  srand(time(NULL));
  int matriz [linha][coluna];
  gerar(matriz);
  printf("resultado da multiplicacao foi: %d\n",multiplicacao(matriz));


  return 0;
}
