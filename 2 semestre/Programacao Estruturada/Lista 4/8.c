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
}
void imprimir(int vetor[])
{
  int i;
  printf("\nVetor antes da ordenacao\n");
  for(i=0;i<tam;i++)
  {
    printf("%d\n",vetor[i]);
  }
  ordenar(vetor);
  printf("\nVetor ordenado\n");
  for(i=0;i<tam;i++)
    printf("%d\n",vetor[i]);
}

void preencher(int vetor[])
{
  int i;
  for(i=0;i<tam;i++)
  {
    vetor[i]=rand()%1000+1;
  }
}

void ordenar(int vetor[])
{
  int i,j,menor,aux;
  for(i=0;i<tam-1;i++)
  {
    menor=i;
    for(j=i+1;j<tam;j++)
    {
      if(vetor[j]<vetor[menor])
      {
        menor=j;
      }
    }
    if(vetor[menor]!=vetor[i])
    {
      aux=vetor[i];
      vetor[i]=vetor[menor];
      vetor[menor]=aux;
    }
  }
}
