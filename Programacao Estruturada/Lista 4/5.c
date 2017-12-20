#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define tam 3

typedef struct
{
  float p1;
  float p2;
  float p3;
  int matricula;
  char nome[256];
}alunos;

void preencher(alunos dados[]);
void imprimir(alunos dados[],int k,char busca[]);

int main ()
{
  int k=0;
  char busca[256];
  srand(time(NULL));
  alunos dados[tam];
  preencher(dados);
  printf("ALuno para ser buscado: ");
  scanf(" %s",busca);
  imprimir(dados,k,busca);
  return 0;
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
void imprimir(alunos dados[],int k,char busca[])
{
  int i;
  for(i=0;i<tam;i++)
  {
    if(strcmp(dados[i].nome,busca)==0)
    {
      printf("matricula:%d\n",dados[i].matricula);
      printf("notas:%.2f %.2f %.2f \n",dados[i].p1,dados[i].p2,dados[i].p3);
    }
  }
}
