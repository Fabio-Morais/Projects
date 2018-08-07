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
void screen::ClearSnake(int x, int y)
{
    gotoXY(x, y);
    cout<< " ";

}

void screen::ResetMove(char *c)
{
    (*c)=' ';
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

    int i;
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
    cout<<"\nC:"<<GetXBody(0)<<","<<GetYBody(0)<<"-"<< GetXBody(1)<<","<<GetYBody(1)<<"---";




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
void screen::PrintSnake(int ascii)
{
    gotoXY(GetX(), GetY());
    cout<<(char)ascii;
}


/* RETURN -1 IF FIND THE LIMIT SCREEN */

int screen::MoveSnake(char c, int BodyCount, int flag)
{
    int i;
    if(c==' ') /*para continuar a andar*/
        c= GetDirection();

    if(BodyCount>0 && flag>0) /* SE TIVER 1 OU + ELEMENTOS NO CORPO ENTRA */
    {
        for(i=BodyCount-1; i>=0; i--)
        {
            ClearSnake(GetXBody(i), GetYBody(i));
            if(i==0)
                setXYBody(GetX(), GetY(), i);
            else
                setXYBody(GetXBody(i-1), GetYBody(i-1), i); /*VAI BUSCAR AO ELEMENTO DA FRENTE*/
                /* VAI TER DE BUSCAR O ANTERIOR AO DE CIMA, NAO PODE IR BUSCAR A ESTE*/
        }

    }
    switch(toupper(c))
    {
    case UP:
        ClearSnake(GetX(), GetY());
        SetDirection(c);
        setY(-1);
        break;
    case LEFT:
        ClearSnake(GetX(), GetY());
        SetDirection(c);
        setX(-1);
        break;
    case DOWN:
        ClearSnake(GetX(), GetY());
        SetDirection(c);
        setY(1);
        break;
    case RIGHT:
        ClearSnake(GetX(), GetY());
        SetDirection(c);
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
void screen::GenerateFood(int *food, int points)
{

    /** y-> 11 a altura+9
        ** x->  11 a largura-1
        **/
    int x,y;

    if((*food)==-1)
    {
        /* rand() % (MAX+MIN) + MIN*/
        y=rand() % ((altura+margem)-12) + 11;
        x=rand() % ((largura+margem)-12) + 11;

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
    cout<<"\n\tpoints:"<<points;
        gotoXY(10,6);
    cout<<"\nC:"<<GetXBody(0)<<","<<GetYBody(0)<<"-"<< GetXBody(1)<<","<<GetYBody(1)<<"---";
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


void screen::PrintBody(int indice)
{

    int i;
    if(indice>0)
    {
        for(i=0; i<indice; i++)
        {

            gotoXY(GetXBody(i), GetYBody(i));
            cout<<(char)64;
        }

    }

}






//void screen::SetBody(int indice, char c){
//    if(indice<0)
//        return;
//
//switch(toupper(c))
//    {
//    case UP:
//        setY(1);
//        setXYBody(GetX(), GetY(), indice, body);
//        setY(-1);
//        break;
//    case LEFT:
//        setX(1);
//        setXYBody(GetX(), GetY(), indice, body);
//        setX(-1);
//        break;
//    case DOWN:
//        setY(-1);
//        setXYBody(GetX(), GetY(), indice, body);
//        setY(1);
//        break;
//    case RIGHT:
//        setX(-1);
//        setXYBody(GetX(), GetY(), indice, body);
//        setX(1);
//        break;
//    default:
//        break;
//    }
//}


void screen::IncreaseBodySize(int indice)
{
    char c=GetDirection();
    switch(c)
    {
    case UP:
        setXYBody(GetXBody(indice-1), GetYBody(indice-1)+1, indice);
        break;
    case LEFT:
        setXYBody(GetXBody(indice-1)+1, GetYBody(indice-1), indice);
        break;
    case DOWN:
        setXYBody(GetXBody(indice-1), GetYBody(indice-1)-1, indice);
        break;
    case RIGHT:
        setXYBody(GetXBody(indice-1)-1, GetYBody(indice-1), indice);
        break;
    default:
        break;
    }
}
