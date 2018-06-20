  //Exercicio 2 - Leonardo,Rafael,Lucas,Amanda


  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include <string.h>
  #include <ctype.h>

  #define range 1000+1
  typedef struct
  {
    int dia;
    int mes;
    char nome[200]; // nome com espaços
    char nome2[200];// nome sem espaços
    float valor;
    int codigo_de_venda;
  } Entrada_dados;
              /*prototipo das funcoes*/
  void opcao1(Entrada_dados dados[],int k); //(1) inserir uma venda (o código da venda não pode ser repetido);
  void opcao2(Entrada_dados dados[],int k); //(2) remover uma venda pelo código da venda;
  void opcao3(Entrada_dados dados[],int k); //(3) listar na tela todas as vendas de um vendedor pesquisando pelo seu nome;
  void opcao4(Entrada_dados dados[],int k); //(4) listar na tela todas as vendas de um vendedor em um determinado dia ou mês;
  void opcao5(Entrada_dados dados[],int k); //(5) imprimir na tela o valor total de vendas de um vendedor em um determinado dia ou mês;
  void opcao6();
  void limpa(); //limpar a tela
  int verificar_Data(int dia, int mes); //verificar a data
              /*prototipo das funcoes*/
  int verificar_Data(int dia, int mes)
  {
    if(13>mes>0)
    {
      if(8>mes>0) //menores que 8
      {
        if(mes==2) //fevereiro
        {
          if(29>dia>0)
            return 1;
        }
        if(mes%2==0) //pares
        {
          if(31>dia>0)
            return 1;
        }
        if(mes%2!=0)   //imapres
        {
          if(32>dia>0)
            return 1;
        }

      }
      if(13>mes>7)
      {
        if(mes%2==0) //pares
        {
          if(32>dia>0)
            return 1;
        }
        if(mes%2!=0)   //imapres
        {
          if(30>dia>0)
            return 1;
        }
      }
    }
    return 0;
  }
  FILE *arquivo; //ponteiro para o arquivo
  void limpa()
  {
    for (int i=0;i<100;i++)
      printf("\n");
  }
  void opcao1(Entrada_dados dados[],int k) //inserir novas vendas
  {
    if (k==0)
      arquivo = fopen("vendas.txt","w"); //se for a primeira vez cria um arquivo novo
    else
      arquivo = fopen("vendas.txt","a"); //se nao for a primeira vez, escreve como continuacao
    int p=0;
    while(p<200) //inicializa o vetor vazio
    {
      dados[k].nome2[p] ='\0';
      p++;
    }
    printf("\n\t\tVoce selecionou a opcao (1)\n\n");
    printf("Insira o dia: ");
    scanf("%d",&dados[k].dia);
    printf("Insira o mes: ");
    scanf("%d",&dados[k].mes);
    int variavel_verificar_data;
    variavel_verificar_data= verificar_Data(dados[k].dia,dados[k].mes);
    if(variavel_verificar_data!=1) //confere se a data esta correta.
    {
      printf("Data invalida\n");
      opcao1(dados,k); // se a data estiver invalida, chama a funcao novamente.
    }
    else //se a data estiver correta, prossegue com a execucao do codigo
    {
      printf("Insira o valor do produto:R$:");
      scanf("%f",&dados[k].valor);
      printf("Insira o nome do vendedor:");
      scanf(" %[^\n]s",&dados[k].nome);
      int f; //varaivel de controle do loop
      int tam = strlen(dados[k].nome);
      for(f=0;f<tam;f++)
        dados[k].nome[f]=tolower(dados[k].nome[f]); //formata o nome para minusculo
      int j=0;
      for(p=0; p<tam;p++) //retir os espacos
      {
        if (dados[k].nome[p]!=' ')
        {
         dados[k].nome2[j] = dados[k].nome[p];
         j++;
        }
      }
      dados[k].codigo_de_venda = rand() % range; //gera o numero aleatorio
      int i=0;
      while (i<k) //confere se o numero ja existe
      {
        if(dados[k].codigo_de_venda==dados[i].codigo_de_venda)
        {
          dados[k].codigo_de_venda = rand() % range; //caso exista, gera outro.
          i=0; //reinicia a posicao no vetor
        }
        else
          i++;
      }
      fprintf(arquivo,"%d ",dados[k].codigo_de_venda); //escre no arquivo as informacoes
      fprintf(arquivo,"%s ",dados[k].nome2);
      fprintf(arquivo,"%.2f ",dados[k].valor);
      fprintf(arquivo,"%d ",dados[k].dia);
      fprintf(arquivo,"%d \n",dados[k].mes);
      fclose(arquivo);
      limpa();
    }
  }
  void opcao2(Entrada_dados dados[],int k) //remover venda pelo codigo
  {
    arquivo = fopen("vendas.txt","r");
    if (k==0)
    {
      printf("\nPrimeiro insira os dados.\n");
    }
    else
    {
      int x=0;
      k--;
      int j=0,p=0;
      printf("\n\t\tVoce selecionou a opcao (2)\n\n");
      int codigo;
      printf("Insira o codigo da venda: ");
      scanf("%d",&codigo);
      int teste=0;
      // k = total de vendas, j= linha atual.
      int b=0;
      for(p=0;b<=k;p++) //procura o codigo digitado no vetor
      {
        if(dados[p].codigo_de_venda==codigo) //ACHOU O CODIGO!!!
        {
          fclose(arquivo);
          arquivo = fopen("vendas.txt","w");
          teste=1;
          for(j=0;j<p;j++) //escreve no arquivo ate  a posicao anterior daonde achou
          {
              fprintf(arquivo,"%d ",dados[j].codigo_de_venda);
              fprintf(arquivo,"%s ",dados[j].nome2);
              fprintf(arquivo,"%.2f ",dados[j].valor);
              fprintf(arquivo,"%d ",dados[j].dia);
              fprintf(arquivo,"%d \n",dados[j].mes);
          }
          for(j=p;j<k;j++) //escreve a partir daonde achou
          {
              fprintf(arquivo,"%d ",dados[j+1].codigo_de_venda);
              fprintf(arquivo,"%s ",dados[j+1].nome2);
              fprintf(arquivo,"%.2f ",dados[j+1].valor);
              fprintf(arquivo,"%d ",dados[j+1].dia);
              fprintf(arquivo,"%d \n",dados[j+1].mes);
           }
           dados[p].codigo_de_venda=0;
           dados[p].valor=0;
           while(x<200) //inicializa o vetor vazio
           {
             dados[p].nome2[x] ='\0';
             x++;
           }
           dados[p].dia=0;
           dados[p].mes=0;
         k--;
       }
       b++;
      }
      if(teste==0) //NAO ACHOU :(
        printf("Codigo nao encontrado.\n");
    }
    fclose(arquivo);
  }
  void opcao3(Entrada_dados dados[],int k)
  {
    arquivo=fopen("vendas.txt","r");
    int p=0;
    p=0;
    char nomeBusca[200];
    char nomeBuscaFormatado[200];
    while(p<200) //inicializa o vetor vazio
    {
      nomeBuscaFormatado[p] ='\0';
      p++;
    }
    if (k==0) //Primeiro insira os dados
      {
        printf("Primeiro insira os dados.\n");
      }
      else //caso os dados ja estejam inseridos
      {
        printf("\n\t\tVoce selecionou a opcao (3)\n\n");
        printf("Insira o nome do vendedor:");
        scanf(" %[^\n]s",&nomeBusca);
        int tam = strlen(nomeBusca);
        for(int f=0;f<tam;f++) // formata a string
          nomeBusca[f]=tolower(nomeBusca[f]);
        int j=0;
        p=0;
        int resultado;
        for(p=0;p<tam;p++) //retirar espacos
        {
          if (nomeBusca[p]!=' ')
          {
           nomeBuscaFormatado[j]=nomeBusca[p];
           j++;
          }
        }
        j=0;
        int teste=0;//teste para comparacao
        while (j<=k)
        {
        resultado = strcmp(nomeBuscaFormatado,dados[j].nome2);
        if(resultado==0)
        {
          printf("Codigo da venda:%d \n",dados[j].codigo_de_venda);
          printf("Valor da venda R$:%.2f \n",dados[j].valor);
          printf("Data da venda: %d/%d \n",dados[j].dia,dados[j].mes);
          teste =1;
        }
        j++;
        }
        if(teste==0)
          printf("Nome nao encontrado.\n");
      }
      fclose(arquivo);
  }
  void opcao4(Entrada_dados dados[],int k)
  {
    arquivo=fopen("vendas.txt","r");
    if (k==0)
    {
      printf("Primeiro insira os dados.\n");
    }
    else
    {
      int p=0;
      p=0;
      char nomeBusca[200];
      char nomeBuscaFormatado[200];
      while(p<200) //inicializa o vetor vazio
      {
        nomeBuscaFormatado[p] ='\0';
        p++;
      }
          printf("\n\t\tVoce selecionou a opcao (4)\n\n");
          printf("Insira o nome do vendedor:");
          scanf(" %[^\n]s",&nomeBusca);
          int f; //varaivel de controle do loop
          int tam = strlen(nomeBusca);
          for(f=0;f<tam;f++)
            nomeBusca[f]=tolower(nomeBusca[f]); //formata o nome para minusculo
          int j=0;
          p=0;
          int resultado;
          for(p=0; p<tam;p++)
          {
            if (nomeBusca[p]!=' ')
            {
             nomeBuscaFormatado[j]=nomeBusca[p];
             j++;
            }
          }
          int dia=0, mes=0,o;
          printf("Deseja listar as vendas do dia ou do mes?\n");
          printf("Dia: (1)\nMes: (2)");
          scanf("%d",&o); //opcao
          if(o==1)
          {
            printf("Insira o dia e o mes (D/M):");
            scanf("%d %d",&dia,&mes);
          }
          if(o==2)
          {
            printf("Insira o mes:");
            scanf("%d",&mes);
          }
          j=0;
          int teste =0;//comparacao do nome
          while (j<=k)
          {
            resultado = strcmp(nomeBuscaFormatado,dados[j].nome2);
            if(resultado==0) //achou a posicao
            {
              teste=1;
              if(o==1)
              {
                if ((dia==dados[j].dia)&&(mes==dados[j].mes))
                {
                  printf("Codigo da venda:%d \n",dados[j].codigo_de_venda);
                  printf("Valor da venda R$:%.2f \n",dados[j].valor);
                  printf("Data da venda: %d/%d \n",dados[j].dia,dados[j].mes);
                }
              }
              if((o==2) && (mes==dados[j].mes))
              {
                printf("Codigo da venda:%d \n",dados[j].codigo_de_venda);
                printf("Valor da venda R$:%.2f \n",dados[j].valor);
                printf("Data da venda: %d/%d \n",dados[j].dia,dados[j].mes);
              }
            }
          j++;
          }
          if(teste==0)
          {
            printf("Nome nao foi encontrado");
          }
      }
      fclose(arquivo);
  }
  void opcao5(Entrada_dados dados[],int k)
  {
    arquivo=fopen("vendas.txt","r");
    if (k==0)
    {
      printf("Primeiro insira os dados.\n");
    }
    else
    {
      float soma=0;
      int p=0;
      p=0;
      char nomeBusca[200];
      char nomeBuscaFormatado[200];
      while(p<200) //inicializa o vetor vazio
      {
        nomeBuscaFormatado[p] ='\0';
        p++;
      }
          printf("\n\t\tVoce selecionou a opcao (5)\n\n");
          printf("Insira o nome do vendedor:");
          scanf(" %[^\n]s",&nomeBusca);
          int f; //varaivel de controle do loop
          int tam = strlen(nomeBusca);
          for(f=0;f<tam;f++)
            nomeBusca[f]=tolower(nomeBusca[f]); //formata o nome para minusculo
          int j=0;
          p=0;
          int resultado;
          for(p=0; p<tam;p++)
          {
            if (nomeBusca[p]!=' ')
            {
             nomeBuscaFormatado[j]=nomeBusca[p];
             j++;
            }
          }
          int dia, mes,o;
          printf("Deseja listar as vendas do dia ou do mes?\n");
          printf("Dia: (1)\nMes: (2)");
          scanf("%d",&o);
          if(o==1)
          {
            printf("Insira o dia e o mes (D M):");
            scanf("%d %d",&dia,&mes);
          }
          if(o==2)
          {
            printf("Insira o mes:");
            scanf("%d",&mes);
          }
          int teste =0;//comparacao do nome
          j=0;
          while (j<=k)
          {
            resultado = strcmp(nomeBuscaFormatado,dados[j].nome2);
            if(resultado==0)
            {
              teste =1;
              if((o==1) && (dia==dados[j].dia) && (mes==dados[j].mes))
                soma = soma + dados[j].valor;
              if((o==2) && (mes==dados[j].mes))
                soma = soma + dados[j].valor;
            }
          j++;
          }
        if(teste==0)
        {
          printf("Nome invalido\n");
        }
        else
        {
          if(o==1)
            printf("Vendas nesse diaR$:%.2f",soma);
          if(o==2)
            printf("Vendas nesse mesR$:%.2f",soma);
        }
      }
      fclose(arquivo);
  }
  void opcao6()
  {
    printf("Voce parou a o programa");
  }
  int menu()
  {
    int opcao;
    printf("\n\n\n\n\n\n\n");
    printf("\t########################################################\n");
    printf("\t#                                                      #\n");
    printf("\t#          Programa de Gerenciamento de vendas         #\n");
    printf("\t#                                                      #\n");
    printf("\t########################################################\n\n\n");
    printf("\t\tEscolha uma opcao.....\n");
    printf("(1):Insira uma nova venda\n");
    printf("(2):Remover venda\n");
    printf("(3):Mostrar todas as vendas de um vendedor\n");
    printf("(4):Mostrar todas as vendas de um vendedor em uma data \n");
    printf("(5):Mostrar o valor total de vendas de um vendedor em uma determinada data\n");
    printf("(6):Fechar o programa\t\t");
    scanf("%d",&opcao);
    return opcao; //volta a opcao selecionada para o main
  }



  int main()
  {
    Entrada_dados dados[999]; //vetor principal que armazena a struct
    int contador=0, resultado,k=0; //k= quantidade atual de vendas
    srand(time(NULL));
    while (contador==0) //looping pra chamar as opcoes
    {
      resultado = menu();
      if (resultado==1)
      {
        opcao1(dados,k);
        k++;
      }
      if (resultado==2)
        opcao2(dados,k);
      if (resultado==3)
        opcao3(dados,k);
      if (resultado==4)
        opcao4(dados,k);
      if (resultado==5)
        opcao5(dados,k);
      if (resultado==6)
      {
        opcao6();
        break; //termina a execucao do programa
      }
      if(resultado>=7)
      {
        printf("Opcao invalida\n");
      }
    }
    return 0;
  }
