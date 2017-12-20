#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 2

typedef struct
{
  float p1;
  float p2;
  float p3;
  int matricula;
  char nome[256];
}alunos;

void preencher(alunos dados[]);
void imprimir(alunos dados[],int k);

int main ()
{
  int k=0;
  srand(time(NULL));
  alunos dados[tam];
  preencher(dados);
  imprimir(dados,k);
}


void preencher(alunos dados[])
{
  int i;
  for(i=0;i<tam;i++)
  {
    printf("Insira o nome do aluno:");
    scanf(" %s",&dados[i].nome);
    dados[i].matricula = rand()%1000+1;
    printf("Insira as notas da P1 e da P2:");
    scanf("%f %f",&dados[i].p1,&dados[i].p2);
    dados[i].p3=(dados[i].p1+dados[i].p2)/2;
  }
}
void imprimir(alunos dados[],int k)
{
  int i;
  for(i=0;i<tam;i++)
  {
    if(dados[i].p3>=6)
    {
      k++;
    }
  }
  printf("\n\nALunos aprovados: %d",k);
}
