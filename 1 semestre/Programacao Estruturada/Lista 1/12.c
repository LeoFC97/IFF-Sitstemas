#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void preencher(char frase[],char frase_nova[])
{
    printf("Digite a frase:");
    gets(frase);
    imprimir(frase,frase_nova);
}
void imprimir(char frase[],char frase_nova[])
{
    int i;
    int j=0;
    int tamanho = strlen(frase);
    for(i=0;i<tamanho;i++)
    {
        if (frase[i]!=' ')
        {

            frase_nova[j]=frase[i];
            j++;
        }
        if  (frase[i]=='\0')
        {
            break;
        }
    }
    tamanho=j;
    for(j=0;j<tamanho;j++)
    {
        printf("%c",frase_nova[j]);
    }
}


int main()
{
    char frase[50];
    char frase_nova[50];
    preencher(frase,frase_nova);
    return 0;
}
