#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define linha 3
#define coluna 3
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
void vetoriar(int matriz[linha][coluna],int vetor[])
{
  int k=0;
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      k=j;
      if (j==0)
        vetor[k]= vetor[k]+matriz[i][j];
      if (j==1)
        vetor[k]= vetor[k]+matriz[i][j];
      if (j==2)
        vetor[k]= vetor[k]+matriz[i][j];
    }
  }
  for (k=0;k<linha;k++)
    printf("Valor do vetor:%d\n",vetor[k]);
}
int main ()
{
  srand(time(NULL));
  int matriz [linha][coluna];
  int vetor[3]={0};
  gerar(matriz);
  imprimir(matriz);
  vetoriar(matriz,vetor);

  return 0;
}
