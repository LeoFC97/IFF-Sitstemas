#include <stdio.h>

#define linha 2
#define coluna 3

void preencher(float matriz[linha][coluna])
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
int verificar(float matriz[linha][coluna],int contador ) {
  int i,j;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      if(matriz[i][j]>20)
      {
        contador++;
      }
    }
  }
  return contador;
}

int main() {
  float matriz [linha][coluna];
  int contador=0;
  preencher(matriz);
  printf("Existem %d numeros maiores do que 20\n",verificar(matriz,contador));
  return 0;
}
