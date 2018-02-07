#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamA 4

#define linhaB 4
#define colunaB 3

#define range 10

void preencher(int matrizA[][tamA],int matrizB[][colunaB]);
void printar(int matrizA[][tamA],int matrizB[][colunaB]);
void gerarC(int matrizA[][tamA],int matrizB[][colunaB],int matrizC[][colunaB]);
void printarC(int matrizC[][colunaB]);


int main ()
{
	srand(time(NULL));
	int matrizA[tamA][tamA];
	int matrizB[linhaB][colunaB];
	int matrizC[tamA][colunaB];
	preencher (matrizA,matrizB);
	printar(matrizA,matrizB);
	gerarC(matrizA,matrizB,matrizC);
	printarC(matrizC);
	return 0;
}

void printarC(int matrizC[][colunaB])
{
	printf("\n\nMatrizC\n\n");
	int i,j;
	for(i=0;i<tamA;i++)
	{
		for(j=0;j<colunaB;j++)
		{
			printf("%d  ",matrizC[i][j]);
		}
		printf("\n");
	}
}

void gerarC(int matrizA[][tamA],int matrizB[][colunaB],int matrizC[][colunaB])
{
	int i,j,x,aux=0;
	for(i=0;i<tamA;i++)
	{
		for(j=0;j<colunaB;j++)
		{
			for(x=0;x<tamA;x++)
			{
				aux+=matrizA[i][x]*matrizB[x][j];
			}
      matrizC[i][j]=aux;
      aux=0;
		}
	}
}

void preencher(int matrizA[][tamA],int matrizB[][colunaB])
{
	int i,j;
	for(i=0;i<tamA;i++)
	{
		for(j=0;j<tamA;j++)
		{
			matrizA[i][j]=rand()%range;
		}
	}
	for(i=0;i<linhaB;i++)
	{
		for(j=0;j<colunaB;j++)
		{
			matrizB[i][j]=rand()%range;
		}
	}
}

void printar(int matrizA[][tamA],int matrizB[][colunaB])
{
	int i,j;
	for(i=0;i<tamA;i++)
	{
		for(j=0;j<tamA;j++)
		{
			printf("%d  ",matrizA[i][j]);
		}
		printf("\n");
	}
	printf("\n\nMatrizB\n\n");
	for(i=0;i<linhaB;i++)
	{
		for(j=0;j<colunaB;j++)
		{
			printf("%d  ",matrizB[i][j]);
		}
		printf("\n");
	}
}
