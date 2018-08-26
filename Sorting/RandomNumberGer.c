#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define MaxRando 1000

int main()
{
    int i, x;
    FILE *fp= fopen("PreSort.txt", "w");

    for(i=0; i<MAX; i++)
    {
        x=rand() % MaxRando;
        fprintf(fp, "%d\n", x);

    }

    return 0;
}
