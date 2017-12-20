#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 5
#define range 50+1

int calcular(int i, int resultado,int vetor[]);
void preencher(int vetor[]);

int main ()
{
  srand(time(NULL));
  int vetor[20];
  preencher(vetor);
  int resultado=0;
  int k;
  int i=0;
  printf("Valor da soma do vetor: %d",calcular(i,resultado,vetor));
}


int calcular(int i, int resultado,int vetor[])
{
  if (i<tam)
  {
    printf("\nValor do i: %d\n",i);
    resultado+=vetor[i];
    printf("\nValor do resultado: %d\n",resultado);
    i++;
    calcular(i,resultado,vetor);
  }
  else
    return resultado;
}
void preencher(int vetor[])
{
  int f;
  for(f=0;f<tam;f++)
    vetor[f]=rand()%range;
  int k;
  for(k=0;k<tam;k++)
    printf("%d\n",vetor[k]);
}
