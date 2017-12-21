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
    int maior=0;
    for (i=0;i<15;i++)
    {
        if (vetor[i]>=maior)
        {
            maior=vetor[i];
            contador = i;
        }
    }
    printf("O maior numero do vetor foi: %d \nA posicao dele foi: %d",maior,contador);
}
int main()
{
    int vetor[15];
    preencher(vetor);
    return 0;
}
