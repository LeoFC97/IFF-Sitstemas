#include <stdio.h>
#include <stdlib.h>

/*
129. O que aconteceria se você incrementasse os valores dos parâmetros, dentro da
função? Quais seriam seus valores dentro da função? E fora dela? Teste e explique por quê.
*/

void maior(int *ptr1,int *ptr2);
int main ()
{
  int m=0,n=10;
  printf("Insira valor para M:");
  scanf("%d",&m);
  printf("\n");
  printf("Insira valor para N");
  scanf("%d",&n);
  maior(&m,&n);
  printf("Valor de M depois da funcao:%d\nValor de N depois da funcao:%d",m,n);
}


void maior(int *ptr1,int *ptr2)
{
  (*ptr1)++;
  (*ptr2)++;
	printf("\n\nValor de M na funcao:%d\nValor de N da funcao:%d\n\n\n\n",*ptr1,*ptr2);
}
