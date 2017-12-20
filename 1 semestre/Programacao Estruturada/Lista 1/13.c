#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimir(char palavra[],int contadorV,int contadorC)
{
    printf("A quantidade de vogais foi: %d\n",contadorV);
    printf("A quantidade de consoantes foi: %d\n",contadorC);
}
void preencher(char palavra[])
{
    int i,tamanho;
    printf("Insira a palavra: ");
    scanf (" %[^\n]s",palavra);
    tamanho=strlen(palavra);
    int contadorV=0,contadorC=0;
    for (i=0;i<tamanho;i++)
    {
        if((palavra[i]=='A')||(palavra[i]=='a')||(palavra[i]=='E')||(palavra[i]=='e')||(palavra[i]=='I')||(palavra[i]=='i')||(palavra[i]=='O')||(palavra[i]=='o')||(palavra[i]=='U')||(palavra[i]=='u'))
        {
          contadorV++;
        }
        else if (palavra[i]!= ' ')
        {
            contadorC++;
        }
    }
    imprimir(palavra,contadorV,contadorC);
}
int main()
{
    char palavra[100];
    preencher(palavra);
    return 0;
}
