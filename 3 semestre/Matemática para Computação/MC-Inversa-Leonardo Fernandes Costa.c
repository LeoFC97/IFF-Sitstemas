#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define range 10
#define tam 5

void gerar(int matriz[][tam]);
void multiplicar(int matrizA[][tam],int matrizB[][tam],int matrizC[][tam]);
int verificar(int matrizC[][tam]);

int main()
{
  srand(time(NULL));
  int matrizA[tam][tam],matrizB[tam][tam],matrizC[tam][tam];
  gerar(matrizA);
  gerar(matrizB);
  multiplicar(matrizA,matrizB,matrizC);
  if(verificar(matrizC)==1)
  {
		printf("B é inversa de A\n");
	}
  else
  {
		printf("B não é inversa de A\n");
	}
}

int verificar(int matriz[][tam])
{
  int i=0,j=0;
 	for(i=0;i<tam ;i++)
  {
 		for(j=0;j<tam ;j++)
    {
 			if(i==j)
      {
				if(matriz[i][j]!= 1)
        {
					return 0;
				}
			}
      else
      {
				if(matriz[i][j] != 0)
        {
					return 0;
				}
			}
		 }
	 }
	return 1;
}

void multiplicar(int matrizA[][tam],int matrizB[][tam],int matrizC[][tam])
{
  int i,j,x,aux=0;
  for(i=0;i<tam;i++)
  {
    for(j=0;j<tam;j++)
    {
      for(x=0;x<tam;x++)
      {
        aux+=matrizA[i][x]*matrizB[x][j];
      }
    }
    matrizC[i][j]=aux;
    aux=0;
  }
}

void gerar(int matriz[][tam])
{
  int i,j;
  for(i=0;i<tam;i++)
  {
    for(j=0;j<tam;j++)
    {
      matriz[i][j]=rand() % range;
    }
  }
}
