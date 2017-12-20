#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define linha 6
#define coluna 6

void gerar(int matrizA[][coluna],int matrizB[][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      matrizB[i][j] = rand() % 10+1;
      matrizA[i][j] = rand() % 10+1;
    }
  }
}
void multi (int matrizA[][coluna],int matrizB[][coluna],int matrizC[][coluna])
{
  int i,j,k;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      for (k=0;k<coluna;k++)
      {
        matrizC[i][j]= matrizC[i][j] + (matrizA[i][k]*matrizB[k][j]);
      }
    }
  }
}
int verificar_indentidade(int matrizC[][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      if ((matrizC[i][j]!=0) && (i!=j))
      {
        return 0;
      }
    }
  }
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      if ((i==j) && (matrizC[i][j]!=1))
      {
         return 0;
      }
    }
  }
  return 1;
}
int main(){
  srand(time(NULL));
  int matrizA [linha][coluna];
  int matrizB [linha][coluna];
  int matrizC [linha][coluna] = {0};
  gerar(matrizA,matrizB);
  multi(matrizA,matrizB,matrizC);
  if (verificar_indentidade(matrizC)==1)
    printf("A matriz B e inversa de A\n");
  else
    printf("A matriz B NAO e inversa de A\n");
  return 0;
}
