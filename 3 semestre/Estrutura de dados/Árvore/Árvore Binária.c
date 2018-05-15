#include<stdio.h>
#include<stdlib.h>

typedef struct arvore{
    int numero;
    struct arvore *direita;
    struct arvore *esquerda;
}arvore;

arvore *novoNo(int numero){
    arvore *auxiliar = (arvore *)malloc(sizeof(arvore));
    auxiliar->numero = numero;
    auxiliar->esquerda = NULL;
    auxiliar->direita = NULL;
    return auxiliar;
}

arvore *inserir(arvore *no, int numero){
    if(no == NULL){ 
        return novoNo(numero);
    }

    if(numero < no->numero){
        no->esquerda = inserir(no->esquerda, numero);
    }

    else{
        no->direita = inserir(no->direita, numero);
    }
 
    return no;
}

arvore *valorMinimo(arvore *no){
    arvore *atual = no;
 
    while(atual->esquerda != NULL){
        atual = atual->esquerda;
    }
 
    return atual;
}

arvore* remover(arvore *raiz, int numero){
    if(raiz == NULL){ 
        return raiz;
    }

    if(numero < raiz->numero){
        raiz->esquerda = remover(raiz->esquerda, numero);
    }

    else if(numero > raiz->numero){
        raiz->direita = remover(raiz->direita, numero);
    }

    else{
        if(raiz->esquerda == NULL){
            arvore *auxiliar = raiz->direita;
            free(raiz);
            return auxiliar;
        }

        else if(raiz->direita == NULL){
            arvore *auxiliar = raiz->esquerda;
            free(raiz);
            return auxiliar;
        }
 
        arvore* auxiliar = valorMinimo(raiz->esquerda);
        raiz->numero = auxiliar->numero;
        raiz->direita = remover(raiz->direita, auxiliar->numero);
    }
    return raiz;
}                           

int buscar(arvore *raiz, int numero){
    if(raiz == NULL){
        return 0;
    }
    
    if(numero == raiz->numero){
        return 1;
    }

    else{
        if(numero >= raiz->numero){
            buscar(raiz->direita, numero);
        }
        
        else{
            buscar(raiz->esquerda, numero);
        }
    }
}

void emOrdem(arvore *raiz){
	if(raiz != NULL){
	    emOrdem(raiz->esquerda);
	    printf(" %d ", raiz->numero);
	    emOrdem(raiz->direita);
	}
}

void preOrdem(arvore *raiz){
	if(raiz != NULL){
        printf(" %d ", raiz->numero);
	    preOrdem(raiz->esquerda);
	    preOrdem(raiz->direita);
	}
}

void posOrdem(arvore *raiz){
	if(raiz != NULL){
        posOrdem(raiz->esquerda);
	    posOrdem(raiz->direita);
        printf(" %d ", raiz->numero);
	}
}


int main(){
    arvore *raiz = NULL;
    int numero, opcao;

    while(opcao!=7){
        printf(" 1-Inserir\n 2-Remover\n 3-Buscar\n 4-Exibir em ordem\n 5-Exibir pre-ordem\n 6-Exibir pos ordem\n 7-Sair\n\n DIGITE SUA OPCAO: ");
	    scanf("%d",&opcao);

    
        switch(opcao){
            case 1: printf("\nNúmero que desejar inserir: ");
                    scanf("%d", &numero);
                    raiz = inserir(raiz, numero);
            break;

            case 2: printf("\nNúmero que deseja remover: ");
                    scanf("%d", &numero);
                    raiz = remover(raiz, numero);
            break;
            
            case 3: if(raiz == NULL){
                        printf("\nArvore vazia\n");
                    }
                    
                    else{
                        printf("\nNúmero que deseja procurar: ");
	     				scanf("%d", &numero);
                        if(buscar(raiz, numero)){
                            printf("\nNúmero encontrado.\n");
                        }
                        
                        else{
                            printf("\nNúmero não encontrado.\n");
                        }
                    }
            break;

            case 4: printf("\n\n");
                    emOrdem(raiz);
                    printf("\n\n");
            break;
            
            case 5: printf("\n\n");
                    preOrdem(raiz);
                    printf("\n\n");
            break;

            case 6: printf("\n\n");
                    posOrdem(raiz);
                    printf("\n\n");
            break;
        }
    }
    
    return 0;
}    
