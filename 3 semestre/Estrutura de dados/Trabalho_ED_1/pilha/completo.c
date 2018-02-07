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


tipo_pilha *criar()
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
    pilha->quantidade ++;
}


void imprimir(tipo_pilha pilha)
{
  int aux=0;
	tipo_no *atual;
	if(pilha == NULL)
  {
		printf("pilha nao criada,crie-a\n ");
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


float excluir(tipo_pilha pilha)
{
    tipo_no *auxiliar;
    int aux;
	if(pilha == NULL)
  {
		return -1;
	}
  else
  {
		auxiliar=pilha->topo;
    if (pilha->topo != NULL)
    {
    	aux= pilha->topo->dado;
        pilha->topo = pilha->topo->proximo;
        free(auxiliar);
        return aux;
    }
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

int main()
{
    int opcao, dado,resultado;
    tipo_pilha pilha = NULL;

    do
    {
    	  printf("1 - Criar pilha\n");
        printf("2 - Inserir elemento\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Remover elemento\n");
        printf("5 - Verificar pilha vazia\n");
        printf("6-  Verificar se pilha existe\n");
        printf("7 - Remover pilha\n");
        printf("0 - Sair\n");
        printf("Entre com a sua opcao:");
        scanf("%d", &opcao);
        switch (opcao)
        {
        	case 1:   pilha=criar();
        			      break;
            case 2:
              		  if(pilha==NULL)
                    {
              			     printf("pilha nao criada\n");
  					        }
                    else
                    {
          					      printf("Entre com um numero inteiro:");
                          canf("%d", &dado);
                          incluir_topo(pilha, dado);
                	  }
                    break;
            case 3: imprimir(pilha);
                    break;
            case 4: resultado=excluir(pilha);
            		  if(resultado==-1)
                  {
            			     printf("imposivel fazer a exclusao pois pilha esta vazia ou nao criada\n");
					        }
                  else
                  {
						           printf("Dado removido: %d\n", resultado);
					         }
                    break;
            case 5: pilha_vazia(pilha);
            		break;
            case 6: existe_pilha(pilha);
            		break;
            case 7: pilha=remover_pilha(pilha);
            		break;
        }
    }
    while (opcao != 0);
    return 0;
}
