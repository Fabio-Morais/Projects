#include <iostream>
#include "screen.h"
#include "snake.h"
#include <time.h>
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>
#include <windows.h>
#define TIME 1000 * 0.2
using namespace std;

int main()
{
    char c,ScreenPrint[MaxC][MaxL]= {' '};
    int milli_seconds = TIME;

    screen scre;
    snake snak;
    //inicializa a tela com o valor ascii que pretender
    scre.BootScreen(ScreenPrint, 177);

    for(;;)
    {
        while(!kbhit())
        {
            clock_t start_time = clock();
            //tempo para atualizar tela
            while (clock() < start_time + milli_seconds);
            system("cls");
            //imprime tela com a snake
            scre.PrintScreen1(ScreenPrint);
            cout<<"coord:"<<scre.GetX()<<"|"<<scre.GetY()<<endl;
        }
        c=getch();
        //atualiza a posiçao da snake
        if(scre.ScreenSnakeUpdate(c, ScreenPrint)==-1)
        {
            cout<<"\n\n\aGAME OVER"<<endl;
            break;
        }
    }

    return 0;
}
