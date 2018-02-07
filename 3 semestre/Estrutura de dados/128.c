#include <stdio.h>
#include <stdlib.h>

/*
128. Descubra (e imprima) o valor da maior variável do exercício anterior, através da
função maior, cujos parâmetros devem ser as variáveis ponteiros para m e n.
*/

void maior(int *ptr1,int *ptr2);
int main ()
{
  int m=0,n=0;
  int resultado;
  maior(&m,&n);
}


void maior(int *ptr1,int *ptr2)
{
  int maior = 0;
	if(*ptr1>*ptr2)
		maior = *ptr1;
	else
		maior = *ptr2;

	printf("\n Maior.: %d", maior);

}
