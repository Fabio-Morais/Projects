#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "tabdispersao.h"
#include "vetor.h"
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include "heap.h"
#define NOME 250
tabela_dispersao *jogadores;

char nome_jogador_presente[50];

void encripta_string(char *string){
    int i,x=(strlen(string)*2);
    string[0]+=strlen(string);
    for(i=1; i<strlen(string); i++)
    {
        if(i==strlen(string)/2)
            string[i]-=x;
        else
            string[i]+=x;
        x+=x;
        if(x>80)
            x=1;

    }

}

void desincripta_string(char *string){
    int i,x=(strlen(string)*2);
    string[0]-=strlen(string);
    for(i=1; i<strlen(string); i++)
    {
        if(i==strlen(string)/2)
            string[i]+=x;
        else
            string[i]-=x;
        x+=x;
        if(x>80)
            x=1;

    }

}

void texto_centra(){
    int i,b;
    b=(80)/2;
    for(i=0; i<b; i++)
        printf(" ");
}

void print_ajuda()
{
    printf("Se ainda não tem uma conta, então deve de se registar primeiro\n");
    printf("Depois de se registar deve de fazer login com a sua conta\n\n");
    printf("Deve de escolher o tipo de perguntas que quer e o nivel que deseja jogar\n\n");
    printf("No ficheiro ""perguntas.txt"" deve de escrever as perguntas da seguinte maneira:(Ex.)\n");
    printf("Quanto é 1+1? \na)1 \nxb)2 \nc)3 \nd)4\n");
    printf("Sendo o x colocado na alinea correta\n\n\n");
    system("PAUSE");
    system("cls");
}



/**
** retorna 1 caso tenha acertado
++ retorna 0 caso tenha errado
**/
void mostra_erradas(vetor *perguntas, int *numero_erradas, char* alinea_correta)
{
    int i;
    char tecla;

    for(i=0; i<vetor_tamanho(perguntas); i++)
    {
        system("cls");
        printf("\t**As perguntas que errou foram as seguintes:**\n\n\t\tpercorra as perguntas com as teclas 'a' ou 'd'\n\n");
        printf("Pergunta %d: %s\n\n", numero_erradas[i],perguntas->elementos[i].str);// string+1 para nao mostrar o X
        printf("\t%s\t%s\t%s\t%s", perguntas->elementos[i].alinea_a, perguntas->elementos[i].alinea_b, perguntas->elementos[i].alinea_c, perguntas->elementos[i].alinea_d);
        printf("\n\tA alinea correta é a %c)",alinea_correta[i]);
        do{
            tecla= getch();
        }
        while(tecla != 'a' && tecla!= 'd');
        if(tecla=='a' && i==0)
            i--;
        if(tecla=='a'&& i>0)
            i-=2;

    }

    vetor_apaga(perguntas);
}

int escolhe_perguntas(vetor *perguntas, int numero_da_pergunta)
{
    char tecla;

    printf("\n\tEscolha a alternativa: ");
    for(;;)
    {
        scanf(" %c%*c", &tecla);
        if(tecla<'a' || tecla>'d')
            {
                printf("\n\n\7**Selecionou uma alternativa incorreta(selecione apenas a,b,c ou d como resposta**\n\tEscolha a alternativa:");
            }
        else
            break;
    }
    if(toupper(tecla)==toupper(perguntas->elementos[numero_da_pergunta].alinea_correta))
        return 1;
    else
        return 0;

}

void imprime_perguntas(vetor *perguntas, int nivel)
{
    int count=0, i=1, validacao, pontuacao=0,num_erradas=0, numero_pergunta_erradas[10];
    int milli_seconds = 1000 * 1;
    char tecla, alinea_correta[10];
    vetor *erradas= vetor_novo();
    system("cls");
    for(count=(nivel*10-10); count<(nivel*10); count++)
    {
        printf("Pergunta %d\n\n", i++);
        printf("%s\n\n", perguntas->elementos[count].str);// string+1 para nao mostrar o X
        printf("\t%s\t%s\t%s\t%s", perguntas->elementos[count].alinea_a, perguntas->elementos[count].alinea_b, perguntas->elementos[count].alinea_c, perguntas->elementos[count].alinea_d);
        validacao=escolhe_perguntas(perguntas, count);
        if(validacao==1)
        {
            clock_t start_time = clock();
            printf("\n\n\t***CORRETO**\n");
            pontuacao++;
            while (clock() < start_time + milli_seconds);
            system("cls");
        }
        else
        {
            clock_t start_time = clock();
            printf("\n\n\t\7***ERRADO**\n");
            vetor_insere(erradas, perguntas->elementos[count].str, perguntas->elementos[count].alinea_a, perguntas->elementos[count].alinea_b, perguntas->elementos[count].alinea_c, perguntas->elementos[count].alinea_d, -1);
            numero_pergunta_erradas[num_erradas]=(count+1);
            alinea_correta[num_erradas]=perguntas->elementos[count].alinea_correta;
            num_erradas++;
            while (clock() < start_time + milli_seconds);
            system("cls");
        }
    }
    altera_pontuacao(jogadores, nome_jogador_presente, pontuacao);
    manda_pontu_ficheiro(nivel);
    printf("\n\t**Errou em %d perguntas**\n\nDeseja visualizar as perguntas que errou?(y/n)\n", 10-(retorna_pontuacao(jogadores, nome_jogador_presente)));
    do
    {tecla=getch();
    }while(tecla!='y' && tecla!='n');
    if(tecla=='y')
        mostra_erradas(erradas, numero_pergunta_erradas, alinea_correta);
}


vetor* importa_perguntas(int *num_de_niveis){
    char pergunta[250], alinea_a[200], alinea_b[200], alinea_c[200],alinea_d[200], nivel[40];
    int x=0;
    (*num_de_niveis)=1;
    FILE *perguntas=fopen("perguntas.txt", "r");
    setlocale(LC_ALL,"");
    system("cls");
    vetor *perguntas_perguntas=vetor_novo();
    fgets(nivel, 40, perguntas);
//    printf("\n---%s\n", nivel);
    while(fgets(pergunta, 250, perguntas))
    {
        fgets(alinea_a, 200, perguntas);
        fgets(alinea_b, 200, perguntas);
        fgets(alinea_c, 200, perguntas);
        fgets(alinea_d, 200, perguntas);
        vetor_insere(perguntas_perguntas, pergunta, alinea_a, alinea_b, alinea_c, alinea_d, -1);

        x++;
        if(x%10==0 && x>5)
          {
            fgets(nivel, 40, perguntas);
            x=0;
            (*num_de_niveis)++;

          }
    }


    fclose(perguntas);
    return perguntas_perguntas;
}

void manda_pontu_ficheiro(int nivel)
{
    int pontu=retorna_pontuacao(jogadores, nome_jogador_presente);
FILE *fich;
    switch(nivel)
    {
    case 1:
        fich=fopen("score.bin", "ab");
        break;
    case 2:
       fich=fopen("score2.bin", "ab");
        break;
    }

    fwrite(nome_jogador_presente, sizeof(nome_jogador_presente), 1, fich);
    fwrite(&pontu,sizeof(pontu), 1,  fich);

//    fprintf(fich, "%s " "%d\n", nome_jogador_presente, retorna_pontuacao(jogadores, nome_jogador_presente));
    fclose(fich);
}

/** PRIORIDADE NEGATIVA**/
heap* ler_pontu_ficheiro(int nivel)
{
    char nome[50];
    int pontu;
    FILE *fich;
      switch(nivel)
    {
    case 1:
        fich=fopen("score.bin", "rb");
        break;
    case 2:
        fich=fopen("score2.bin", "rb");
        break;

    }
heap *top_score=heap_nova(20);

//    while(fscanf(fich, "%s" "%d", nome, &pontu)!=EOF)
//    {
//        heap_insere(top_score, nome, -pontu);
//    }

    while(fread(nome, sizeof(nome), 1, fich)==1)
    {
        fread(&pontu, sizeof(pontu), 1, fich);
        heap_insere(top_score, nome, -pontu);
    }

    return top_score;
}

void ler_para_tabela(){
    char nome[50], pass[50];
    FILE *fich=fopen("jogadores", "r");
    while(fscanf(fich, "%s" "%s", nome, pass)!=EOF)
    {
        desincripta_string(pass);
        tabela_insere(jogadores, nome, pass);
    }
//    mostraTabela(jogadores);
}



/** PERMITIR MUDAR DE UTILIZADOR **/

char imprime_top_score(heap *top_score1, heap *top_score2)
{
    system("mode con:cols=100 lines=35");
    char tecla;
    int i, tamanho1=top_score1->tamanho,tamanho2=top_score2->tamanho;
    elemento *top;
    system("cls");
    printf("\t***TOP 10***\n\n\n");
    printf("\n\t\t**NIVEL 1**\n");
    printf("-------------------------------------------------\n");
    for(i=0; (i<tamanho1 && i<10); i++)
    {
       top=heap_remove(top_score1);
       printf("|\t%*s|%5d\t|\n",-30,top->valor, (-1)*(top->prioridade) );
    }
    printf("-------------------------------------------------\n\n\n");
    printf("\n\t\t**NIVEL 2**\n");
    printf("-------------------------------------------------\n");
    for(i=0; (i<tamanho2 && i<10); i++)
    {
       top=heap_remove(top_score2);
       printf("|\t%*s|%5d\t|\n",-30,top->valor, (-1)*(top->prioridade) );
    }
    printf("-------------------------------------------------\n\n\n");
    for(;;)
    {
    printf("\nDeseja voltar para o menu principal?(y/n)\n");
    tecla=getch();
    if(tecla!='y' && tecla!='n')
        printf("\n\7*Tecla errada*");
    if(tecla== 'y' || tecla == 'n')
        break;
    }

 return tecla;

}

/** imprime o menu do login ou registo **/
void menu_login_ou_registo(){
    printf("\t\t\t********************\n");
    printf("\t\t\t*BEM VINDO AO QUIZZ*\n");
    printf("\t\t\t********************\n\n\n\n\n\n");
    printf("O que deseja fazer?\n\n\n");
    printf("\ta: login \n");
    printf("\tb: Registar\n");
    printf("\th: Ajuda\n\n\n");

}

void menu_print_nivel(int n)
{
    int i;
    char c='a';
    printf("\tPor favor, esoclha o nivel que pretende jogar\n");
    for(i=1; i<n; i++)
    printf("\t\t%c->Nivel %d\n",c++, i);

}
/** imprime o menu das disciplinas que queremos**/
void menu_print_inicial(){
    char nome[NOME];
    strcpy(nome, nome_jogador_presente);
    system("cls");
    printf("\t\t\t**BEM VINDO %s**\n\n", strupr(nome));
    printf("\tO que deseja jogar?\n");
    printf("\t\ta->Minhas perguntas\n");
    printf("\t\tb->Perguntas padrão\n");
    printf("\n\n\n\nm-> Se deseja mudar de utilizador\n"); /** é preciso fazer isto **/

}

/** escolha a opçao no menu do login ou registo **/
int menu_escolha_login_registo(){
    char tecla;
    int x;
    int milli_seconds = 1000 * 0.1;
    int milli_seconds2 = 1000 * 0.1;
    int milli_seconds3 = 1000 * 0.2;
    int milli_seconds4 = 1000 * 0.3;
    fflush(stdin);
    tecla=getch();
    system("cls");
    switch(tecla)
    {

    case 'a':
        x=valida_jogador(jogadores);//x==2 entra em root
        if(x==2)
        {
            /** ENTRA EM MODO ROOT **/
        }
        do{
            if(x==-2)
            {
                system("cls");
                menu_login_ou_registo();
                menu_escolha_login_registo();
            }

            if(x==1)
            {
                system("cls");
                printf("\n**login efetuado com sucesso**\nPor favor aguarde\n");
                clock_t start_time = clock();
                clock_t end_time = clock();
                printf("..");
                end_time;
                while (clock() < start_time + milli_seconds); //espera 1 segundos
                printf("...");
                clock_t start_time2 = clock();
                while (clock() < start_time2 + milli_seconds2); //espera 1 segundos
                printf("....");
                clock_t start_time3 = clock();
                while (clock() < start_time3 + milli_seconds3); //espera 1 segundos
                printf("....");
                clock_t start_time4 = clock();
                while (clock() < start_time4 + milli_seconds4); //espera 1 segundos
                printf("......");
                clock_t start_time5 = clock();
                while (clock() < start_time5 + milli_seconds4); //espera 1 segundos
                printf("......");
                system("cls");
                return x;
            }

            else
                x=valida_jogador(jogadores);
        } while(x!=1);
        return 1;

    case 'b':
        x=novo_jogador(jogadores);
        if(x==-2)
        {
            system("cls");
            menu_login_ou_registo();
            menu_escolha_login_registo();
        }
        printf("\n**registo efetuado com sucesso**\nPor favor aguarde\n");
       clock_t start_time = clock();
                clock_t end_time = clock();
                printf("..");
                end_time;
                while (clock() < start_time + milli_seconds); //espera 1 segundos
                printf("...");
                clock_t start_time2 = clock();
                while (clock() < start_time2 + milli_seconds2); //espera 1 segundos
                printf("....");
                clock_t start_time3 = clock();
                while (clock() < start_time3 + milli_seconds3); //espera 1 segundos
                printf("....");
                clock_t start_time4 = clock();
                while (clock() < start_time4 + milli_seconds4); //espera 1 segundos
                printf("......");
                clock_t start_time5 = clock();
                while (clock() < start_time5 + milli_seconds4); //espera 1 segundos
                printf("......");
        system("cls");
        menu_login_ou_registo();
        menu_escolha_login_registo();
        return 1;
    case 'h':
        {
            system("mode con:cols=100 lines=30");
            print_ajuda();
            system("mode con:cols=70 lines=20");
            menu_login_ou_registo();
            menu_escolha_login_registo();
            break;
        }
    default:
        menu_login_ou_registo();
        if(tecla!='\r')
            printf("\nescolha errada, selecionou a tecla (%c) por favor repita:\n", tecla);
        menu_escolha_login_registo();
        tecla=getch();
        break;
    }
    return -2;
}

/** retorna 1 para nivel 1
** retorna 2 para nivel 2...etc**/
void menu_escolha_nivel(vetor* perguntas, int n)
{
    char tecla;
    setbuf(stdin, NULL);
    tecla=getch();
    /** O N DE NUMERO DE PERGUNTAS
    ** É PRECISO LER APENAS O NUEMRO DE PERGUNTAS QUE HA
    **/
    switch(tecla){

    case 'a':
        imprime_perguntas(perguntas,1);
        break;

    case'b':
        imprime_perguntas(perguntas,2);
        break;

    default:
        menu_escolha_nivel(perguntas,  n);
        break;
    }
}

/** escolhe a opçao da disciplina **/
void menu_escolha_incial(){
    char tecla_nova, tecla;
    tecla= getch();

    switch(tecla)
    {

    case 'a':
        break;
    case 'b':
        break;

    case 'm':
        nome_jogador_presente[0]='\0';
        system("cls");
        menu_login_ou_registo();
        menu_escolha_login_registo();
        system("cls");
        menu_print_inicial();
        menu_escolha_incial();
        break;
    default:
        printf("escolha errada, por favor repita:\n");
        menu_escolha_incial(tecla_nova);
        break;
    }
}

void pedir_pass(char *pass)
{
    char tecla, animacao='*', anim[10]="*********";
    int i=0, x;
    fflush(stdin);
    while (tecla != '\r')
    {
        tecla = getch();
        if(tecla!='\r')
           {
             pass[i++] = tecla;
             fflush(stdin);

             if((int)tecla==8)
                {
                    i=i-2;
                    pass[i]='\0';

                }
           }
    }
    pass[i]='\0';

}

/** adiciona um novo jogador**/
int novo_jogador(tabela_dispersao *jogadores){
    char Nome_jogador[50], pass[40], pass2[40];
    int i=0, existencia, vali;
    int milli_seconds = 1000 * 2;

    FILE *lista_jogadores= fopen("jogadores", "a");
    do{
    printf("\nSe desejar sair escreva 0\n\n\n");
    vali=0;
    puts("Nome do jogador: ");
    scanf("%[^\n]s", Nome_jogador);
    setbuf(stdin, NULL);
    for(i=0; i<strlen(Nome_jogador); i++)
        if(Nome_jogador[i]==' ')
        {
        vali=1;

        break;
        }
    if(vali==1)
    {
        system("cls");
        printf("\n\t\7**O nome que deseja colocar não é valido, não pode ter espaço\n\n");
    }

    else{
    if(!strcmp(Nome_jogador,"0"))
        return -2;
    if((existencia=tabela_existe(jogadores, Nome_jogador))== TABDISPERSAO_EXISTE)
    {
        system("cls");
      puts("\n\t\7**O nome que deseja colocar já existe, por favor escreva outro");
    }
    }
    }while(existencia== TABDISPERSAO_EXISTE ||vali==1);

    fflush(stdin);  /**  meter *** à medida que escrevemos**/
    do{         /** ter a funçao para apagar a pass**/
        puts("\nPassword: ");
        pedir_pass(pass);
        while(strlen(pass)<6)
        {
        printf("\n**tem de ter pelo menos 6 caracteres**\nPor favor repita\n\n");
        clock_t start_time = clock();
        while (clock() < start_time + milli_seconds); //espera 3 segundos
        puts("\nPassword: ");
        pedir_pass(pass);
        }
        puts("\nInsira de novo a password: ");
        pedir_pass(pass2);
        if(strcmp(pass2,pass))
            puts("\n\t**Password não correspondem, por favor repita**");
    }while(strcmp(pass2,pass));


    fflush(stdin);
    strcpy(nome_jogador_presente,Nome_jogador);
    tabela_insere(jogadores, Nome_jogador, pass );
    encripta_string(pass);

    fprintf(lista_jogadores, "%s " "%s\n", Nome_jogador, pass);
    fclose(lista_jogadores);
    system("cls");
    return 1;
}

/**
** -2 se desejar sair
** -1 se nao existir na tabela
** 1 se existir e fizer bem o login
** 2 para dar login do root
** 0 se existir mas nao fizer bem o login
**/
int valida_jogador(tabela_dispersao *jogadores){
    char Nome_jogador[50], pass[25], tecla='\0';
    int i=0, x=0;
    printf("\nSe desejar sair escreva 0 no nome\n\n\n");
    puts("Nome do jogador: ");
    scanf("%s", Nome_jogador);
    if(!strcmp(Nome_jogador,"0"))
        return -2;
        puts("\nPassword: ");
    pedir_pass(pass);

    if(tabela_existe(jogadores, Nome_jogador)==TABDISPERSAO_NAOEXISTE)
        return -1;
    if(!strcmp(tabela_valor(jogadores, Nome_jogador), pass))
    {
        strcpy(nome_jogador_presente,Nome_jogador);
        if(!strcmp(Nome_jogador,"root"))
            return 2;
        return 1;
    }
    else
        return 0;

}

