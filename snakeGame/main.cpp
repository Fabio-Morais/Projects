#include <iostream>
#include "screen.h"
#include "snake.h"
#include <time.h>
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>

using namespace std;

int main()
{
    char c,ScreenPrint[MaxC][MaxL]= {' '};
    int milli_seconds = 1000 * 0.2;

    screen scre;
    snake snak;
    scre.BootScreen(ScreenPrint);



    for(;;)
    {
        while(!kbhit())
        {
            clock_t start_time = clock();
            while (clock() < start_time + milli_seconds);
            system("cls");
            scre.PrintScreen1(ScreenPrint);
            cout<<"coord:"<<snak.returnX()<<"|"<<snak.returnY()<<endl;
        }
        c=getch();
        switch(toupper(c)){
        case 'W':
            ScreenPrint[snak.returnY()][snak.returnX()]=' ';
            snak.setY(-1);
            if(snak.returnY()==0 )
                for(;;)
                cout<<"LIMITE"<<endl;
            ScreenPrint[snak.returnY()][snak.returnX()]=254;
            cout<<"tecla: w  ->"<<snak.returnX()<<"|"<<snak.returnY();
            break;
        case 'A':
            ScreenPrint[snak.returnY()][snak.returnX()]=' ';
            snak.setX(-1);
            if(snak.returnX()==0 )
                for(;;)
                cout<<"LIMITE"<<endl;
            ScreenPrint[snak.returnY()][snak.returnX()]=254;
            cout<<"tecla: A  ->"<<snak.returnX()<<"|"<<snak.returnY();
            break;
        case 'S':
            ScreenPrint[snak.returnY()][snak.returnX()]=' ';
            snak.setY(1);
            if(snak.returnY()==MaxC-1)
                for(;;)
                    cout<<"LIMITE"<<endl;
            ScreenPrint[snak.returnY()][snak.returnX()]=254;
            cout<<"tecla: S  ->"<<snak.returnX()<<"|"<<snak.returnY();
            break;
        case 'D':
            ScreenPrint[snak.returnY()][snak.returnX()]=' ';
            snak.setX(1);
            if(snak.returnX()==MaxL-1)
                for(;;)
                    cout<<"LIMITE"<<endl;
            ScreenPrint[snak.returnY()][snak.returnX()]=254;
            cout<<"tecla: D  ->"<<snak.returnX()<<"|"<<snak.returnY();
            break;
        default:
            break;
        }

    }

    return 0;
}
