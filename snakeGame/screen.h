#ifndef SCREEN_H
#define SCREEN_H
#define MaxL 65
#define MaxC 25


class screen
{
    public:
        screen();
        virtual ~screen();
        void BootScreen(char ScreenPrint[MaxC][MaxL]);
        void PrintScreen1(char ScreenPrint[MaxC][MaxL]);

    protected:

    private:
};

#endif // SCREEN_H
