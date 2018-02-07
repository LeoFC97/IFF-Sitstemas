#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define tam 6

void preencher(int matriz[][tam]);
void printar(int matriz[][tam]);
int questao5(int matrizA[][tam],int matrizB[][tam]);


int main ()
{
  int matrizA[tam][tam],matrizB[tam][tam];
  preencher(matrizA);
  printar(matrizA);
  printf("\n---Matriz B---\n");
  preencher(matrizB);
  printar(matrizB);
  if(questao5(matrizA,matrizB))
    printf("As matrizes satisfazem a propriededade\n");
  else
    printf("As matrizes nao satisfazem a propriededade\n");
  return 0;
}
void preencher(int matriz[][tam])
{
  srand(time(NULL));
  int i,j;
  for(i=0;i<tam;i++)
  {
    for(j=0;j<tam;j++)
    {
      matriz[i][j]=rand() % 10+1;
    }
  }
}

void printar(int matriz[][tam])
{
  int i,j;
  for(i=0;i<tam;i++)
  {
    for(j=0;j<tam;j++)
    {
      printf("%d\t",matriz[i][j]);
    }
    printf("\n");
  }
}

int questao5(int matrizA[][tam],int matrizB[][tam])
{ //somatorio
  int i,j,soma[tam-1]={0};
  for(j=0;j<tam;j++)
  {
    for(i=0;i<tam;i++)
    {
      if(i>j)
      {
        soma[j]+=abs(matrizA[i][j]);
      }
    }
  }
  int k;
  int menor=soma[0];
  for(k=0;k<tam-1;k++)
  {
    if(soma[k]<menor)
    {
      menor=soma[k];
    }
  }
  //produtorio
  int produto[tam-1]={1};
  for(i=0;i<tam;i++)
  {
    for(j=0;j<tam;j++)
    {
      if(i<j)
      {
        produto[i]=produto[i]*matrizB[i][j];
      }
    }
  }
  int maior=produto[0];
  for(k=0;k<tam-1;k++)
  {
    if(produto[k]>maior)
    {
      maior=produto[k];
    }
  }
   //comparar os resultados
   if(menor>=maior)
   {
     return 1;
   }
   return 0;
}
