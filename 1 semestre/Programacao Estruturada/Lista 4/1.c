#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 20

typedef struct
{
  int codigo;
  char nome[256];
  float saldo;
  int flag;
} conta_bancaria;

    //prototipo das funcoes//
void preencher(conta_bancaria dados[]);
int verificar(float saldo,int i);
    //prototipo das funcoes//

int main()
{
  srand(time(NULL));
  conta_bancaria dados[tam];
  preencher(dados);
  int j;
  for(j=0;j<tam;j++)
  {
    if(dados[j].flag==1)
      printf("\nClientes que tem mais de R$1000 na conta %s",dados[j].nome);
  }
  return 0;
}

void preencher(conta_bancaria dados [])
{
  int i;
  int resultado;
  for(i=0;i<tam;i++)
  {
    printf("Insira o primeiro nome do cliente");
    scanf(" %s",&dados[i].nome);
    printf("Insira o saldo:");
    scanf("%f",&dados[i].saldo);
    dados[i].codigo = rand()%1000+1;
    resultado=verificar(dados[i].saldo,i);
    if(resultado==1)
      dados[i].flag=1;
    else
      dados[i].flag=0;
  }
}
int verificar(float saldo,int i)
{
  if(saldo>1000)
    return 1;
  return 0;
}
