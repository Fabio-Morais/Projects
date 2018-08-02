#include "screen.h"
#include <conio.h>
#include <iostream>
#include<stdlib.h>
#include <iomanip>

using namespace std;

screen::screen()
{
    //ctor
}

screen::~screen()
{
    //dtor
}


void screen::BootScreen(char ScreenPrint[MaxC][MaxL], int ascii)
{
// 178
    int i, j;
    system("mode con:cols=80 lines=35");
    system("color 0B");

    ScreenPrint[MaxC/2][MaxL/2]= 254;

    for(i=0; i<MaxL; i++)
    {
        ScreenPrint[0][i]=ascii;
        ScreenPrint[MaxC-1][i]=ascii;
        if(i<MaxC)
        {
            if(i==0)
                continue;
            if(i==MaxC-1)
                continue;
            ScreenPrint[i][0]=ascii;
            ScreenPrint[i][MaxL-1]=ascii;

        }
    }
}

void screen::PrintScreen1(char ScreenPrint[MaxC][MaxL])
{

    int i, j;
    cout<<setw(MaxL/2 +5)<<"SNAKE GAME"<<endl;
    for(i=0; i<MaxC; i++)
    {
        for(j=0; j<MaxL; j++)
        {
            if(j==MaxL-1)
                cout<< ScreenPrint[i][j]<<endl;
            else
                cout<<ScreenPrint[i][j];

        }

    }
}
/* RETURN -1 IF FIND THE LIMIT SCREEN */
int screen::ScreenSnakeUpdate(char c, char ScreenPrint[MaxC][MaxL])
{

    switch(toupper(c))    {
    case 'W':
        ScreenPrint[GetY()][GetX()]=' ';
        setY(-1);
        ScreenPrint[GetY()][GetX()]=254;
        cout<<"tecla: w  ->"<<GetX()<<"|"<<GetY();
        break;
    case 'A':
        ScreenPrint[GetY()][GetX()]=' ';
        setX(-1);
        ScreenPrint[GetY()][GetX()]=254;
        cout<<"tecla: A  ->"<<GetX()<<"|"<<GetY();
        break;
    case 'S':
        ScreenPrint[GetY()][GetX()]=' ';
        setY(1);
        ScreenPrint[GetY()][GetX()]=254;
        cout<<"tecla: S  ->"<<GetX()<<"|"<<GetY();
        break;
    case 'D':
        ScreenPrint[GetY()][GetX()]=' ';
        setX(1);
        ScreenPrint[GetY()][GetX()]=254;
        cout<<"tecla: D  ->"<<GetX()<<"|"<<GetY();
        break;
    default:
        break;
    }

    /*  SCREEN LIMIT */
    if(GetX()<=0 || GetY()<=0 || GetX()>=MaxL-1 || GetY()>=MaxC-1)
             return -1;

    else
        return 1;
}

