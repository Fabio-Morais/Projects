#ifndef SCREEN_H
#define SCREEN_H
#include "snake.h"
#define largura 70
#define altura 25
#define TIME 1000 * 0.2
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
        void ClearScreen();
        void Delay(unsigned int mseconds);
        void gotoxy(int x, int y);
        void PrintScreen1(int ascii);// imprime tela
        int ScreenSnakeUpdate(char c); // atualiza posiçao da snake
        int MoveSnake(char c);
        void GenerateFood(int *food);
    protected:

    private:
};

#endif // SCREEN_H
