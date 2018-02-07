#include <stdlib.h>
#include <stdio.h>
#include<time.h>

/*
131. Implemente uma função que receba um vetor de inteiros (vet) de tamanho n. Essa
função deve alocar dinâmicamente um outro vetor também de tamanho n que contenha os
endereços dos valores do vetor de inteiros de forma ordenada crescente, ficando a primeira
posição do vetor de ponteiros o endereço do menor valor até a última posição, que conterá o
endereço do maior valor. Essa função deve obedecer ao protótipo: int**inverte2 (int n, int*
vet);
*/


int** ordem(int n,int *vet);      //prototipo
void ordenar(int n,int *end);  //ordena vetor endereco
void preencher(int n,int *vet);

int main (){
  int *vet,n,i,*end;
  printf("\nInforme o tamanho do vetor:");
  scanf("%d",&n);
  vet=(int *) malloc(n*sizeof(int));
  srand(time(NULL));

  preencher(n,vet);
  printf("\nVETOR VET!");
  for(i=0;i<n;i++){
    printf("\n%d",vet[i]);        //printar vetor vet
  }
  end=ordem(n,vet);
  printf("\nENDERECO VETOR VET!");
  for(i=0;i<n;i++) {
    printf("\n%p",&vet[i]);        //printar vetor vet
  }
printf("\n\n\nDEPOIS DE ORDENAR!!!");
    printf("\nVETOR END!");
    for(i=0;i<n;i++){
      printf("\n%p",end[i]);        //printar vetor vet
    }
free(vet);
printf("\n\naaaa");
free(end);
printf("\n\nbbbb");
return 0;
}

int** ordem(int n,int *vet){
    int i,*end,j;
    end=(int *) malloc(sizeof(int));
    for(i=0;i<n;i++){
      end[i]=vet[i];
    }
    ordenar(n,end);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
              if(end[i]==vet[j]){
                end[i]=&vet[j];
              }
        }
    }
return end;
}


void ordenar(int n,int *end){
  int i,menor,j,aux;
  for(i=0;i<n-1;i++){
    menor=i;
    for(j=i+1;j<n;j++){
      if(end[menor]>end[j]){
        menor=j;
      }
    }
    if(end[menor]!=end[j]){
      aux=end[i];
      end[i]=end[menor];
      end[menor]=aux;
    }
  }
}


void preencher(int n,int *vet){
  int i,j=0;
      for(i=0;i<n;i++){
        vet[i]=rand()%100+1;           //preencher vetor
      }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
              if(vet[i]==vet[j]){
                preencher(n,vet);
              }
      }
    }
}
