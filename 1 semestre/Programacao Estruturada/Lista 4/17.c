#include <stdio.h>
#include <stdlib.h>


int calcular(int r,int a,int b,int resultado);

int main()
{
  int r=100;
  int a,b,resultado=1;
  printf("Programa para calcular o valor de A elevado B");
  printf("\nInsira A:\n");
  scanf("%d",&a);
  printf("\nInsira B\n");
  scanf("%d",&b);
  printf("\nResultado: %d\n",calcular(r,a,b,resultado));

}
int calcular(int r,int a,int b,int resultado) //calcular =8
{
  int i;
  if(b>=1)
  {
   calcular(r,a,b-1,resultado*a);
 }
 
  return resultado;

}
