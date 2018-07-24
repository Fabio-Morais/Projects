#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>


#define nome 50
//PERGUNTA O NOME DOS JOGADORES
void inicializa_jogadores(char jogador_1[nome], char jogador_2[nome]);

//METE O X EM TODAS AS POSIÇOES
void inicializa_tela(char tela[3][3]);

//IMPRIME TELA DE JOGO
void imprime_tela(char tela[3][3]);

//IMPRIME AS OPÇOES POSSIVEIS
void imprime_opcoes();

//RETORNA A JOGADA, PERGUNTA QUAL A JOGADA QUE QUER
char imprime_get(char tela[3][3],int count,char jogador_1[nome], char jogador_2[nome]);

//VERIFICA SE HA ALGUM VENCEDOR E RETORNA O VENCEDOR
int valida(char tela[3][3]);

// FAZ A JOGADA, MODIFICA TELA
void faz_jogada(char tela[3][3], char jogada, int jogador);

// COUNTADOR DE JOGADAS 1  2  1  2  1  2...ETC
void gera_contador(int *count);

// IMPRIME VENCEDOR (SE EXISTIR)
void imprime_vencedor(int jogador_venc,char jogador_1[nome], char jogador_2[nome]);

//FINALIZA PROGRAMA
void finaliza();

int main()
{
    int jogador_venc=0, count=1, contador_jogadas;
    char tela[3][3], jogador_1[nome], jogador_2[nome], tecla;
    system("mode con:cols=50 lines=20");
    setlocale(LC_ALL,"");
    system("color 0B");
    inicializa_jogadores(jogador_1, jogador_2);
    for(;;)
    {
        contador_jogadas=0;
        jogador_venc=0;
        inicializa_tela(tela);

        while((jogador_venc==0) && (contador_jogadas<9))
        {
            imprime_tela(tela);
            imprime_opcoes();
            tecla=imprime_get(tela,count, jogador_1, jogador_2);
            faz_jogada(tela, tecla, count);
            gera_contador(&count);
            jogador_venc=valida(tela);
            contador_jogadas++;
        }

        imprime_tela(tela);
        imprime_vencedor(jogador_venc, jogador_1, jogador_2);
        printf("\nDo you want play again?(y/n) ");
        scanf(" %c", &tecla);
        if(tecla=='y')
            continue;
        else if(tecla=='n')
           break;
    }
    finaliza();

    return 0;
}


void imprime_vencedor(int jogador_venc, char jogador_1[nome], char jogador_2[nome]){

    if(jogador_venc==1)
        printf("\n%s wins\n\n\n", jogador_1);
    else
    {
        if(jogador_venc==2)
            printf("\n%s wins\n\n\n", jogador_2);
        else
            printf("\nNO PLAYER WON\n\n\n");
    }
}


void inicializa_jogadores(char jogador_1[nome], char jogador_2[nome])
{
    printf("\t\t**WELCOME**\n\n");
    printf("\nWrite your name player 1: ");
    scanf("%s", jogador_1);
    printf("\nWrite your name player 2: ");
    scanf("%s", jogador_2);

}

void gera_contador(int *count)
{
    (*count)++;
    if((*count)==3)
        (*count)=1;
}

void inicializa_tela(char tela[3][3])
{
    int i, j;
    for(i=0; i<3; i++)
      for(j=0; j<3; j++)
        tela[i][j]='-';



}

void imprime_tela(char tela[3][3])
{
    int i, j;
    system("cls");
    for(i=0; i<3; i++)
    {
        printf("\t");
        for(j=0; j<3; j++)
        {
            printf("%3c ", tela[i][j]);
        }
        printf("\n");
    }
        printf("\n\n\n");

}

void imprime_opcoes()
{
       int i;
       char tela[3][16];

    strcpy(tela[0],"Q/7   W/8   E/9");
    strcpy(tela[1],"A/4   S/5   D/6");
    strcpy(tela[2],"Z/1   X/2   C/3");

     for(i=0; i<3; i++)
        printf("\t%s\n", tela[i]);


}

char imprime_get(char tela[3][3], int count,char jogador_1[nome], char jogador_2[nome] )
{
    char tecla;
    int jogada[2];
      for(;;)
    {

       while(1)
       {

        if(count==1)
        printf("\nMake a move %s (X): ", jogador_1);
        else if(count==2)
        printf("\nMake a move %s (O): ", jogador_2);
        fflush(stdin);
        scanf(" %c", &tecla);
        tecla=toupper(tecla);
        if((tecla<='9' && tecla>='1') || tecla== 'Q' || tecla== 'W' || tecla== 'E' || tecla== 'A' || tecla== 'S' || tecla== 'D' || tecla== 'Z' || tecla== 'X' || tecla== 'C')
            break;
        else
            printf("\n\7*Wrong key, please check the options*\n");
       }

        if(tecla=='Q' || tecla=='7')
            {
                jogada[0]= 0;
                jogada[1]= 0;
            }

        if(tecla=='W' || tecla=='8')
            {
                jogada[0]= 0;
                jogada[1]= 1;
            }
        if(tecla=='E' || tecla=='9')
            {
                jogada[0]= 0;
                jogada[1]= 2;
            }

        if(tecla=='A' || tecla=='4')
             {
                jogada[0]= 1;
                jogada[1]= 0;
            }

        if(tecla=='S' || tecla=='5')
            {
                jogada[0]= 1;
                jogada[1]= 1;
            }

        if(tecla=='D' || tecla=='6')
            {
                jogada[0]= 1;
                jogada[1]= 2;
            }

        if(tecla=='Z' || tecla=='1')
            {
                jogada[0]= 2;
                jogada[1]= 0;
            }

        if(tecla=='X' || tecla=='2')
            {
                jogada[0]= 2;
                jogada[1]= 1;
            }

        if(tecla=='C' ||tecla== '3')
            {
                jogada[0]= 2;
                jogada[1]= 2;
            }

        if(tela[jogada[0]][jogada[1]]=='-')
            break;
        else
        {
             imprime_tela(tela);
             imprime_opcoes();
            printf("\n\7*WRONG MOVE*");

        }
    }




return tecla;
}

int valida(char tela[3][3])
{
    int i,j,jog=0,p, count1=0, count2=0;
    bool x=false, o=false;

    for(i=0; i<3; i++)
    {

        for(j=0; j<3; j++)
            if(tela[i][j]!='X')
                break;
        if(j==3)
            x=true;

        for(j=0; j<3; j++)
            if(tela[i][j]!='O')
                break;

        if(j==3)
            o=true;

        for(j=0; j<3; j++)
            if(tela[j][i]!='X')
                break;
        if(j==3)
            x=true;

        for(j=0; j<3; j++)
            if(tela[j][i]!='O')
                break;

        if(j==3)
            o=true;
        if(tela[i][i]=='X')
            count1++;
        if(tela[i][i]=='O')
            count2++;
    }

    p=0;
    for(j=2; j>=0; j--)
    {
        if(tela[p][j]!='X')
            break;
        p++;

    }

    if(j==-1)
        x=true;


    p=0;
    for(j=2; j>=0; j--)
    {
        if(tela[p][j]!='O')
            break;
        p++;
        }
    if(j==-1)
        o=true;

    if(count1==3)
        jog=1;
    else if(count2==3)
        jog=2;

    if(x)
        jog=1;
    else if(o)
        jog=2;

return jog;
}

void faz_jogada(char tela[3][3], char jogada, int jogador)
{
    char tecla='E';
    if(jogador==1)
    tecla='X';
    else if(jogador==2)
        tecla='O';

        if(jogada=='Q' || jogada=='7')
            tela[0][0]=tecla;

        if(jogada=='W' || jogada=='8')
            tela[0][1]=tecla;

        if(jogada=='E' || jogada=='9')
            tela[0][2]=tecla;

        if(jogada=='A' || jogada=='4')
            tela[1][0]=tecla;

        if(jogada=='S' || jogada=='5')
            tela[1][1]=tecla;

        if(jogada=='D' || jogada=='6')
            tela[1][2]=tecla;

        if(jogada=='Z' || jogada=='1')
            tela[2][0]=tecla;

        if(jogada=='X' || jogada=='2')
            tela[2][1]=tecla;

        if(jogada=='C' ||jogada== '3')
            tela[2][2]=tecla;

}



void finaliza()
{
    system("mode con:cols=100 lines=20");
    system("cls");
    printf("\n\t***Created by Fábio Morais***\n\nTHANKS FOR PLAYING\n");
    system("pause");
}




