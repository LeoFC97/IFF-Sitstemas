#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define range 10000+1
#define tamA 5000
#define tamB 10000
#define tamC 20000
#define tamD 30000

FILE *outputA;
FILE *outputB;
FILE *outputC;
FILE *outputD;

void gerar(int vetor[],int fim);
void gravar(int vetor[],int fim);

int main()
{
	outputA=fopen("A.txt","w");
	outputB=fopen("B.txt","w");
	outputC=fopen("C.txt","w");
	outputD=fopen("D.txt","w");

	srand(time(NULL));
	int vetorA[tamA],vetorB[tamB],vetorC[tamC],vetorD[tamD];
	gerar(vetorA,tamA);
	gravar(vetorA,tamA);
	gerar(vetorB,tamB);
	gravar(vetorB,tamB);
	gerar(vetorC,tamC);
	gravar(vetorC,tamC);
	gerar(vetorD,tamD);
	gravar(vetorD,tamD);
			//compila e chama os .exe dos .c NAO ENVIAR PRA FELIPE ESSA PARTE DO CODIGO
	system("gcc BubbleSort.c -o BubbleSort");
	//system("BubbleSort.exe");
	system("gcc InsertionSort.c -o InsertionSort");
	//system("InsertionSort.exe");
	system("gcc QuickSort.c -o QuickSort");
	//system("QuickSort.exe");
	system("gcc SelectionSort.c -o SelectionSort");
	//system("SelectionSort.exe");
		//compila e chama os .exe dos .c NAO ENVIAR PRA FELIPE ESSA PARTE DO CODIGO

	return 0;
}


void gravar(int vetor[],int fim)
{
	int i;
	if(fim==tamA)
	{
		for(i=0;i<fim;i++)
			fprintf(outputA,"%d\n",vetor[i]);
	fclose(outputA);
	}
	if(fim==tamB)
	{
		for(i=0;i<fim;i++)
			fprintf(outputB,"%d\n",vetor[i]);
	fclose(outputB);
	}

	if(fim==tamC)
	{
		for(i=0;i<fim;i++)
			fprintf(outputC,"%d\n",vetor[i]);
	fclose(outputC);
	}

	if(fim==tamD)
	{
		for(i=0;i<fim;i++)
			fprintf(outputD,"%d\n",vetor[i]);
	fclose(outputD);
	}

}

void gerar(int vetor[],int fim)
{
	int i;
	for(i=0;i<fim;i++)
		vetor[i]=rand()%range;
}
