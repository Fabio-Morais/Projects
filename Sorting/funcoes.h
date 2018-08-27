
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define MaxRando 1000
typedef struct Vetor{

int *data;
int size;

}Vetor;
// POS= -1 inserir no fim
int InserirData(Vetor *vec, int number, int pos);

Vetor* CriarVetor();

void ImprimeData(Vetor *vec);


void menu(Vetor *vec);

/** Manda para o ficheiro PreSort numeros aleatorios **/
int GerarNumero();

int LerFicheiro(Vetor *vec);

/** METODOS DE ORDENAÇAO **/

int InsertionSort(Vetor *vec);

int SelectionSort(Vetor *vec);

int QuickSort1(Vetor *vec);

int QuickSort2(Vetor *vec);

int Mergesort(Vetor *vec);

int bubbleSort(Vetor *vec);


