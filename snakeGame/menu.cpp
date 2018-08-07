#include "menu.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;
menu::menu()
{
    //ctor
}

menu::~menu()
{
    //dtor
}

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}
int menu::MenuNivel()
{
    int nivel;
    cout<<"Qual o nivel que deseja jogar?"<<endl;
    cout<<"1-Nivel 1\n2-Nivel 2\n3-Nivel 3\n4-Chuck Norris Nivel"<<endl;
    do
    {
        cin>>nivel;
    }
    while(nivel>4 &&nivel<1);
    switch(nivel)
    {

    case 1:
        return 200;
        break;
    case 2:
        return 100;
        break;
    case 3:
        return 40;
        break;
    case 4:
        return 20;
        break;
    default:
        break;
    }
    return -1;
}

void menu::Load()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    cout<<"loading...";
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        clock_t start_time = 160+ clock();
        while (clock() < start_time );
        cout<<(char)177;
    }

}
