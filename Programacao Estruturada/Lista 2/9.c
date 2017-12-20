  #include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define linha 2
#define coluna 2

void gerar(int matrizA[linha][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      matrizA[i][j] = rand() % 19;
    }
  }
}
int verificar(int matrizA[linha][coluna])
{
  int contador=0;
  int contador2=0;
  int resultado=0;
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      if ((matrizA[i][j]==0) && (i!=j))
      {
       contador=1;
      }
    }
  }
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      if ((i==j) && (matrizA[i][j]==1))
      {
       contador2=1;
      }
    }
  }
  resultado=contador2+contador;
  return resultado;
}
int main() {
  srand(time(NULL));
  int matrizA [linha][coluna];
  gerar(matrizA);
  if (verificar(matrizA)==2)
    printf("A matriz e indentidade\n");
  else
    printf("A matriz NAO e indentidade\n");
  return 0;
}
