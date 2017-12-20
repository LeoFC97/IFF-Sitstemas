#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void retirar_Espacos(char cidade_Destino[]);

int main ()
{
  FILE *input=fopen("7Distancia.txt","r");
  FILE *output = fopen("7Gastos.txt","w");
  char cidade[4][30]={'\0'},aux;
  char cidade_Destino[30]={'\0'};
  float consumo_Litros,distancia[4],gasto,consumo_carro;
  int i;
  float preco;

  printf("Insira a cidade destino:\n");
  scanf(" %[^\n]s",&cidade_Destino);
  printf("Quanto e o consumo do seu carro em KM/L?  ");
  scanf("%f",&consumo_carro);
  printf("Insira o preco do combustivel");
  scanf("%f",&preco);
  retirar_Espacos(cidade_Destino);
  for(i=0;i<4;i++)
  {
    fscanf(input," %s %f",&cidade[i],&distancia[i]);
    printf("\n%s\n",cidade[i]);
  }
  int r=0;
/*  for(i=0;i<4;i++)
  {
    r=strcmp(cidade_Destino,cidade[i]);
    if(r==0)
    {
      consumo_Litros=(distancia/consumo_carro)
      gasto = consumo_Litros*preco;
      fprintf(output,"%s %.2f R$:%.2f",cidade_Destino,consumo_Litros,gasto);
    }
  }*/
  fclose(input);
  fclose(output);
}
void retirar_Espacos(char cidade_Destino[])
{
  int i;
  int x=0;
  for(i=0;i<strlen(cidade_Destino);i++)
  {
    if(cidade_Destino[i]==' ')
    {
      for(x=i;cidade_Destino[x]!='\0';x++)
      {
        cidade_Destino[x]=cidade_Destino[x+1];
      }
    }
  }
}
