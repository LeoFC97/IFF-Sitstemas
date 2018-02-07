#include<stdio.h>
#include<stdlib.h>

/*
127. O que aconteceria se você incrementasse os valores dos parâmetros, dentro da
função? Quais seriam seus valores dentro da função? E fora dela? Teste e explique por quê.
*/

void maior(int m,int n);   //prototipo

int main(){
    int m,n,*ptrm,*ptrn;
    ptrm=&m;
    ptrn=&n;
    printf("\nDigite o valor de M:");
    scanf("%d",ptrm);
    printf("\nDigite o valor de N:");
    scanf("\n%d",ptrn);
    maior(m,n);
    printf("\n\n\n"); //pular linhas
    printf("\nValor de M após a função: %d",m);
    printf("\nValor de N após a função: %d",n);
return 0;
}


void maior(int m,int n){
  m++;
  n++;
  printf("\nValor de M dentro da função: %d",m);
  printf("\nValor de N dentro da função: %d",n);
  //os valores sofreram alteração somente na função
}
