#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define tam 3

int norma_coluna(int matriz[][tam]);
int norma_linha(int matriz[][tam]);
float NormaEuclideana (int matriz[][tam]);

int main ()
{
  int matriz[tam][tam]={3,2,5,1,1,2,4,3,-2};
  int i,j;
  printf("Norma Coluna:\t%d\n",norma_coluna(matriz));
  printf("Norma Linha:\t%d\n",norma_linha(matriz));
  printf("Norma Euclideana:\t%.2f\n",NormaEuclideana(matriz));
  return 0;
}

int norma_coluna(int matriz[][tam])
{
  int soma=0,maior=0;
  int i=0,j=0;
  for(j=0;j<tam;j++)
  {
    for(i=0;i<tam;i++)
    {
      soma+=abs(matriz[i][j]);
    }
    if(soma>=maior)
    {
      maior=soma;
    }
    soma=0;
  }
  return maior;
}



int norma_linha (int matriz[][tam])
{
	int i,j,maior=0,soma=0;
	for(i=0;i<tam;i++)
	{
		for(j=0;j<tam;j++)
		{
			soma+=abs(matriz[i][j]);
		}
		if(soma>maior)
		{
			maior = soma;
		}
		soma = 0;
	}
	return maior;
}

float NormaEuclideana (int matriz[][tam])
{
	int i,j,soma=0;
	float normaE=0;
	for(i=0;i<tam;i++)
	{
		for(j=0;j<tam;j++)
		{
			soma = soma+(pow(matriz[i][j],2));
		}

	}
	normaE=(sqrt(soma));
	return normaE;

}
