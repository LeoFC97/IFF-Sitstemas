#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int matriz_A[3][3]={1,2,3,4,5,6,7,8,9},matriz_B[3][3]={1,2,3,4,5,6,7,8,9},matriz_C[3][3]; //declaração das matrizes como varaiveis globais

void * calcular_C(void *a);

int main()
{
  pthread_t thread1,thread2,threads3;
  int i,j,coluna1=0,coluna2=1,coluna3=2;

  pthread_create(&thread1,NULL,calcular_C,(void *)(&coluna1));
  pthread_create(&thread2,NULL,calcular_C,(void *)(&coluna2));
  pthread_create(&threads3,NULL,calcular_C,(void *)(&coluna3));

  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);
  pthread_join(thread3,NULL);
  for(i=0;i<3;i++) //imprimir as matrizes
  {
    for(j=0;j<3;j++)
    {
      printf("%d ",matriz_C[i][j]);
    }
    printf("\n");
  }
  return 0;
}

void * calcular_C(void *a) //calcular a matriz C
{
  int i,*j=(void *)a,resultado=0,c;
  for(i=0;i<3;i++)
  {
     for(c=0;c<3;c++)
     {
       soma+=(matriz_A[i][c])*(matriz_B[c][*j]);
     }
     matriz_C[i][*j]=resultado;
     resultado=0;
  }
}
