#ifndef SNAKE_H
#define SNAKE_H
#define MaxL 80
#define MaxC 25

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
