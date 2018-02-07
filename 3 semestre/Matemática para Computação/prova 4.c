#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int diagonalmenteDominante(int matriz[][2]);
void preencher(int matriz[][2]);
void printar(int matriz[][2]);

int main ()
{
  int matriz[2][2];
  preencher(matriz);
  printar(matriz);
  if(diagonalmenteDominante(matriz))
    printf("Essa matriz e diagonalmente dominante\n");
  else
    printf("Essa matriz nao e diagonalmente dominante\n");
  return 0;
}
void preencher(int matriz[][2])
{
  srand(time(NULL));
  int i,j;
  for(i=0;i<2;i++)
  {
    for(j=0;j<2;j++)
    {
      matriz[i][j]=rand() % 10+1;
    }
  }
}
void printar(int matriz[][2])
{
  int i,j;
  for(i=0;i<2;i++)
  {
    for(j=0;j<2;j++)
    {
      printf("%d\t",matriz[i][j]);
    }
    printf("\n");
  }
}

int diagonalmenteDominante(int matriz[][2])
{
  int i,j,somaNaoDiagonal=0;
  for(i=0;i<2;i++)
  {
    somaNaoDiagonal=0;
    for(j=0;j<2;j++)
    {
      if(i!=j)
      {
        somaNaoDiagonal+=abs(matriz[i][j]);
      }
      if(matriz[i][i]<somaNaoDiagonal)
      {
        return 0;
      }
    }
  }
  return 1;
}
