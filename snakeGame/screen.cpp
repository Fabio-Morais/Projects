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


void screen::BootScreen(char ScreenPrint[MaxC][MaxL])
{
// 178
    int i, j;
    system("mode con:cols=80 lines=35");
    system("color 0B");

    ScreenPrint[MaxC/2][MaxL/2]= 254;

    for(i=0; i<MaxL; i++)
    {
        ScreenPrint[0][i]=254;
        ScreenPrint[MaxC-1][i]=254;
        if(i<MaxC)
        {
            if(i==0)
                continue;
            if(i==MaxC-1)
                continue;
            ScreenPrint[i][0]=178;
            ScreenPrint[i][MaxL-1]=178;

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

