#include <stdio.h>
#include <stdlib.h>

void preencherA(int vetorA[])
{
    int vetorB[50], vetorC[50];
    int i;
    srand(time(NULL));
    for(i=0;i<50;i++)
    {
        vetorA[i]=rand()%100+1;
        printf("Numero: %d\n Posicao: %d\n",vetorA[i],i);
    }

    preencherBC(vetorA,vetorB,vetorC);

}
void preencherBC(int vetorA[],int vetorB[],int vetorC[])
{
    printf("\NENTROU NO PREENCHER\n");
    int contadorPar=0,contadorImpar=0;
    int i;
    int k=0;
    int j=0;
    for(i=0;i<50;i++) //PREENCHER OS VETORES B,C
    {
        if ((vetorA[i]%2==0) && (vetorA[i]!=0))
        {
            vetorB[j] = vetorA[i];
            contadorPar++;
            j++;
        }
        if(vetorA[i]%2!=0)
        {
            vetorC[k] = vetorA[i];
            contadorImpar++;
            k++;
        }
    }
    printf("Contadores:\nPar: %d\nImpar:% d\n",contadorPar,contadorImpar);
    imprimirBC(vetorB,vetorC,contadorPar,contadorImpar);
}
void imprimirBC(int vetorB[],int vetorC[],int contadorPar,int contadorImpar)
{
    //B = PAR
    //C = IMPAR
    int  i;
    int j=0;
    int k=0;
    printf("***Vetor B****\n");
    for(i=0;i<contadorPar;i++)
    {
        printf("%d\n",vetorB[j]);
        j++;
    }
    printf("****Vetor C****\n");
    for(i=0;i<contadorImpar;i++)
    {
        printf("%d\n",vetorC[k]);
        k++;
    }
}

int main()
{
    int vetorA[50];
    preencherA(vetorA);

    return 0;
}
