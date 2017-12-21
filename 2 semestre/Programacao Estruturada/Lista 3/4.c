#include <stdio.h>
#include <stdlib.h>

#define linha 4
#define coluna 4

FILE *input;
FILE *output;

      /*prototipo das funcoes*/
void transposta(int matriz[][coluna]);
      /*prototipo das funcoes*/
void transposta(int matriz[][coluna])
{
  int i,j;
  while(!feof(input))
  {
    for(i=0;i<linha;i++)
    {
      for(j=0;j<coluna;j++)
      {
        fscanf(input,"%d",&matriz[j][i]);
      }
    }
  }
}
int main ()
{
  int i,matriz[linha][coluna],j;
  input=fopen("4Matriz4x4.txt","r");
  if(input==NULL)
  {
    printf("Erro na abertura do arquivo");
    return 0;
  }
  transposta(matriz);
  fclose(input);
  output = fopen("4Transposta.txt","w");
  for (i=0;i<linha;i++)
  {
    for(j=0;j<coluna;j++)
    {
      fprintf(output,"%d  ",matriz[i][j]);
    }
    fprintf(output,"\n");
  }
  fclose(output);
  system("4Transposta.txt");
  return 0;
}
