#include <stdio.h>

#define linha 4
#define coluna 3

void preencher(float matriz[4][3])
{
  printf("Insira os valores para a matriz:");
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
    scanf("%f", &matriz[i][j]);
    }
  }
}
void imprimir(float matriz[4][3]) {
  printf("\n");
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna; j++)
    {
      printf("%.1f\t",matriz[i][j]);
    }
    printf("\n");
  }
}

int main() {
  float matriz [4][3];
  preencher(matriz);
  imprimir (matriz);
  return 0;
}
