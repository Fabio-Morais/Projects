#ifndef SCREEN_H
#define SCREEN_H
#include "snake.h"
#define MaxL 60
#define MaxC 25
/* screen coordinates
|---------+X
|
|
+
Y

*/
class screen : public snake
{
    public:
        screen();
        virtual ~screen();
        void BootScreen(char ScreenPrint[MaxC][MaxL], int ascii); // inicializa tela
        void PrintScreen1(char ScreenPrint[MaxC][MaxL]);// imprime tela
        int ScreenSnakeUpdate(char c,char ScreenPrint[MaxC][MaxL]); // atualiza posiçao da snake
    protected:

    private:
};

#endif // SCREEN_H
