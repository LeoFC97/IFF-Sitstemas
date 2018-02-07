#include <stdio.h>
#include <stdlib.h>


/*
124. A partir do exercício anterior, incremente o valor de n usando apenas o ponteiro ptrn.
Imprima o novo valor de n para confirmar se está correto.
*/
int main ()
{
  int n=0,m=0;
  int *p1,*p2;
  p1=&n;
  p2=&m;
  while(*p1<5)
  {
    (*p1)++;
  }
  while(*p2<5)
  {
    (*p2)++;
  }
  if(*p1>*p2)
  {
    printf("Valor de N:%d\n",*p1);
  }
  if(*p1<*p2)
  {
    printf("Valor de M:%d\n",*p2);
  }
  if(*p1==*p2)
  {
    printf("Ambas variaveis tem o mesmo valor\n");
  }
  return 0;
}
