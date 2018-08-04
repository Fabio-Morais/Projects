#include <iostream>
#include "screen.h"
#include "snake.h"
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>
#include <windows.h>
using namespace std;

int main()
{
    char c=' ';
    int validation=0, food=-1;
    screen scre;
    snake snak;
    //inicializa a tela com o valor ascii que pretender

    for(;;)
    {
        while(kbhit())
            c=getch();

        scre.Delay(100);
        scre.ClearScreen();
        //imprime tela com a snake
        scre.PrintScreen1(177);
        cout<<"coord:"<<scre.GetX()<<"|"<<scre.GetY()<<" -> "<<c<<endl;
        if(validation=scre.MoveSnake(c)==-1)
            break;

            scre.GenerateFood(&food);
        //atualiza a posiçao da snake e verifica se chega ao limite

        if( validation==-1)
        {
            cout<<"\n\n\aGAME OVER"<<endl;
            break;
        }



    }

    return 0;
}
