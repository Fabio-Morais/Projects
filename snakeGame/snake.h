#ifndef SNAKE_H
#define SNAKE_H
#define MaxL 70
#define MaxC 25
#define margem 10


class snake
{
public:
    snake();
    virtual ~snake();
    void setX(int x);
    void setY(int y);
    int GetX();
    int GetY();
    int GetXFood();
    int GetYFood();
    void setXFood(int x);
    void setYFood(int y);
protected:

private:
    int CoordX;
    int CoordY;
    int CoordXFood;
    int CoordYFood;
};

#endif // SNAKE_H
