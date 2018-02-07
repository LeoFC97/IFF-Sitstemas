#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define tam 5

void preencher (int MatrizA[][tam]);
int verificar (int MatrizA[][tam]);
void printar (int MatrizA[][tam]);

int main()
{
	int MatrizA[tam][tam], resultado=3;
	preencher(MatrizA);
	printar(MatrizA);
	resultado=verificar(MatrizA);
	if(resultado==1)
	{
		printf("Diagonal dominante");
	}
	else
	{
		printf("Diagonal nao dominante");
	}
	return 0;
}

void printar (int MatrizA[][tam])
{
	int i,j;
	for(i=0;i<tam;i++)
	{
		for (j=0;j<tam;j++)
		{
			printf("%d  ",MatrizA[i][j]);
		}
		printf("\n");
	}
}

void preencher(int MatrizA[][tam])
{
	srand(time(NULL));
	int i,j;
	for(i=0;i<tam;i++)
	{
		for (j=0;j<tam;j++)
		{
			MatrizA[i][j]=rand()%10+1;
		}
	}
}

int verificar (int MatrizA[][tam]){
	int i,j, aux1=0,aux2=0,aux3=3;
	for(i=0;i<tam;i++)
	{
		for (j=0;j<tam;j++)
		{
			if(i==j)
			{
				aux1=MatrizA[i][j];
			}
			else
			{
				aux2+=MatrizA[i][j];
			}
		}
		aux1=abs(aux1);
		aux2=abs(aux2);
		if(aux1>=aux2)
		{
			aux3=1;
		}
		else
		{
			aux3=0;
			i+=tam;
			j+=tam;
		}
		aux2=0;
	}
	return aux3;
}
