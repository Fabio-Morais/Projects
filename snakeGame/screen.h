#ifndef SCREEN_H
#define SCREEN_H
#include "snake.h"
#define largura 70
#define altura 25
#define margem 10
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
        void ClearSnake(int x, int y);
        void Delay(unsigned int mseconds);
        void PrintScreen(int ascii);// imprime tela
        void PrintSnake(int ascii);// imprime tela
        int MoveSnake(char c);
        void GenerateFood(int *food);
        void FoodValidation(int *food, int *points);
    protected:

    private:
};

#endif // SCREEN_H
