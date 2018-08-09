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
    void SetBodyDirection(char c, int indice);
    char GetDirection();
    char GetBodyDirection(int indice);
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
    Coord body[70];
};

#endif // SNAKE_H
