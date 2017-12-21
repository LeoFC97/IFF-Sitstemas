#include<stdio.h>
#include <stdlib.h>

int main (){

    float media[6]={0};
    float nota1[6],nota2[6],nota3[6];
    char nome[6][256];
    FILE *output;
    FILE * arquivoLeitura;
    int i;
    arquivoLeitura = fopen("1Turma.txt","r");
    for (i=0;i<6;i++)
    {
        fscanf(arquivoLeitura," %s %f %f %f",&nome[i],&nota1[i],&nota2[i],&nota3[i]);
        media[i]=(nota1[i]+nota2[i]+nota3[i])/3;
    }
    fclose(arquivoLeitura);
    output=fopen("1MediasAlunos.txt","w");
    for (i=0;i<6;i++)
    {
        fprintf(output,"%s  ",nome[i]);
        fprintf(output,"%.2f\n",media[i]);
    }
    fclose(output);
    return 0;

}
