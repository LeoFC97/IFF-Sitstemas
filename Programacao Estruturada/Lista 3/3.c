#include <stdio.h>
#include <stdlib.h>

int main ()
{
  FILE *outputAprovados;
  FILE *outputReprovados;
  FILE *input;
  int i=0;
  char nome[6][256];
  float media[6]={0};
  input=fopen("3Medias.txt","r");
  outputAprovados=fopen("3Aprovados.txt","w");
  outputReprovados=fopen("3Reprovados.txt","w");
  if(input==NULL)
  {
    printf("Erro na abertura do arquivo");
    return 0;
  }
  while (!feof(input))
  {
    fscanf(input," %s %f",&nome[i],&media[i]);
    if(media[i]>=7)
    {
      outputAprovados=fopen("3Aprovados.txt","a");
      fprintf(outputAprovados,"%s %.2f\n",nome[i],media[i]);
      fclose(outputAprovados);
    }
    else
    {
      outputReprovados=fopen("3Reprovados.txt","a");
      fprintf(outputReprovados,"%s %.2f\n",nome[i],media[i]);
      fclose(outputReprovados);
    }
    i++;
  }
  fclose(input);
  return 0;
}
