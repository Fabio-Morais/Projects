#include <stdio.h>
#include <string.h>

void menu();
void menuCalcu();
void menuCalcuValid();
int convertBinaryToDecimal(long long n);
char* convertDecimalToBinary(long long n);
char* itoa(int val, int base)
{

    static char buf[32] = {0};

    int i = 30;

    for(; val && i ; --i, val /= base)

        buf[i] = "0123456789abcdef"[val % base];

    return &buf[i+1];

}
int main()
{
    char *bufferDec, *bufferBin;
    long long n;

    n=25;
    menuCalcu();


    bufferBin=convertDecimalToBinary(n);// 25 em decimal
    printf("\n");
    scanf("%lld", &n);

    printf("%d",convertBinaryToDecimal(n)); //54 em decimal



    return 0;

}


void menu()
{

    printf("1- Dec->Bin");
    printf("2- Bin->Dec");
}
void menuCalcu()
{
    printf("1- AND\n");
    printf("2- OR\n");
    printf("3- XOR\n");
    printf("4- COMPLEMENTO\n");
    printf("5- SHIFT LEFT\n");
    printf("6- SHIFT RIGHT\n");
}
void menuCalcuValid(int x)
{
    ciclo:
    switch(x)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        goto fim;
    default:
        break;
    }goto ciclo;
    fim:
        return;

}
int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}


char* convertDecimalToBinary(long long n)
{
    int i;
    char *buffer, *dest=malloc(80);
    strcpy(dest,"0b");
    buffer=itoa(n, 2);
    strcat(dest, buffer);
    for(i=0; dest[i]!='\0'; i++)
        printf("%c", dest[i]);

    return buffer;
}
