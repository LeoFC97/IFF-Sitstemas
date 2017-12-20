#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define linha 10
#define coluna 10
#define range 50 + 1

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
int minmax(int matriz[linha][coluna])
{
  int i,j;
  int l_maior =0;
  int maior_ultimo = 0;
  int mini=999;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      if (matriz[i][j] >= maior_ultimo)
      {
        maior_ultimo = matriz[i][j];
        l_maior=i;
      }
    }
  }
  for(j=0;j<coluna;j++)
  {
    if(matriz[l_maior][j]<mini)
      mini = matriz[l_maior][j];
  }

  return mini;
}

int main ()
{
  srand(time(NULL));
  int matriz[linha][coluna];
  gerar(matriz);
  printf("O elemento minmax foi: %d\n",minmax(matriz));
}
