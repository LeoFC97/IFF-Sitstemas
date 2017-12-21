#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define linha 8
#define coluna 8
#define range 14

void gerar(int matriz[linha][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      matriz[i][j] = rand() % range;
    }
  }
}
int verificar(int matriz[linha][coluna])
{
  int contador1=0;
  int i,j;
  for(i=0;i<linha;i++)
  {
    for(j=0;j<coluna;j++)
    {
      if((j>i) && (matriz[i][j]==0))
        contador1=1;
      else
        contador1=0;
    }
  }
  return contador1;
}
int main()
{
  srand(time(NULL));
  int matriz [linha][coluna];
  gerar(matriz);
  int resultado = verificar(matriz);
  if(resultado==1)
    printf("A matriz e triangular inferior\n");
  else
    printf("A matriz nao e triangular inferior\n");

  return 0;
}
