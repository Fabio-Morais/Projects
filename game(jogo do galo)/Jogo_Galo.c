#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>


#define nome 50
//ASK THE PLAYERS NAMES
void initializes_players(char player_1[nome], char player_2[nome]);

//PUT THE X IN ALL POSITIONS
void boot_screen(char screen[3][3]);

//PRINT GAME SCREEN
void print_screen(char screen[3][3]);

//PRINT THE POSSIBLE OPTIONS
void print_options();

//RETORNA A JOGADA, PERGUNTA QUAL A JOGADA QUE QUER
char imprime_get(char screen[3][3],int count,char player_1[nome], char player_2[nome]);

//VERIFICA SE HA ALGUM VENCEDOR E RETORNA O VENCEDOR
int valida(char screen[3][3]);

// MAKE A PLAY AND MODIFY THE SCREEN
void make_play(char screen[3][3], char jogada, int jogador);

// generates which of the players will play 1  2  1  2  1  2...ETC
void generate_counter(int *count);

// PRINT THE WINNER (IF IT EXISTS)
void print_winner(int winner_player,char player_1[nome], char player_2[nome]);

//end program
void ends();

int main()
{
    int winner_player=0, count=1, moves_counter;
    char screen[3][3], player_1[nome], player_2[nome], key;
    system("mode con:cols=50 lines=20");
    setlocale(LC_ALL,"");
    system("color 0B");
    initializes_players(player_1, player_2);
    for(;;)
    {
        moves_counter=0;
        winner_player=0;
        boot_screen(screen);

        while((winner_player==0) && (moves_counter<9))
        {
            print_screen(screen);
            print_options();
            key=imprime_get(screen,count, player_1, player_2);
            make_play(screen, key, count);
            generate_counter(&count);
            winner_player=valida(screen);
            moves_counter++;
        }

        print_screen(screen);
        print_winner(winner_player, player_1, player_2);
        printf("\nDo you want play again?(y/n) ");
        scanf(" %c", &key);
        if(key=='y')
            continue;
        else if(key=='n')
           break;
    }
    ends();

    return 0;
}


void print_winner(int winner_player, char player_1[nome], char player_2[nome]){

    if(winner_player==1)
        printf("\n%s wins\n\n\n", player_1);
    else
    {
        if(winner_player==2)
            printf("\n%s wins\n\n\n", player_2);
        else
            printf("\nNO PLAYER WON\n\n\n");
    }
}


void initializes_players(char player_1[nome], char player_2[nome])
{
    printf("\t\t**WELCOME**\n\n");
    printf("\nWrite your name player 1: ");
    scanf("%s", player_1);
    printf("\nWrite your name player 2: ");
    scanf("%s", player_2);

}

void generate_counter(int *count)
{
    (*count)++;
    if((*count)==3)
        (*count)=1;
}

void boot_screen(char screen[3][3])
{
    int i, j;
    for(i=0; i<3; i++)
      for(j=0; j<3; j++)
        screen[i][j]='-';



}

void print_screen(char screen[3][3])
{
    int i, j;
    system("cls");
    for(i=0; i<3; i++)
    {
        printf("\t");
        for(j=0; j<3; j++)
        {
            printf("%3c ", screen[i][j]);
        }
        printf("\n");
    }
        printf("\n\n\n");

}

void print_options()
{
       int i;
       char screen[3][16];

    strcpy(screen[0],"Q/7   W/8   E/9");
    strcpy(screen[1],"A/4   S/5   D/6");
    strcpy(screen[2],"Z/1   X/2   C/3");

     for(i=0; i<3; i++)
        printf("\t%s\n", screen[i]);


}

char imprime_get(char screen[3][3], int count,char player_1[nome], char player_2[nome] )
{
    char key;
    int jogada[2];
      for(;;)
    {

       while(1)
       {

        if(count==1)
        printf("\nMake a move %s (X): ", player_1);
        else if(count==2)
        printf("\nMake a move %s (O): ", player_2);
        fflush(stdin);
        scanf(" %c", &key);
        key=toupper(key);
        if((key<='9' && key>='1') || key== 'Q' || key== 'W' || key== 'E' || key== 'A' || key== 'S' || key== 'D' || key== 'Z' || key== 'X' || key== 'C')
            break;
        else
            printf("\n\7*Wrong key, please check the options*\n");
       }

        if(key=='Q' || key=='7')
            {
                jogada[0]= 0;
                jogada[1]= 0;
            }

        if(key=='W' || key=='8')
            {
                jogada[0]= 0;
                jogada[1]= 1;
            }
        if(key=='E' || key=='9')
            {
                jogada[0]= 0;
                jogada[1]= 2;
            }

        if(key=='A' || key=='4')
             {
                jogada[0]= 1;
                jogada[1]= 0;
            }

        if(key=='S' || key=='5')
            {
                jogada[0]= 1;
                jogada[1]= 1;
            }

        if(key=='D' || key=='6')
            {
                jogada[0]= 1;
                jogada[1]= 2;
            }

        if(key=='Z' || key=='1')
            {
                jogada[0]= 2;
                jogada[1]= 0;
            }

        if(key=='X' || key=='2')
            {
                jogada[0]= 2;
                jogada[1]= 1;
            }

        if(key=='C' ||key== '3')
            {
                jogada[0]= 2;
                jogada[1]= 2;
            }

        if(screen[jogada[0]][jogada[1]]=='-')
            break;
        else
        {
             print_screen(screen);
             print_options();
            printf("\n\7*WRONG MOVE*");

        }
    }




return key;
}

int valida(char screen[3][3])
{
    int i,j,jog=0,p, count1=0, count2=0;
    bool x=false, o=false;

    for(i=0; i<3; i++)
    {

        for(j=0; j<3; j++)
            if(screen[i][j]!='X')
                break;
        if(j==3)
            x=true;

        for(j=0; j<3; j++)
            if(screen[i][j]!='O')
                break;

        if(j==3)
            o=true;

        for(j=0; j<3; j++)
            if(screen[j][i]!='X')
                break;
        if(j==3)
            x=true;

        for(j=0; j<3; j++)
            if(screen[j][i]!='O')
                break;

        if(j==3)
            o=true;
        if(screen[i][i]=='X')
            count1++;
        if(screen[i][i]=='O')
            count2++;
    }

    p=0;
    for(j=2; j>=0; j--)
    {
        if(screen[p][j]!='X')
            break;
        p++;

    }

    if(j==-1)
        x=true;


    p=0;
    for(j=2; j>=0; j--)
    {
        if(screen[p][j]!='O')
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

void make_play(char screen[3][3], char jogada, int jogador)
{
    char key='E';
    if(jogador==1)
    key='X';
    else if(jogador==2)
        key='O';

        if(jogada=='Q' || jogada=='7')
            screen[0][0]=key;

        if(jogada=='W' || jogada=='8')
            screen[0][1]=key;

        if(jogada=='E' || jogada=='9')
            screen[0][2]=key;

        if(jogada=='A' || jogada=='4')
            screen[1][0]=key;

        if(jogada=='S' || jogada=='5')
            screen[1][1]=key;

        if(jogada=='D' || jogada=='6')
            screen[1][2]=key;

        if(jogada=='Z' || jogada=='1')
            screen[2][0]=key;

        if(jogada=='X' || jogada=='2')
            screen[2][1]=key;

        if(jogada=='C' ||jogada== '3')
            screen[2][2]=key;

}



void ends()
{
    system("mode con:cols=100 lines=20");
    system("cls");
    printf("\n\t***Created by Fábio Morais***\n\nTHANKS FOR PLAYING\n");
    system("pause");
}




