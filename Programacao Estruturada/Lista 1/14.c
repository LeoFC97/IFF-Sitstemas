#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



void preencher(char vetor[]){

    int i;
    printf("Insira a frase:");
    scanf(" %[^\n]s",vetor);
}
int verificar(char vetor[]){

    int i;
    char letra;
    printf("Insira a letra para ser verificada:");
    scanf(" %c",&letra);
    letra = toupper(letra);
    int f =strlen(vetor);
    for(i=0;i<f;i++)
    {
        if(vetor[i]!=' ')
        {
            vetor[i]=toupper(vetor[i]);
            if (vetor[i]==letra)
            {
                return 1;
            }
        }
        i++;
    }
return 0;
}

int main()
{
    int resultado;
    char vetor[30];
    preencher(vetor);
    resultado = verificar(vetor);
    if  (resultado==1)
    printf("A palavra existe na frase.");
    else
    printf("A palavra nao existe na frase.");
    return 0;
}
