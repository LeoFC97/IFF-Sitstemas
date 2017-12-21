#include <stdio.h>
#include <stdlib.h>

void preecher(int vet[])
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("Insira um valor para a posicao %d:",i);
        scanf("%d",&vet[i]);
    }
}
int checar(int vet[])
{
    int resultado[10];
    int i=0,i2=0;
    int verificador=0;

    for (i=0;i<9;i++)
    {
        resultado[i] = vet[i+1]-vet[i];
        if  ((resultado[i]==resultado[i-1]) && (i2!=0))
        {
            verificador++;
        }
        i2=1;
    }
    return verificador;
}
int main()
{
    int resultado;
    int vet[10];
    preecher(vet);
    resultado = checar(vet);
    if(resultado==8)
    {
        printf("O vetor e uma PA.");
    }
    if  (resultado!=8)
    {
        printf("O vetor nao e uma PA.");
    }

    return 0;
}

