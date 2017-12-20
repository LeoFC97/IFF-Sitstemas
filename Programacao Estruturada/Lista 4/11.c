#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 20
#define range 30+1

void preencher(int vetor[]);
void imprimir(int vetor[]);
void ordenar(int vetor[]);
int main()
{
  srand(time(NULL));
  int vetor[tam];
  preencher(vetor);
  imprimir(vetor);
}
void preencher(int vetor[])
{
  int i;
  for(i=0;i<tam;i++)
    vetor[i]=rand()% range;
}
void imprimir(int vetor[])
{
  int i;
  printf("Antes da ordenacao");
  for(i=0;i<tam;i++)
    printf("%d\n",vetor[i]);
  ordenar(vetor);
  printf("\n---------------------------\n");
  printf("\nDepois da ordenacao\n");
  for(i=0;i<tam;i++)
    printf("%d\n",vetor[i]);
}
void ordenar(int vetor[])
{
  int i,j,aux;
  for(i=1;i<tam;i++)
  {
    aux=vetor[i];
    for(j=i;(j>0)&&(aux>vetor[j-1]);j--)
      vetor[j]=vetor[j-1];
    vetor[j]=aux;
  }
}
