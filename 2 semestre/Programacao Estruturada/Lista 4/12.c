#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 15

void preencher(int vetor[]);
void imprimir(int vetor[]);
void gerar(int vetor[]);

int main()
{
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
