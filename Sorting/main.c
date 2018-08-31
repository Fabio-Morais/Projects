#include "funcoes.h"
#define WINVER 0x0500
#include <windows.h>
//ver quantidade de memoria alocada
unsigned long long getTotalSystemMemory()
{
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);
    return status.ullTotalPhys; //mudar para status. (...) para outras coisas

}
int main()
{
    int x;
    inicial();
    menu();
for(int i=0; i<10; i++)
    x++;
    return 0;
}

