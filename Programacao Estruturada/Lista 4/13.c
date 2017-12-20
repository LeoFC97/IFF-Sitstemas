#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define range 30+1
#define tam 20


void ordenar(int vetor[],int inicio,int fim);
int particionar(int vetor[],int inicio,int fim);
void preencher(int vetor[]);
void imprimir(int vetor[]);

int main ()
{
  int vetor[tam];
  srand(time(NULL));
  preencher(vetor);
  ordenar(vetor,0,tam);
  imprimir(vetor);
}

void preencher(int vetor[])
{
  int i;
  for(i=0;i<tam;i++)
    vetor[i]=rand()%range;
}

void imprimir(int vetor[])
{
  int i;
  for(i=0;i<tam;i++)
    printf("%d\n",vetor[i]);
}

void ordenar(int vetor[],int inicio,int fim) //Quick Sort
{
  int pivo;
  if(fim>inicio)
  {
    pivo=particionar(vetor,inicio,fim);
    ordenar(vetor,inicio,pivo-1);
    ordenar(vetor,pivo+1,fim);
  }
}
int particionar(int vetor[],int inicio,int fim)
{
  int k;
  int i,j,pivo,aux;
  pivo=vetor[inicio];
  i=inicio;
  for(j=inicio+1;j<=fim-1;j++)
  {
    if(vetor[j]>pivo)
    {
		  i++;
			aux=vetor[i];
			vetor[i]=vetor[j];
			vetor[j] = aux;
		}
	}
  aux=vetor[i];
	vetor[i]=vetor[inicio];
	vetor[inicio]=aux;
  return i;
}
