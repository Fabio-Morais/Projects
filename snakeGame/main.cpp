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
    int validation=0, food=-1, points=0, nivel, flag=0, assistant_valid=0;
    screen scre;
    snake snak;
    menu men;
    nivel=men.MenuNivel();
    scre.ClearScreen();
    //men.Load();
    scre.ClearScreen();
    //inicializa a tela com o valor ascii que pretender
    for(;;)
    {
        scre.PrintScreen(177);

        for(;;)
        {
            while(kbhit())
               {
                 c=getch();
                 flag++;
               }
            scre.PrintSnake(190);
            scre.Delay(nivel);

            //imprime tela com a snake
            if(validation=scre.MoveSnake(c, points+3, flag)==-1)
                break;

            scre.PrintBody(points+3);

            assistant_valid=points;

            scre.GenerateFood(&food, points);
            scre.FoodValidation(&food, &points); /*  POINTS */
            //atualiza a posiçao da snake e verifica se chega ao limite
            if(assistant_valid!=points && points>0)
                scre.IncreaseBodySize(points);
            scre.ResetMove(&c);

        }
        /* *colocar numa classe* */
        scre.ClearScreen();
        scre.setX(10);
        scre.setY(10);
        scre.setXYBody(9+margem+1,10+margem+1,0);
        scre.setXYBody(9+margem+1-1,10+margem+1,1);
        scre.setXYBody(9+margem+1-2,10+margem+1,2);
        scre.SetDirection(' ');
        scre.ResetMove(&c); // Reset the c variable
        validation=0;
        points=0;
        flag=0;
    }


    return 0;
}
