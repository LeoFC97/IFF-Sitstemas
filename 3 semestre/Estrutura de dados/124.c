#include <stdio.h>
#include <stdlib.h>


/*
124. A partir do exercício anterior, incremente o valor de n usando apenas o ponteiro ptrn.
Imprima o novo valor de n para confirmar se está correto.
*/
int main ()
{
  int n;
  int *prt;
  prt=&n;
  n=10;
  (*prt)++;
  printf("Valor de N: %d\n",*prt);
  printf("Endereco de N: %p\n",&n);
  printf("Endereco de prt:%p\n",&prt);
  return 0;
}
