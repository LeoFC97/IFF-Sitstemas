#include <stdio.h>
#include <stdlib.h>



void preencher(int vet[])
{
    int  i;
    for(i=0;i<30;i++)
    {
        printf("Insira o elemento da posicao %d>>",i);
        scanf("%d",&vet[i]);
    }
}
float conferir(int vet[],int valor)
{
    int i;
    for(i=0;i<30;i++)
    {
        if (vet[i]==valor)
        {
            return valor;
        }
    }
    return -1.5;
}

int main()
{
    int vet[30];
    int resultado;
    preencher(vet);
    int valor;
    printf("Insira um valor para ser conferido no vetor:");
    scanf("%d",&valor);
    resultado= conferir(vet,valor);
    if  (resultado==valor)
    {
     printf("O numero esta no vetor");
    }
    else
    {
        printf("O numero nao esta no vetor");
    }
    return 0;
}
