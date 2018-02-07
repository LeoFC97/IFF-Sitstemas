#include<stdio.h>
#include<stdlib.h>

/*
126. Descubra (e imprima) o valor da maior variável do exercício anterior, através da
função maior, cujos parâmetros devem ser m e n.
*/

void maior(int m,int n);

int main(){
    int m,n,*ptrm,*ptrn;
    ptrm=&m;
    ptrn=&n;

    printf("\nDigite o valor de M:");
    scanf("%d",ptrm);
    printf("Digite o valor de N:");
    scanf("\n%d",ptrn);
    maior(m,n);
return 0;
}


void maior(int m,int n){
  if(m==n)
    printf("Os valores são iguais.");
  if(m>n)
    printf("\nO maior valor é: %d",m);
    if(m<n)
      printf("\nO maior valor é: %d",n);
}
