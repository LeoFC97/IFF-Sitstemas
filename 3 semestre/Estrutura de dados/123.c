#include <stdio.h>
#include <stdlib.h>

 /*
 123. Declare uma variável inteira n e um ponteiro ptrn para essa variável. Atribua um
 valor para n. A seguir, imprima o valor de n a partir de ptrn. Imprima também o endereço de
 n e de ptrn.
 */
int main ()
{
  int n;
  int *prt;
  prt=&n;

  n=10;
  printf("Valor de N: %d\n",*prt);
  printf("Endereco de N: %p\n",&n);
  printf("Endereco de prt:%p\n",&prt);
  return 0;
}
