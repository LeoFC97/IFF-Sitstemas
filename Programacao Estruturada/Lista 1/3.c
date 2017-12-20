#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencher(int vetor[])
{
 int i;
 srand(time(NULL));
 for(i=0; i < 40; i++)
 {
    vetor[i] = rand( ) % 100 + 1;
    printf("Numero: %d\n Posicao: %d\n",vetor[i],i);
 }
}
void verificar(int vetor[])
{
    int i;
    int contador=0;
    int vetAux[40];
    int x;
    printf("Insira um numero para fazer a verificacao");
    scanf("%d",&x);
    for(i=0; i < 40; i++)
    {
        if(vetor[i]==x)
        {
            vetAux[contador]=i;
            contador++;
        }
    }z
    if  (contador!=0)
    {
        int contador2;
        printf("O numero escolhido apareceu %d x no vetor.",contador);
        for(contador2=0;contador2<contador;contador2++)
        {
            printf("\nApareceu na posicao: %d",vetAux[contador2]);

        }
    }
    if  (contador==0)
    {
      printf("O numero nao aparece  no vetor");
    }
}
int main( ){
 int vetor[40];
 preencher(vetor);
 verificar(vetor);

 return 0;
 }
