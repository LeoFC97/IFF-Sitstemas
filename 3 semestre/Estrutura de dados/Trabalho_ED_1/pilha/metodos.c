#include<stdio.h>
#include<stdlib.h>

struct reg_no
{
    int dado;
    struct reg_no *proximo;
};

typedef struct reg_no tipo_no;

struct pilha{
	int quantidade;
	tipo_no *topo;
};
typedef struct pilha *tipo_pilha;


tipo_pilha criar()
{
    tipo_pilha pilha;
    pilha = (tipo_pilha) malloc (sizeof(tipo_pilha));
    pilha->quantidade = 0;
    pilha->topo = NULL;
    return pilha;
}

void incluir(tipo_pilha pilha, int dado)
{
    tipo_no *novo;
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = dado;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->quantidade++;
}


void imprimir(tipo_pilha pilha)
{
  int aux=0;
	tipo_no *atual;
	if(pilha == NULL)
  {
		printf("Pilha ainda nao foi  criada\n ");
	}
  else
  {
		atual=pilha->topo;
		while (aux < pilha->quantidade)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
        aux++;
    }
    printf("\n\n");
	}

}


int excluir(tipo_pilha pilha)
{
    tipo_no *auxiliar;
    int aux;
  if(pilha==NULL)
  {
    return -5;
  }
  else
  {
    auxiliar=pilha->topo;
    if(pilha->topo!=NULL)
    {
      aux= pilha->topo->dado;
      pilha->topo = pilha->topo->proximo;
      pilha->quantidade--;
      free(auxiliar);
      return aux;
    }
    return -5;
  }
}
void pilha_vazia(tipo_pilha pilha)
{
	if(pilha == NULL)
  {
		printf("Pilha nao criada\n");
	}
  else
  {
		if(pilha->topo == NULL){
			printf("A pilha esta vazia\n");
		}
    else
    {
		    printf("A pilha nao esta vazia\n");
		}
	}
}
void existe_pilha(tipo_pilha pilha)
{
	if(pilha == NULL)
  {
		printf("a pilha nao exsite\n");
	}
  else
  {
		printf("a pilha existe\n");
	}
}

tipo_pilha remover_pilha(tipo_pilha pilha)
{
	tipo_no *atual, *anterior=NULL;
	if(pilha == NULL)
  {
		printf("Pilha nao criada\n");
	}
  else
  {
		atual=pilha->topo;
		while(atual != NULL){
			anterior = atual;
        	atual = atual->proximo;
        	free(anterior);
		}
		free(pilha);
	}
	return NULL;
}
