#include "screen.h"
#include <conio.h>
#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include<windows.h>
#include <time.h>

#define UP 'W'
#define DOWN 'S'
#define LEFT 'A'
#define RIGHT 'D'

using namespace std;

screen::screen()
{
   system("mode con:cols=90 lines=35");
    system("color 0B");
     srand(time(0));
}

screen::~screen()
{
    ClearScreen();
    cout<<"\n\n\aThanks for playing\n Fa´bio Morais"<<endl;

}
void screen::ClearScreen()
{
    system("cls");
}

void screen::Delay(unsigned int mseconds)
{
//    int milli_seconds = TIME;
    clock_t start_time = mseconds+ clock();

    //tempo para atualizar tela
    while (clock() < start_time );

}

void gotoXY(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}



void screen::PrintScreen1(int ascii)
{

    int i, j;
     gotoXY(10,2);
     cout<<"------------->x  Coord: da tela interior 1->"<<largura-2<< " | coord: da tela real 11->"<<largura+9;
     gotoXY(10,3);
     cout<<"|";
     gotoXY(10,4);
     cout<<"|";
     gotoXY(10,5);
     cout<<"|";
     gotoXY(10,6);
     cout<<"y  Coord: da tela interior 1->"<<altura-1<< " | coord: da tela real 11->"<<altura+9;


    for(i=10; i<largura; i++)
    {
        gotoXY(i,10);   // fazer a tela para lado DIREITO
        cout<<(char)ascii;
        gotoXY(i,altura+10);   // fazer a tela para lado ESQUERDO
        cout<<(char)ascii;
        if(i<altura+11)
        {
            gotoXY(10,i);
            cout<<(char)ascii;
            gotoXY(largura,i);
            cout<<(char)ascii;
        }
    }
    gotoXY(10+GetX(), 10+GetY());
    cout<<(char)190<<" ";

}
/* RETURN -1 IF FIND THE LIMIT SCREEN */
int screen::ScreenSnakeUpdate(char c)
{

    switch(toupper(c))
    {
    case UP:
        setY(-1);
        break;
    case LEFT:
        setX(-1);
        break;
    case DOWN:
        setY(1);
        break;
    case RIGHT:
        setX(1);
        break;
    default:
        break;
    }

    /*  SCREEN LIMIT */
    if(GetX()<=0 || GetY()<=0 || GetX()>=largura-10 || GetY()>=altura)
        return -1;

    else
        return 1;
}



int screen::MoveSnake(char c){


    switch(toupper(c))
    {
    case UP:
        setY(-1);
        break;
    case LEFT:
        setX(-1);
        break;
    case DOWN:
        setY(1);
        break;
    case RIGHT:
        setX(1);
        break;
    default:
        break;
    }
if(GetX()<=0 || GetY()<=0 || GetX()>=largura-10 || GetY()>=altura)
        return -1;

    else
        return 1;
}


void screen::GenerateFood(int *food){

/** y-> 11 a altura+9
    ** x->  11 a largura-1
    **/
    int x,y;

if((*food)==-1)
{
    y=rand() % ((altura+9)-10) + 11;
    x=rand() % ((largura-1)-10) + 11;


     gotoXY(x, y);
     cout<<"o" << x << " "<< y;
     (*food)=1;
     setXFood(x);
     setYFood(y);
}
/** ir buscar ao snake **/
gotoXY(GetXFood(), GetYFood());
cout<<"o";
}




