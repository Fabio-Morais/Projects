#ifndef SCREEN_H
#define SCREEN_H
#define MaxL 75
#define MaxC 30


class screen
{
    public:
        screen();
        virtual ~screen();
        void BootScreen(char ScreenPrint[MaxC][MaxL]);
        void PrintScreen1(char ScreenPrint[MaxC][MaxL]);
        void snake(char ScreenPrint[MaxC][MaxL]);
        void SnakeMove(char ScreenPrint[MaxC][MaxL], int x, int y);
    protected:

    private:
};

#endif // SCREEN_H
