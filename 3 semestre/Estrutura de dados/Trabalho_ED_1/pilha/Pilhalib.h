#include<stdio.h>
#include<stdlib.h>


typedef struct reg_no tipo_no;
typedef struct pilha *tipo_pilha;


tipo_pilha criar();
void incluir(tipo_pilha , int );
void imprimir(tipo_pilha );
int excluir(tipo_pilha );
void pilha_vazia(tipo_pilha );
void existe_pilha(tipo_pilha pilha);
tipo_pilha remover_pilha(tipo_pilha );
