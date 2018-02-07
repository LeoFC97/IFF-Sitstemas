#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define TAM 3
int NormaColuna (int mat[TAM][TAM])
{
	int i,j,maior=0,soma=0;
	for(j=0;j<TAM;j++)
	{
		for(i=0;i<TAM;i++)
		{
			soma = soma+(abs(mat[i][j]));
		}
		if(soma>maior)
		{
			maior = soma;
		}
		soma=0;


	}
	return maior;
}

int NormaLinha (int mat[TAM][TAM])
{
	int i,j,maior=0,soma=0;
	for(i=0;i<TAM;i++)
	{
		for(j=0;j<TAM;j++)
		{
			soma = soma+(abs(mat[i][j]));
		}
		if(soma>maior)
		{
			maior = soma;
		}
		soma = 0;
	}
	return maior;
}

float NormaEuclideana (int mat[TAM][TAM])
{
	int i,j,soma=0;
	float normaE=0;
	for(i=0;i<TAM;i++)
	{
		for(j=0;j<TAM;j++)
		{
			soma = soma+(pow(mat[i][j],2));
		}

	}
	normaE=(sqrt(soma));
	return normaE;

}


int main ()
{
	FILE *arq;
	int m[TAM][TAM];
	int i,j;
	arq = fopen("Matriz.txt","r");
	if(arq==NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}
	for(i=0;i<TAM;i++)
	{
		for(j=0;j<TAM;j++)
		{
			fscanf(arq,"%i\t",&m[i][j]);
		}
		fscanf(arq,"\n");
	}
	fclose(arq);
	printf("Norma Coluna:\t%d\n",NormaColuna(m));
	printf("Norma Linha:\t%d\n",NormaLinha(m));
	printf("Norma Euclideana:\t%.2f\n",NormaEuclideana(m));
	return 0;
}
