#include "funcoes.h"





int main()
{
    int i;
    GerarNumero();
    Vetor *vetor=CriarVetor();
    LerFicheiro(vetor);

//    ImprimeData(vetor);

    menu(vetor);

    ImprimeData(vetor);

    EscreverFicheiro(vetor);

//    ApagaData(vetor);

//    LerFicheiro(vetor);
//
//    ImprimeData(vetor);
//
//    SelectionSort(vetor);
//
//    ImprimeData(vetor);




    return 0;
}

