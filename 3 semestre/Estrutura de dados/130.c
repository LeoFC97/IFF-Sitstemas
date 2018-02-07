#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
130. Implemente uma função que receba como parâmetro um vetor v de n números
inteiros e retorne um novo vetor w, alocado dinamicamente, cujos elementos são definidos
pelas fórmulas:
w[0] = v[0]
w[i] = v[i] + w[i] − 1 , 0 < i < n
Essa função não deve alterar o conteúdo do vetor original v e seu protótipo deve ser:
int* somatorios (int n, int* v);

*/

int* somatorios(int n,int* v);
void printar(int *vetor,int fim);
void preencher(int *vetor,int tam);
int main()
{
  srand(time(NULL));
  int tamanho,*v,*w;
  printf("Informe o tamanho do vetor: ");
  scanf("%d",&tamanho);
  v=(int *) malloc(tamanho*sizeof(int));
  preencher(v,tamanho);
  printar(v,tamanho);
  w=somatorios(tamanho,v);
  //printar(w,tamanho);
  free(w);
  free(v);

}
int* somatorios(int n,int *v)
{
  int i=0,*w;
  w=(int *) malloc(n*sizeof(int));
  w[0]=v[0];
  for(i=1;i<n;i++)
  {
    w[i]=v[i]+w[i-1];
  }
  printf("----------------\n");
  for(i=0;i<n;i++)
    printf("%d\n",w[i]);
  return w;
}
void preencher(int *vetor,int tam)
{
  int i=0;
  while(i<tam)
  {
    vetor[i]=rand()%100+1;
    i++;
  }
}

void printar(int *vetor,int fim)
{
  int i=0;
  while(i<fim)
    {
      printf("%d\n",vetor[i]);
      i++;
  }
}
