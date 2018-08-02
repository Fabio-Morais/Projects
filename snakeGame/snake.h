#ifndef SNAKE_H
#define SNAKE_H
#define MaxL 60
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
    protected:

    private:
        int CoordX;
        int CoordY;
};

#endif // SNAKE_H
