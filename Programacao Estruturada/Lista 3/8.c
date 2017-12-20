#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
  FILE *input;
  char nome[10][200];
  int poupulacao[10];
  input=fopen("8Cidades.txt","r"); //abre o arquivo como leitura
  fscanf(input,"%s %d",&nome[0],&poupulacao[0]);
  printf("Cidade: %s\thabitantes: %d\n",nome[0],poupulacao[0]);
  int linhas =0;
  int i=1;
  linhas++;
  while (!feof(input))
  {
    fscanf(input,"%s %d",&nome[i],&poupulacao[i]);
    printf("Cidade: %s\thabitantes: %d\n",nome[i],poupulacao[i]);
    linhas++;
  }
  //comparar as varaiveis para saber qual tem o maior valor
  int maior=0;
  char cidade_maior[200];
  for(i=0;i<linhas;i++)
  {
    if(poupulacao[i]>=maior)
    {
      printf("Entrou no iff\n");
      printf("Valor do maior: %d\n",maior );
      maior=poupulacao[i];
      strcpy(cidade_maior,nome[i]);
    }
  }
  printf("Cidade com mais habitantes: %s\n",cidade_maior );
  printf(" habitantes: %d\n",maior);

}
