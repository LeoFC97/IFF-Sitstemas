#include <stdio.h>
#include <stdlib.h>
void preecher(int vet[])
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("Insira um valor:");
        scanf("%d",&vet[i]);
    }
}
int verificar(int vet[])
{
    int ultimoValor=vet[0],i;
    printf("Ultimo VALOR: %d\n",ultimoValor);
    for(i=1;i<5;i++)
    {
        if  (vet[i]>ultimoValor)
        {
            ultimoValor = vet[i];
        }
        else
        {
            return 0;
            break;
        }
    }
    return 1;
}
int main()
{
    int resultado;
    int vet[25];
    preecher(vet);
    resultado = verificar(vet);
    if(resultado==1)
    {
        printf("O vetor esta em ordem crescente.");
    }
    else
    {
        printf("O vetor nao esta em ordem crescente.");
    }
    return 0;
}
