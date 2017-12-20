#include <stdio.h>
#include <stdlib.h>

void preencher (int vetor[])
{
    int i;
    for (i=0;i<15;i++)
    {
        printf("Insira um numero para a posicao%d: ",i);
        scanf("%d",&vetor[i]);
    }
    verificar_imprimir(vetor);
}
void verificar_imprimir (int vetor[])
{
    int i;
    int  contador;
    int menor=999;
    for (i=0;i<15;i++)
    {
        if (vetor[i]<=menor)
        {
            menor=vetor[i];
            contador = i;
        }
    }
    printf("O menor numero do vetor foi: %d \nA posicao dele foi: %d",menor,contador);
}
int main()
{
    int vetor[15];
    preencher(vetor);
    return 0;
}
