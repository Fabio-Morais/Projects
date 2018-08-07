#include "snake.h"



snake::snake()
{
//    setX(MaxL/2);
//    setY(MaxC/2);
    setX(10);
    setY(10);
    setXYBody(9+margem+1,10+margem+1,0);
    setXYBody(9+margem+1-1,10+margem+1,1);
    setXYBody(9+margem+1-2,10+margem+1,2);
    Direction='p';
}

snake::~snake()
{
    //dtor
}

void snake::SetDirection(char c)
{
    Direction= c;
}
char snake::GetDirection()
{
    return Direction;
}

void snake::setX(int x)
{

    if(x==1)
        CoordX++;
    else if(x==-1)
        CoordX--;
    else
        CoordX=x;
}

void snake::setY(int y)
{

    if(y==1)
        CoordY++;
    else if(y==-1)
        CoordY--;

    else
        CoordY=y;
}

void snake::setXYBody(int x,int y, int indice)
{
    body[indice].x=x;
    body[indice].y=y;


}

int snake::GetXBody(int indice)
{
    return body[indice].x;
}
int snake::GetYBody(int indice)
{

    return body[indice].y;
}

int snake::GetX()
{
    return CoordX+margem+1;
}
int snake::GetY()
{
    return CoordY+margem+1;
}

int snake::GetXFood()
{
    return CoordXFood;
}

int snake::GetYFood()
{
    return CoordYFood;
}
void snake::setXFood(int x)
{
    CoordXFood=x;
}


void snake::setYFood(int y)
{
    CoordYFood=y;
}
