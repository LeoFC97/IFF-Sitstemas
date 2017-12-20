#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 15

void preencher(int vetor[]);
void ordenar(int vetor[]);
void imprimir(int vetor[]);

int main()
{
  srand(time(NULL));
  int vetor[tam];
  preencher(vetor);
  imprimir(vetor);
  ordenar(vetor);
  printf("\nVetor ordenado\n");
  imprimir(vetor);
  return 0;
}


void preencher(int vetor[])
{
  int i;
  for(i=0;i<tam;i++)
    vetor[i]=rand()%1000+1;
}
void imprimir(int vetor[])
{
  int i;
  for(i=0;i<tam;i++)
      printf("%d\n",vetor[i]);
}
void ordenar(int vetor[])
{
  int i,fim=tam,count,aux;
  do
  {
    count=0;
    for(i=0;i<fim-1;i++)
    {
      if(vetor[i]>vetor[i+1])
        {
        aux=vetor[i];
        vetor[i]=vetor[i+1];
        vetor[i+1]=aux;
        count=1;
        }
      }
    fim--;
  }
  while(count!=0);
}
