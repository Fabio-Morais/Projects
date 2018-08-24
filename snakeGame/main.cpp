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
    char val,c=' ', assistant_char;
    int validation=0, food=-1, points=0, menuVa, flag=0, assistant_valid=0;
    screen scre;
    snake snak;
    menu men;

    resetar:
    int lives=3,  nivel=170;
    scre.CleanBody();
    do{
    menuVa= men.MenuValida( men.MenuInic(), &nivel);
    if( menuVa ==-1)
        goto GoEnd;
    }while(menuVa==1);
    scre.ClearScreen();
    //men.Load();
    scre.ClearScreen();
    //inicializa a tela com o valor ascii que pretender
    for(;;)
    {
        scre.PrintScreen(219);
        men.LogoMin();
        for(;;)
        {
            while(kbhit())
               {
                 c=getch();
                 flag++;
                scre.InvalidMove(&c, &assistant_char);
                if(c!='W' && c!='D' && c!='S' && c!='A' )
                    c=' ';
               }
            scre.PrintInfo(points, lives);
            scre.PrintSnake(flag);
            scre.Delay(nivel);

            //imprime tela com a snake
            if(validation=scre.MoveSnake(c, points+3, flag)==-1)
                break;
            if(validation=scre.BodyLimits(points+3)==-1)
                break;
            scre.PrintSnake(flag);
            scre.PrintBody(points+3);   // imprime corpo da cobra

            assistant_valid=points; /*Confirmar se aumentou ou manteve os pontos em cada ciclo*/

            scre.GenerateFood(&food, points);
            scre.FoodValidation(&food, &points); /*  POINTS */
            //atualiza a posi�ao da snake e verifica se chega ao limite

            if(assistant_valid!=points && points>0)
                scre.IncreaseBodySize(points+3);

            if(c!=' ')
                assistant_char=c; // Para nao ser possivel andar para a esquerda quando estamos a andar para direita

             scre.ResetMove(&c);
        }
        /* *colocar numa classe* */
    scre.ResetGame(&c, &validation, &points, &flag);
    if(lives==0)
        {
            scre.ClearScreen();
            cout<<"Deseja voltar ao menu principal?(y/n)"<<endl;
            cin>>val;
            if(val=='y')
                goto resetar;
            else
                goto GoEnd;
        }

    lives--;

    }
    GoEnd:

    return 0;
}
