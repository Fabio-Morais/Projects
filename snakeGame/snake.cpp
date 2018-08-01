#include "snake.h"

snake::snake()
{
setX(MaxL/2);
setY(MaxC/2);
}

snake::~snake()
{
    //dtor
}

void snake::setX(int x){
    if(x==1)
        CoordX++;
    else
        if(x==-1)
            CoordX--;
        else
            CoordX=x;
}

void snake::setY(int y){
    if(y==1)
        CoordY++;
    else
        if(y==-1)
            CoordY--;
        else
            CoordY=y;
}
int snake::returnX(){
return CoordX;
}
int snake::returnY(){
return CoordY;
}
