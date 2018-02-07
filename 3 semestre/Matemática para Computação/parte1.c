#include <stdio.h>
#include <stdlib.h>

#define linha 5
#define coluna 5



void printar(int matriz[][coluna]);

  /*prototipos*/
int somatorioA(int matriz[][coluna]);
int somatorioB(int matriz[][coluna]);
int somatorioC(int matriz[][coluna]);
int somatorioD(int matriz[][coluna]);
int somatorioE(int matriz[][coluna]);
int somatorioF(int matriz[][coluna]);
int somatorioG(int matriz[][coluna]);
  /*prototipos*/

int main ()
{
  int matriz[linha][coluna] = {0,2,8,1,7,1,5,8,2,2,3,4,0,8,1,9,1,2,7,2,3,0,1,0,4};
  printar(matriz);
  int opcao;
  do
  {
    printf("(1)A\n(2)B\n(3)C\n(4)D\n(5)E\n(6)F\n(7)G\n(99)SAIR\n");
    scanf("%d",&opcao);
    switch(opcao)
  	{
  			case 1:
  			   printf("Somatorio A: %d\n\n\n\n",somatorioA(matriz));
  			break;
  			case 2:
  			   printf("Somatorio B: %d\n\n\n\n",somatorioB(matriz));
  			break;
  			case 3:
  			   printf("Somatorio C: %d\n\n\n\n",somatorioC(matriz));
  			break;
  			case 4:
  			   printf("Somatorio D: %d\n\n\n\n",somatorioD(matriz));
  			break;
  			case 5:
  			   printf("Somatorio E: %d\n\n\n\n",somatorioE(matriz));
  			break;
		    case 6:
  			   printf("Somatorio F: %d\n\n\n\n",somatorioF(matriz));
  			break;
  			case 7:
  			   printf("Somatorio G: %d\n\n\n\n",somatorioG(matriz));
  			break;
  			case 99:
  			   exit(1);
  			break;
  			default:
      	   printf("Opcao Invalida\n\n");
  	}
  }while(opcao!=99);
}
int somatorioG(int matriz[][coluna])
{
	int soma=0,i,j;
	for(i=0;i<linha;i++)
	{
		for(j=i+1;j<coluna;j++)
		{
			soma +=(matriz[i][j]*matriz[j][i]);
		}
	}
	return soma;
}
int somatorioF(int matriz[][coluna])
{
	int soma=0,i,j;
	for(i=0;i<linha;i++)
	{
		for(j=0;j<i;j++)
		{
			soma +=matriz[i][j];
		}
	}
	return soma;
}
int somatorioE(int matriz[][coluna])
{
  int i,j,soma=0;
  for(i=0;i<linha;i++)
  {
    for(j=i+1;j<coluna;j++)
    {
      soma+=matriz[i][j];
    }
  }
  return soma;
}
int somatorioD(int matriz[][coluna])
{
  int i,j,soma=0;
  for(i=0;i<linha;i++)
  {
    for(j=0;j<coluna;j++)
    {
      if(i==j)
      {
        soma+=matriz[j][i];
      }
    }
  }
  return soma;
}
int somatorioC(int matriz[][coluna])
{
  int i,j,soma=0;
  for(i=0;i<linha;i++)
  {
    for(j=0;j<coluna;j++)
    {
      if(i!=j)
      {
        soma+=matriz[i][j];
      }
    }
  }
  return soma;
}
int somatorioB(int matriz[][coluna])
{
  int i,j,soma=0;
  for(j=0;j<linha;i++)
  {
    for(i=0;j<coluna;i++)
    {
      soma+=matriz[i][j];
    }
  }
  return soma;
}
int somatorioA(int matriz[][coluna])
{
  int i,j,soma=0;
  for(i=0;i<linha;i++)
  {
    for(j=0;j<coluna;j++)
    {
      soma+=matriz[i][j];
    }
  }
  return soma;
}
void printar(int matriz[][coluna])
{
  int i,j;
  for(i=0;i<linha;i++)
  {
    for(j=0;j<coluna;j++)
    {
      printf("%d  ",matriz[i][j]);
    }
    printf("\n");
  }
}
