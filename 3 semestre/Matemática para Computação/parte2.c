#include <stdio.h>
#include <stdlib.h>

#define tam 5

int questaoH(int matrizA[][tam], int x);
void questaoI(int matrizA[][tam],int *vetor);
void questaoJ(int matrizA[][tam],int *vetor);




int main ()
{
  int matriz[tam][tam]={0,2,8,1,7,1,5,8,2,2,3,4,0,8,1,9,1,2,7,2,3,0,1,0,4};
  int x;
  int vetor[tam];
  int vetor2[tam];
  int opcao;
  do
  {
    printf("(1)H\n(2)I\n(3)J");
    scanf("%d",&opcao);
    switch(opcao)
    {
        case 1:
            printf("Insira valor de X: ");
            scanf("%d",&x);
            printf("Questao H: %d\n\n\n\n",questaoH(matriz,x));
            break;
       case 2:
            questaoI(matriz,vetor);
            break;
       case 3:
            questaoJ(matriz,vetor2);
            break;
        case 99:
            exit(1);
        break;
        default:
            printf("Opcao Invalida\n\n");
    }
  }while(opcao!=99);
  return 0;
}

void questaoJ(int matriz[][tam],int *vetor)
{
  int i,j,x,soma=1;
  for(j=0;j<tam;j++)
  {
    vetor[j]=0;
    for(i=0;i<tam;i++)
    {
      soma=soma*matriz[i][j];
    }
    vetor[j]=soma;
    soma=1;
  }
  printf("Vetor P:\n");
  for(i=0;i<tam;i++)
  {
    printf("%d\t",vetor[i]);
  }
  printf("\n");
}

void questaoI(int matriz[][tam],int *vetor)
{
  int i,j,x,soma=0;
  for(i=0;i<tam;i++)
  {
    vetor[i]=0;
    for(j=0;j<tam;j++)
    {
      soma+=matriz[i][j];
    }
    vetor[i]=soma;
    soma=0;
  }
  printf("Vetor V:\n");
  for(i=0;i<tam;i++)
  {
    printf("%d\t",vetor[i]);
  }
  printf("\n");
}

int questaoH(int matriz[][tam], int x)
{
    int i,j,soma=0;
  for(i=0;i<tam;i++)
  {
    for(j=0;j<tam;j++)
    {
      soma+=matriz[i][j]*x;
    }
  }
  return soma;
}
