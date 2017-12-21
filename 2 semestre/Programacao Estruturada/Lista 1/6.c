#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher_verificar(int vetor[])
{
     //printf("COMECOU A PREENCHER \n");
     int i;
     int f;
     int j;
     //for (f=0;f<1000000000/6  ;f++); //TESTEI VARIAS VEZES E ESSA � A QUANTIDADE DE A�OES QUE O MEU PC REALIZA EM 1 SEGUNDO
     /*
     Tem que ajustar o valor desse for de cima para ele demorar 1 segundo para ser realizado.
     A fundao srand gera uma semente aleatoria para ser feito os numeros aleatorios. Mas essa semente s� muda a cada 1 segundo,
     entao se chamar ela sem o intervalo de 60 segundos nao vai mudar o valor dos numeros.
     */
     //srand(time(NULL)); //TEM QUE ESPERAR 1 SEGUNDO PARA A SEMENTE ALEATORIA SER DIFERENTE
     for(i=0;i<10;i++)
     {
        vetor[i] = rand() %11+1;
     }
     for (i=0;i<10;i++)
     {
        for (j=0;j<10;j++)
        {
            if ((vetor[i] == vetor[j]) && (i!=j)) //conferir se nao tem numero repetido
            {

                printf("Entrou no IF de numeros iguais.\n");
                printf("Valor do vetor  %d na posicao %d\n",vetor[i],i);
                printf("Valor do vetor  %d na posicao %d\n",vetor[j],j);
                preencher_verificar(vetor); //GERAR NOVO VETOR
            }

        }
    }
}
void imprimir (int vetor[])
{
    int i;
    printf("O vetor nao tem numeros repetidos.\n");
    for (i=0;i<10;i++)
    {
        printf("VALOR: %d\n",vetor[i]);
    }
}
int main()
{
    int vetor[10];
    preencher_verificar(vetor);
    imprimir(vetor);
    return 0;
}
