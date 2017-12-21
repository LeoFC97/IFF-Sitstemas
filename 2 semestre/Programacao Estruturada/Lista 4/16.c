#include <stdio.h>
#include <stdlib.h>


int fatorial(int n,int resultado,int r);

int main()
{
  int numero;
  printf("Insira um numero >=0\n");
  scanf("%d",&numero );
  int resultado = numero;
  int r=numero-1;
  int k=0;
  if(numero<0)
    printf("Numero invalido\n");
  else
  {
    k=fatorial(numero,resultado,r);
    printf("A fatorial foi:%d",k);
  }

  return 0;
}

int fatorial(int n,int resultado,int r)
{
  if((n==0)||(n==1))
    return 1;
  if(r>=1)
  {
    resultado=resultado*r;
    r--;
    return fatorial(n,resultado,r);
    printf("\na\n");

  }
  else
    return resultado;
}
