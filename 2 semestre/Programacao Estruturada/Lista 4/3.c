#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct
{
  float x,y,diferenca_x,diferenca_y;
}dados;

void ler_coordenadas(dados dados[]);
float distancia(dados dados[]);

int main()
{
    dados dados[2];
    float resultado;
    ler_coordenadas(dados);
    resultado = distancia(dados);
    printf("\nA distancia dos pontos foi: %.3f\n",resultado);
}

void ler_coordenadas(dados dados[])
{
  int i;
  for(i=0;i<2;i++)
  {
    printf("Insira as coordenadas do ponto %d X,Y",i+1);
    scanf("%f %f",&dados[i].x,&dados[i].y);
  }
}
float distancia(dados dados[])
{
  float dist;
  int i=0;
  dados[i].diferenca_x=(dados[i].x)-(dados[i+1].x);
  dados[i].diferenca_y=(dados[i].y)-(dados[i+1].y);
  dist=(dados[i].diferenca_x*dados[i].diferenca_x)+(dados[i].diferenca_y*dados[i].diferenca_y);
  dist=sqrt(dist);
  return dist;
}
