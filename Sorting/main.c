#include "funcoes.h"





int main()
{
    int i;
    GerarNumero();
    Vetor *vetor=CriarVetor();
    LerFicheiro(vetor);
    ImprimeData(vetor);
    menu();

    return 0;
}
