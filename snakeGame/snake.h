#ifndef SNAKE_H
#define SNAKE_H
#define MaxL 70
#define MaxC 25
#define margem 10

struct Coordinate{
int x;
int y;
char direction;
};
typedef Coordinate Coord;

class snake
{
public:
    snake();
    virtual ~snake();
    void SetDirection(char c);
    char GetDirection();
    void setX(int x);
    void setY(int y);
    void setXYBody(int x,int y, int indice);
    int GetX();
    int GetY();
    int GetXBody(int indice);
    int GetYBody(int indice);
    int GetXFood();
    int GetYFood();
    void setXFood(int x);
    void setYFood(int y);
protected:

private:
    char Direction;
    int CoordX;
    int CoordY;
    int CoordXFood;
    int CoordYFood;
    Coord body[30];
};

#endif // SNAKE_H
