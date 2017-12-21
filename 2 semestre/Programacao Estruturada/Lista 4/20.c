#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 20
#define range 40+1

void gerar(int vetor[]);
int checar(int vetor[],int maior,int k);

int main ()
{
  int maior=0;
  int vetor[tam];
  gerar(vetor);
  int k=0;
  printf("O maior numero foi :%d\n",checar(vetor,maior,k));
  return 0;
}
int checar(int vetor[],int maior,int k)
{
  if(vetor[k]>=maior)
  {
  return  checar(vetor,vetor[k],k+1);

  }
  if (k==tam-1)
    return maior;
  return checar(vetor,maior,k+1);
}

void gerar(int vetor[])
{
  srand(time(NULL));
  int i;
  for(i=0;i<tam;i++)
  {
    vetor[i]=rand()%range;
    printf("%d\n",vetor[i]);
  }
}
