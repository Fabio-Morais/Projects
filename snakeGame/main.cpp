#include <iostream>
#include "screen.h"
#include "snake.h"
#include "menu.h"
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>
#include <windows.h>
using namespace std;

int main()
{
    char c=' ';
    int validation=0, food=-1, points=0, nivel;
    screen scre;
    snake snak;
    menu men;
    nivel=men.MenuNivel();
    scre.ClearScreen();
    men.Load();
    scre.ClearScreen();
    //inicializa a tela com o valor ascii que pretender
    for(;;)
    {
        scre.PrintScreen(177);

        for(;;)
        {
            while(kbhit())
                c=getch();
            scre.PrintSnake(190);
            scre.Delay(nivel);
            //imprime tela com a snake

            if(validation=scre.MoveSnake(c)==-1)
                break;

            scre.GenerateFood(&food);
            scre.FoodValidation(&food, &points); /*  POINTS */
            //atualiza a posiçao da snake e verifica se chega ao limite



        }
        scre.ClearScreen();
        scre.setX(0);
        scre.setY(0);
        c=' '; // Reset the c variable
        validation=0;
    }


    return 0;
}
