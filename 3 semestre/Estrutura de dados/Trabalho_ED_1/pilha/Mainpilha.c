#include <stdio.h>
#include "Pilhalib.h"

int main()
{
    int opcao, dado;
    tipo_pilha pilha = NULL;
    int resultado;

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
        	case 1:   pilha = criar();
        			      break;
            case 2:
              		  if(pilha==NULL)
                    {
              			     printf("pilha nao criada\n");
  					        }
                    else
                    {
          					      printf("Entre com um numero inteiro:");
                          scanf("%d", &dado);
                          incluir(pilha, dado);
                	  }
                    break;
            case 3: imprimir(pilha);
                    break;
            case 4: resultado=excluir(pilha);
            		  if(resultado==-5)
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
