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
        void ResetMove(char *c);
        void Delay(unsigned int mseconds);
        void PrintScreen(int ascii);// imprime tela
        void PrintSnake(int ascii);// imprime tela
        int MoveSnake(char c, int BodyCount, int flag);
        void GenerateFood(int *food, int points);
        void FoodValidation(int *food, int *points);
        void PrintBody(int indice);
        void IncreaseBodySize(int indice);
//        void SetBody(int indice, char c);
    protected:

    private:
};

#endif // SCREEN_H
