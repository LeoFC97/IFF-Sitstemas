#include <stdio.h>
#include <stdlib.h>


#define tam 3

void imprimir(int matriz[][tam],int b[tam]);
void calcular(int matriz[][tam],float x[tam],int b[tam]);

int main()
{
  int matriz[tam][tam]={3,1,0,0,2,-1,0,0,3};
  float x[tam] = {0,0,0};
  int b[tam]={4,2,0};
  int i;
  imprimir(matriz,b);
  calcular(matriz,x,b);
  for(i=0;i<tam;i++)
  {
    printf("\nx%3d =%.4f\n",i,x[i]);
  }
  return 0;
}

void calcular(int matriz[][tam],float x[tam],int b[tam])
{
  float soma=0;
  int i,j;
  for(i=0;i<tam;i++)
  {
    for(j=0;j<tam;j++)
    {
      soma+=(matriz[i][j]*x[j]);
    }
    x[i]=(b[i]-(soma))/matriz[i][i];
    soma=0;
  }
}

void imprimir(int matriz[][tam],int b[tam]){
  printf("\n\n->MATRIZ TRIANGULAR INFERIOR<-\n\n");
  for(int i=0;i<tam;i++){
    for(int j=0;j<tam;j++){
      printf("%4d",matriz[i][j]);
    }
    printf(" = %d \n",b[i]);
  }
}
