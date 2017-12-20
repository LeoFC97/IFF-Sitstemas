#include <stdio.h>

#define linha 4
#define coluna 4

void preencher(int matriz[linha][coluna])
{
  printf("Insira os valores para a matriz:");
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
    scanf("%d", &matriz[i][j]);
    }
  }
}
int verificar(int matriz[linha][coluna],int x) {
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      if(matriz[i][j]==x)
      {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  int matriz [linha][coluna];
  int x;
  printf("Insira o numero para ser verificado:");
  scanf("%d",&x);
  preencher(matriz);
  if (verificar(matriz,x)==1)
     printf("O numero pertence a matriz\n");
  else
    printf("O numero NAO pertence a matriz\n");
  return 0;
}
