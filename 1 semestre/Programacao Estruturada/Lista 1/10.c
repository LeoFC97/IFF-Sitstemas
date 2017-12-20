#include <stdio.h>
#include <stdlib.h>

void preencherAB(int A[],int B[])
{
     int i;
     for(i=0;i<15;i++)
     {
         printf("Insira um valor para a posicao %d do vetor A:",i);
         scanf("%d",&A[i]);
         printf("Insira um valor para a posicao %d do vetor B:",i);
         scanf("%d",&B[i]);
     }
}
void preencherC(int A[],int B[],int C[])
{
     int i;
     for(i=0;i<15;i++)
     {
         C[i]= (2*A[i]+B[i]);
     }
}
void imprimirC(int C[])
{
    int i;
    for(i=0;i<15;i++)
    {
         printf("Posicao no vetor C %d. Valor:",i,C[i]);
    }
}
int main()
{
    int A[15];
    int B[15];
    int C[15];
    preencherAB(A,B);
    preencherC(A,B,C);
    imprimirC(C);
    return 0;
}
