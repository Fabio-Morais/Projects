#include "menu.h"
#include <iostream>
#include <windows.h>
#include "conio21/conio2.h"
#include <time.h>
#include <stdio.h>

using namespace std;
menu::menu()
{
    //ctor
}

menu::~menu()
{
    //dtor
}

int menu::MenuNivel()
{
    int nivel;

    Logo();
    gotoxy(30,1);
    cout<< "#### WELCOME TO ####"<<endl;
    gotoxy(10,15);
    cout<<"Qual o nivel que deseja jogar?\n\n"<<endl;
    cout<<"1-Nivel 1\n2-Nivel 2\n3-Nivel 3\n4-Chuck Norris Nivel"<<endl;
    do
    {
        cin>>nivel;
    }
    while(nivel>4 &&nivel<1);
    switch(nivel)
    {

    case 1:
        return 170;
        break;
    case 2:
        return 100;
        break;
    case 3:
        return 40;
        break;
    case 4:
        return 20;
        break;
    default:
        break;
    }
    return -1;
}

void menu::Load()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    cout<<"loading...";
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        clock_t start_time = 160+ clock();
        while (clock() < start_time );
        cout<<(char)177;
    }

}
void menu::Logo(){
    int x=0,y=0;
system("cls");
textbackground(4);
for(x=19;x<63;x++)
    {
        y=3;
        gotoxy(x,y);
        printf(" ");
        y=13;
        gotoxy(x,y);
        printf(" ");
    }
    for(y=3;y<14;y++)
    {
        x=19;
        gotoxy(x,y);
        printf("  ");
        x=62;
        gotoxy(x,y);
        printf("  ");
    }
    textcolor(15);
    textbackground(3);
    gotoxy(21,4);
    printf("                                         ");
    gotoxy(21,5);
    printf("   %c%c%c%c%c%c  %c     %c   %c%c%c%c   %c  %c  %c%c%c%c%c  ",219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,219);
    gotoxy(21,6);
    printf("  %c        %c%c    %c  %c    %c  %c  %c  %c      ",219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(21,7);
    printf("  %c        %c %c   %c  %c    %c  %c %c   %c      ",219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(21,8);
    printf("   %c%c%c%c%c   %c  %c  %c  %c    %c  %c%c    %c%c%c%c   ",219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(21,9);
    printf("        %c  %c   %c %c  %c%c%c%c%c%c  %c %c   %c      ",219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(21,10);
    printf("        %c  %c    %c%c  %c    %c  %c  %c  %c      ",219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(21,11);
    printf("  %c%c%c%c%c%c   %c     %c  %c    %c  %c  %c  %c%c%c%c%c  ",219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(21,12);
    printf("                                         ");
    textcolor(15);
    textbackground(0);
}

void menu::LogoMin(){
    int x=0,y=0;

    textbackground(15);
for(x=19;x<63;x++)
    {
        y=1;
        gotoxy(x,y);
        printf(" ");
        y=7;
        gotoxy(x,y);
        printf(" ");
    }
    for(y=1;y<8;y++)
    {
        x=19;
        gotoxy(x,y);
        printf("  ");
        x=62;
        gotoxy(x,y);
        printf("  ");
    }
    textcolor(9);
    textbackground(11);

    gotoxy(21,2);
    printf("   %c%c%c%c%c%c  %c     %c   %c%c%c%c   %c  %c  %c%c%c%c%c  ",219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,219);
    gotoxy(21,3);
    printf("  %c        %c%c    %c  %c    %c  %c  %c  %c      ",219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(21,4);
    printf("   %c%c%c%c%c   %c  %c  %c  %c    %c  %c%c    %c%c%c%c   ",219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(21,5);
    printf("        %c  %c   %c %c  %c%c%c%c%c%c  %c %c   %c      ",219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(21,6);
    printf("  %c%c%c%c%c%c   %c     %c  %c    %c  %c  %c  %c%c%c%c%c  ",219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(21,7);
    textcolor(15);
    textbackground(0);
    printf("\n\n\n\n");
}

//J= 15, 17, 19, 21
int menu::MenuInic(){
   int j=15;
    Logo();
    char tecla =' ';
    do
    {
        textcolor(15);
        gotoxy(37,15);
        printf("INICIAR");
        gotoxy(37,17);
        printf("INSTRU%c%cES",128, 229);
        gotoxy(37,19);
        printf("DIFICULDADE");
        gotoxy(37,21);
        printf("SAIR");
        gotoxy(35,j);
        textcolor(10);
        printf("%c",'>');
        textcolor(15);
        tecla = getch();
        if (tecla == 72)
        {
                gotoxy(35,j);
                printf(" ");
            if(j == 15)
                j = 23;
            j = j - 2;
        }
        else
        {
            if(tecla == 80)
            {
                    gotoxy(35,j);
                    printf(" ");
                if(j == 21)
                    j = 13;
                j = j + 2;
            }
        }
    }while(tecla != '\r');

    return(j);

}

int menu::MenuValida(int j){

switch(j){
case 15:
    return 170; // valor do nivel 1
    break;
case 17:
    Instructions();
    return 1;
    break;
case 19:
    return MenuNivel();
    break;
case 21:
    return -1;
    break;
}
 return -2;
}

void menu::Instructions(){
system("cls");
Logo();
do{
gotoxy(18,15);
printf(" UTILIZE AS TECLAS W A S D PARA MOVER A COBRA; ");
//gotoxy(18,17);
//printf("(2) PARA PAUSAR/CONTINUAR O JOGO UTILIZE A TECLA 'ESC';");
//gotoxy(18,19);
//printf("(3) COMA TODAS AS COMIDAS PARA PASSAR DE N%cVEL;",214);
gotoxy(18,17);
printf(" TOME CUIDADO COM AS PAREDES;");
//gotoxy(18,23);
//printf("(5) A CADA 5 DE COMIDA VOC%c PASSAR%c DE N%cVEL;", 210, 181, 214);
gotoxy(18,19);
printf(" VOC%c VENCER%c QUANDO PASSAR O N%cVEL 5;", 210, 181, 214);

gotoxy(18, 22);
textcolor(4);
printf(" %c PRIMA ENTER PARA VOLTAR AO MENU %c", 219,219);
}while(getch()!='\r');
}
