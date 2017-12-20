#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct  {
	char nome[30];
	int idade;
	float salario;

}dados;
void preencher(dados *funcionarios){
	int c=0;
	for(c=0;c<3;c++){
		printf("nome do %d funcionario: ",c+1);
		scanf(" %[^\n]s", funcionarios[c].nome);
		printf("idade: ");
		scanf("%d",&funcionarios[c].idade);
		printf("salario: ");
		scanf ("%f", &funcionarios[c].salario);
	}
}
void ordenacao(dados *funcionarios){
	int c1=0,c2=0,min=0;
	float aux=0;
	char aux1[30];
	for(c1=0;c1<2;c1++){
		min=c1;
		for(c2=c1+1;c2<3;c2++){
			if(funcionarios[c2].idade<funcionarios[min].idade){
				min=c2;
			}
			strcpy(aux1,funcionarios[c1].nome);
			strcpy(funcionarios[c1].nome,funcionarios[min].nome);
			strcpy(funcionarios[min].nome,aux1);
			aux= funcionarios[c1].idade;
			funcionarios[c1].idade= funcionarios[min].idade;
			funcionarios[min].idade=aux;
			aux= funcionarios[c1].salario;
			funcionarios[c1].salario= funcionarios[min].salario;
			funcionarios[min].salario=aux;
		}


	}
}
void imprimir(dados *funcionarios){
	int c=0;
	for(c=0;c<3;c++){
		printf("nome: %s \n",funcionarios[c].nome);
		printf("idade %d\n",funcionarios[c].idade);
		printf("salario %.2f\n", funcionarios[c].salario);
		printf("\n \n");

	}
}
int main (){
	dados funcionarios[4];
	preencher(funcionarios);
	ordenacao(funcionarios);
	imprimir (funcionarios);
return 0;
}
