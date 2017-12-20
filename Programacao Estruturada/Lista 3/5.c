#include <stdio.h>
#include <stdlib.h>





int main ()
{
  FILE *input;
  FILE *output;

  float km[4];
  char nome[4][256];
  int i;
  float consumo=0,valorL=0,preco[4]={0},litros[4]={0};
  printf("Insira o consumo do seu carro em km/L\nInsira o valor do litro do combustivel  ");
  scanf("%f %f",&consumo,&valorL);
  input = fopen("5Distancia.txt","r");
  if(input==NULL)
  {
    printf("Erro na abertura do arquivo");
    return 0;
  }
  else
  {
    for (i=0;i<4;i++)
    {
      fscanf(input," %s %f",&nome[i],&km[i]);
      litros[i]=km[i]/consumo;
      preco[i]=litros[i]*valorL;
    }

    fclose(input);
    output=fopen("5Gastos.txt","w");
    fprintf(output,"Cidade\t\tLitros\tPreco\n");
    for(i=0;i<4;i++)
    {
      fprintf(output,"%s \t%.2f \tR$:%.2f \n",nome[i],litros[i],preco[i]);
    }
    fclose(output);
    system("Gastos.txt");
    return 0;
  }
}
