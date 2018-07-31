#include <iostream>
#include "screen.h"
#include <conio.h>
#include <time.h>
#include<stdlib.h>

using namespace std;

int main()
{
    char c,ScreenPrint[MaxC][MaxL]= {' '};
    int milli_seconds = 1000 * 0.2;

    screen scre;
    scre.BootScreen(ScreenPrint);
    for(;;)
    {
        while(!kbhit())
        {
            clock_t start_time = clock();
            while (clock() < start_time + milli_seconds);
            system("cls");

            scre.PrintScreen1(ScreenPrint);
            scre.snake(ScreenPrint);
        }
        c=getch();
        cout<<c<<"---------";
    }

    return 0;
}
