#include <stdio.h>
#include <stdlib.h>

void imprimirAntes(int numeros[])
{
  int i;
  for(i=0;i<10;i++)
  {
    printf("%d\n",numeros[i]);
  }
}
void ordenar(int numeros[],int vetorOrganizado[])
{
  int i;
  int aux=20;
  int k=0;
  int j=0;
  for (i=0;i<10;i++)
    for(j=i+1;j<10;j++)
    {
      if(numeros[i]>numeros[j])
      {
        aux=numeros[i];
        numeros[i]=numeros[j];
        numeros[j]=aux;
      }
    }
}
void imprimirDepois(int numeros[])
{
  int i;
  printf("--------\n");
  for(i=0;i<10;i++)
  {
    printf("%d\n",numeros[i]);
  }
}
int main ()
{
  int vetorOrganizado[10];
  FILE *input = fopen("6Numeros.txt","r");
  if (input==NULL)
  {
    printf("Errro na abertura do arquivo\n");
    return 0;
  }
  else
  {
    int i;
    int numeros[10];
    for (i=0;i<10;i++)
    {
      fscanf(input,"%d",&numeros[i]);
    }
    system("6Numeros.txt");
    imprimirAntes(numeros);
    ordenar(numeros,vetorOrganizado);
    imprimirDepois(numeros);
  }
}
