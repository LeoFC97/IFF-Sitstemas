#include <stdio.h>
#include <stdlib.h>

int main ()
{
  FILE *output;
  FILE *input;
  int i;
  float n1[6],n2[6],n3[6],media[6]={0};
  input=fopen("2Notas.txt","r");
  for(i=0;i<6;i++)
  {
    fscanf (input,"%f",&n1[i]);
    fscanf (input,"%f",&n2[i]);
    fscanf (input,"%f",&n3[i]);
    media[i]=(n1[i]+n2[i]+n3[i])/3;
  }
  fclose(input);
  output = fopen("2Situacao.txt","w");
  for (i=0;i<6;i++)
  {
    if(media[i]>=5)
      fprintf(output,"%.2f   A\n",media[i]);
    else
      fprintf(output,"%.2f   R\n",media[i]);
  }
  fclose(output);
  return 0;
}
