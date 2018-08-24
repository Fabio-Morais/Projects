#include <stdio.h>
#include <string.h>
#define clear() system("cls")
void menu();
long long And();
long long Or();
long long Xor();
long long Complemento();
long long ShiftLeft();
long long ShiftRight();
void menuCalcu();
void menuCalcuValid();
long long convertBinaryToDecimal(  long long n);
long long convertDecimalToBinary(  long long n);


long long val1,val1Convert,val2, val2Convert;
int valid;// 1-decimal, 2 binario
int main()
{
    long long n;

    n=25;
    menu();
//    convertDecimalToBinary(n);// 25 em decimal
//    printf("%lli",convertDecimalToBinary(n)); //54 em decimal
//
//    printf("\n");
//    scanf("%lli", &n);
//
//    printf("%lli",convertBinaryToDecimal(n)); //54 em decimal
    menuCalcu();



    return 0;

}
void LerDecimal()
{
    printf("Escreva o numero em decimal: ");
    scanf("%lli", &val1);//decimal
    clear();
    val1Convert=convertDecimalToBinary(val1);
    printf("O numero %lli em binario e: %lli\n\n",val1, val1Convert );
}
void LerBinario()
{
    printf("Escreva o numero em binario: ");
    scanf("%lli", &val1Convert);//decimal
    clear();
    val1=convertBinaryToDecimal(val1Convert);
    printf("O numero %lli em decimal e: %lli\n\n",val1Convert,val1Convert  );

}

void menu()
{
    clear();
    printf("1- Dec\n");
    printf("2- Bin\n");
    int  x;
repeat:
    scanf("%llu", &valid);
    clear();
    switch(valid)
    {
    case 1:
        LerDecimal();
        break;
    case 2:
        LerBinario();
        break;
    default:
        goto repeat;
        break;
    }
}

long long And()
{
    if(valid==1)
    {
        printf("\nIntruduzir o numero em decimal: ");
        scanf("%lli", &val2);
    }else if(valid==2)
    {
        printf("\nIntruduzir o numero em binario: ");
        scanf("%lli", &val2Convert);
        val2=convertBinaryToDecimal(val2Convert);
    }else
        return NULL;

printf("->%lli\n", (val1&val2));

    return val1&val2;
}
long long Or()
{

    return val1|val2;
}
long long Xor()
{

    return val1^val2;
}
long long Complemento()
{
    return ~val1;
}
long long ShiftLeft()
{
int y;
    return val1<<y;
}
long long ShiftRight()
{
int y;
    return val1>>y;
}

void menuCalcu()
{
    int x;
ciclo:

    printf("1- AND\n");
    printf("2- OR\n");
    printf("3- XOR\n");
    printf("4- COMPLEMENTO\n");
    printf("5- SHIFT LEFT\n");
    printf("6- SHIFT RIGHT\n");

    scanf("%d", &x);


    switch(x)
    {
    case 1:
        And();
        break;
    case 2:
        Or();
        break;
    case 3:
        Xor();
        break;
    case 4:
        Complemento();
        break;
    case 5:
        ShiftLeft();
        break;
    case 6:
        ShiftRight();
        break;
    case 7:
        goto fim;
    default:
        break;
    }
    goto ciclo;
fim:
    return;
}

long long convertBinaryToDecimal( long long n)
{
    long long  i = 0, remainder;
    long long decimalNumber = 0;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

long long convertDecimalToBinary( long long n)
{
    long long binaryNumber = 0;
    long long remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}
