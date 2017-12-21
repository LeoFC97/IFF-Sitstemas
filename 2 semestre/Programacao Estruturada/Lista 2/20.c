
//PASSAR O VALOR PARA A VARIAVEL  MENOR E MAIOR


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define linha 10
#define coluna 3
#define tam 3
#define range 10

void gerar(int matriz[][coluna],int menor[tam],int maior[tam])
{
  printf("Linha representa aluno\nColuna representa suas provas\n");
  int i,j;
  int k;
  for(i=0;i<linha;i++)
  {
    for (j=0;j<coluna;j++)
    {
      matriz[i][j] = rand() % range ;
      printf("%d\t",matriz[i][j]);
    }
    printf("\n");
  }
}
void maior_menor(int matriz[][coluna],int menor[tam],int maior[tam])
{
  int i,j;
  for (j=0;j<coluna;j++)
  {
    for (i=0;i<linha;i++)
    {
      if (matriz[i][j]<=menor[j])
        menor[j]=matriz[i][j];
      if (matriz[i][j]>=maior[j])
        maior[j]=matriz[i][j];
    }
    printf("\n");
    printf("Valor da maior nota na coluna %d:\t %d\n",j,maior[j]);
    printf("Valor da menor nota na coluna %d:\t %d\n",j,menor[j]);
  }
}
int main ()
{
  srand(time(NULL));
  int menor[tam]={11},maior[tam]={-1};
  int matriz [linha][coluna] = {0};
  gerar(matriz, menor,maior);
  maior_menor(matriz,menor,maior);

  return 0;
}
