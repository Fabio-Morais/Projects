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
    system("PAUSE");
}
void gotoXY(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}
void screen::ClearScreen()
{
    system("cls");
}
void screen::ClearSnake(int x, int y){
 gotoXY(x, y);
 cout<<  " ";

}

void screen::Delay(unsigned int mseconds)
{
//    int milli_seconds = TIME;
    clock_t start_time = mseconds+ clock();

    //tempo para atualizar tela
    while (clock() < start_time );

}





void screen::PrintScreen(int ascii)
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




    for(i=margem; i<=largura+margem; i++)
    {
        gotoXY(i,margem);   // fazer a tela para lado DIREITO
        cout<<(char)ascii;
        gotoXY(i,altura+margem);   // fazer a tela para lado ESQUERDO
        cout<<(char)ascii;
        if(i<=altura+margem)
        {
            gotoXY(margem,i);
            cout<<(char)ascii;
            gotoXY(largura+margem,i);
            cout<<(char)ascii;
        }
    }


}
void screen::PrintSnake(int ascii){
    gotoXY(GetX(), GetY());
    cout<<(char)ascii;
}


/* RETURN -1 IF FIND THE LIMIT SCREEN */

int screen::MoveSnake(char c)
{


    switch(toupper(c))
    {
    case UP:
        ClearSnake(GetX(), GetY());
        setY(-1);
        break;
    case LEFT:
        ClearSnake(GetX(), GetY());
        setX(-1);
        break;
    case DOWN:
        ClearSnake(GetX(), GetY());
        setY(1);
        break;
    case RIGHT:
        ClearSnake(GetX(), GetY());
        setX(1);
        break;
    default:
        break;
    }
    if(GetX()<=margem || GetY()<=margem || GetX()>=largura+margem || GetY()>=altura+margem)
        return -1;

    else
        return 1;
}

/* If food=-1, generate food*/
void screen::GenerateFood(int *food)
{

    /** y-> 11 a altura+9
        ** x->  11 a largura-1
        **/
    int x,y;

    if((*food)==-1)
    {
        /* rand() % (MAX+MIN) + MIN*/
        y=rand() % ((altura+margem)-11) + 11;
        x=rand() % ((largura+margem)-11) + 11;

        gotoXY(x, y);
        cout<<"o";


        (*food)=1;
        setXFood(x);
        setYFood(y);
    }
    else
    {
        /** ir buscar ao snake **/
        gotoXY(GetXFood(), GetYFood());
        cout<<"o";
    }


    gotoXY(16,4);
    cout<<"coord food: "<<GetXFood()<<","<< GetYFood();
    cout<<"\tcoord snake:"<<GetX()<<","<<GetY(); // debbug
}

/*Return -1 if the snake eat the food */
void screen::FoodValidation(int *food, int *points)
{

    if(GetX()== GetXFood() && GetY() == GetYFood())
    {
        (*food)= -1;
        (*points)++;
    }
}



