#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
char crip[128];
void maiusculas(char *texto)
{
    int i;
    for(i=0; i<strlen(texto); i++) //Pega todos os caracteres do vetor string (texto ou chave)
    {
        texto[i] = toupper(texto[i]); //Transforma todas as letras minusculas em maiusculas
    }
}
void somente_letras(char *texto) //Remove numeros e caracteres especiais
{
    int i,j=0;
    char texto_novo[128];
    for(i=0; i<strlen(texto); i++) //Recolhe todos os caracteres do vetor string (texto ou chave)
    {
        if(texto[i]>='A' && texto[i]<='Z') //Se o caractere atual não estiver no intervalo de A-Z
        {
            texto_novo[j] = texto[i]; //Acrescenta a letra maiuscula à um novo vetor
            j++;
        }
    }
    for(i=0; i<j; i++) //Troca o texto antigo pelo novo formado apenas por letras
    {
        texto[i] = texto_novo[i];
    }
    texto[i] = '\0'; //Adiciona um valor nulo ao final do texto
}
void cifrar( char *texto, char *chave, int op_cifra)
{
    int i;
    maiusculas(texto);
    maiusculas(chave);
    somente_letras(texto);
    somente_letras(chave);
    for(i=0; i <strlen(texto); i++) //Recolhe todos os caracteres do vetor string (texto ou chave)
    {
        if(op_cifra == 1)
        {
            crip[i] = ((texto[i] - 'A') + (chave[i % strlen(chave)] - 'A')) % 26 + 'A'; //Criptografa o caractere
        }
    }
}
int main(int argc, char *argv[])
{
    FILE *arqs, *arqc; //Função para trabalhar com arquivos .txt
    char
    texto[128], chave[128], m1[128], m2[128], des, cripto[128], temp[128], cripz[128], key[128], ch;
    int op, e, op_cifra, i;
    {
        printf("*\n*\n*             :::::::::::::::::::::::::::::::::::::");
        printf("\n*             ::                                 ::");
        printf("\n*             ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
        printf("\n*             ::     @                     @     ::");
        printf("\n*             ::     @       NAVIO EM      @     ::");
        printf("\n*             ::     @                     @     ::");
        printf("\n*             ::     @      QUARENTENA!    @     ::");
        printf("\n*             ::     @                     @     ::");
        printf("\n*             ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
        printf("\n*             ::                                 ::");
        printf("\n*             :::::::::::::::::::::::::::::::::::::\n*\n*");
    }
    printf("\n* ---------------------------------------------------------------");
    printf("\n*\n*             **OBSERVAÇÕES PARA A SENHA E CIFRA**\n",setlocale(LC_ALL,""));
    printf("\n* - No máximo 128 caracteres;",setlocale(LC_ALL,""));
    printf("\n* - Somente é permitido a utilização de letras;",setlocale(LC_ALL,""));
    printf("\n* - Os acentos e a letra 'ç (c cedilha)' não serão aceitos;",setlocale(LC_ALL,""));
    printf("\n* ---------------------------------------------------------------");
    printf("\n*\n*");
    printf("\n* ---------------------------------------------------------------");
    printf("\n*\n* Opções: ",setlocale(LC_ALL,""));
    printf("\n* 1 - Criptografar");
    printf("\n* 2 - Acesso ao Navio");
    printf("\n* 0 - Sair do programa");
    printf("\n* ---------------------------------------------------------------");
    do
    {
        printf("\n*\n*\tDigite o numero da opcao escolhida: ");
        scanf("%d", &op);
        fflush(stdin);
        __fpurge(stdin); //somente para o linux
        e = 1;
        if(op!=1 && op!=2 && op!=0)
        {
            printf("*\n*\tOpção inválida!\n*",setlocale(LC_ALL,""));
            e = 0;
        }
    }
    while(e == 0); //Verifica se foi digitado algum texto
    switch(op)
    {
    case 0:
        return 0;
    case 1:
        printf("*\n*\n*\tCRIPTOGRAFAR! \n*\n*");
        arqs = fopen("crip1.txt","w"); //Abre o arquivo .txt em modo escrita
        arqc = fopen("crip2.txt","w"); //Abre o arquivo .txt em modo escrita
        op_cifra = 1;
        strcpy(m1, "Senha original");
        strcpy(m2, "Senha criptografada");
        break;
    case 2:
voltar:
        printf("*\n*\n*\tACESSO AO NAVIO! \n*\n*");
        arqs = fopen("crip1.txt", "r"); //Abre o arquivo .txt em modo leitura
        while(fgets(cripto,128,arqs) != NULL) //Lê o conteúdo do arquivo até que chegue ao fim
            printf("\n*\tCodigo: %s",cripto);
        printf("\n*\tInsira a chave: ");
        scanf("%s", &chave);
        for(i=0; i<strlen(chave); i++) //Pega todos os caracteres do vetor string (texto ou chave)
        {
            chave[i] = toupper(chave[i]); //Transforma todas as letras minusculas em maiusculas
        }
        arqc = fopen("crip2.txt","r"); //abre o arquivo da chave
        while(fgets(key,128,arqc) != NULL) //Lê o conteúdo do arquivo até que chegue ao fim
            if (strcmp(chave,key)!=0) //Compara a chave digita com a chave utilizada para criptografar
            {
                printf("*\n*\tAcesso Negado!!\n*"); //Nega o acesso pois a chave esta incorreta
                printf("\n*\tDeseja tentar novamente?[s/n]: ");
                scanf("%s",&ch);
                switch (ch)
                case 's': //Caso resposta seja 's', voltará ao inicio do processo
                goto voltar;
                break;
            default:
                return 1;
            }
            else
            {
                for(i=0; i<strlen(cripto); i++)
                {
                    cripz[i] = (cripto[i] - chave[i % strlen(chave)]
                                + 26) % 26 + 'A'; // Descriptografa o caractere
                }
                printf("*\n*\tSenha: %s",cripz);
                printf("\n*\n*\tNAVIO DESBLOQUEADO!!!!");
            }
        return 1;
    }
    do
    {
        printf("\n*\tDigite a senha: ");
        fgets(texto,128,stdin);
        fflush(stdin);
        __fpurge(stdin); //somente para o linux
        if(texto[strlen(texto)-1]=='\n')
        {
            texto[strlen(texto)-1]='\0';
        }
        e = 1;
        if(!strlen(texto))
        {
            printf("*\n*\tNão foi digitada nenhuma senha!\n*",setlocale(LC_ALL,""));
            e = 0;
        }
        else if(strlen(texto) < 4)
        {
            printf("*\n*\tA senha deve ter no mínimo 4 caracteres!\n*",setlocale(LC_ALL,""));
            e = 0;
        }
    }
    while(e == 0);
    do
    {
        printf("*\n*\tDigite a chave: ");
        fgets(chave,128,stdin);
        fflush(stdin);
        __fpurge(stdin); //somente para o linux
        if(chave[strlen(chave)-1]=='\n')
        {
            chave[strlen(chave)-1]='\0';
        }
        e = 1;
        if(!strlen(chave))
        {
            printf("\n*\tNão foi digitada nenhuma chave!\n*",setlocale(LC_ALL,""));
            e = 0;
        }
        else if(strlen(chave) < 4)
        {
            printf("*\n*\tA chave deve ter no mínimo 4 caracteres!\n",setlocale(LC_ALL,""));
            e = 0;
        }
    }
    while(e == 0);
    cifrar(texto,chave,op_cifra);
    printf("*\n*\n*\n*\t%s: \t%s \n*",m1,texto);
    printf("\n*\tChave: \t\t\t%s \n*",chave);
    printf("\n*\t%s: \t%s \n*",m2,crip);
    fprintf(arqs,"%s",crip); //Escreve a criptografia no arquivo .txt
    fprintf(arqc,"%s",chave); //Escreve a chave no arquivo . txt
    fclose(arqs); //fecha arquivo .txt
    fclose(arqc);
    printf("\n\n\n");
    getchar();
    getchar();
    return 0;
}
