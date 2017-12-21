#include <stdlib.h>
#include <stdio.h>

#define linha 10
#define coluna 10

void gerar(int matriz[linha][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      if(i<j)
        matriz[i][j]=(2*i)+(7*j)+2;
      if(i==j)
        matriz[i][j]=(3*(i*i))-1;
      if(i>j)
        matriz[i][j]=(4*(i*i*i))-(5*(j*j))+1;
    }
  }
}
void imprimir(int matriz[linha][coluna]) {
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
int main()
{
  int matriz [linha][coluna];
  gerar(matriz);
  imprimir(matriz);

  return 0;
}
