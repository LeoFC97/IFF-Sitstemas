#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencher(int vetor[])
{
 int i;
 srand(time(NULL));
 for(i=0;i<20;i++)
 {
    vetor[i]=rand()%49;
    printf("Numero: %d\n Posicao: %d\n",vetor[i],i);
 }
}
void verificar(int vetor[])
{
    int i,contadorPar=0,contadorImpar=0;
    for(i=0;i<20;i++)
    {
        if ((vetor[i]%2==0) && (vetor[i]!=0))
        {
            contadorPar++;
        }
        if(vetor[i]%2!=0)
        {
            contadorImpar++;
        }
    }
    printf("A quantidade de pares foi: %d\n",contadorPar);
    printf("A quantidade de impares foi: %d",contadorImpar);
}
int main( ){
 int vetor[20];
 preencher(vetor);
 verificar(vetor);

 return 0;
 }
