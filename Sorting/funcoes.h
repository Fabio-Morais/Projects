
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define MaxRando 1000
typedef struct Vetor{

int *data;
int size;

}Vetor;
// POS= -1 inserir no fim
int InserirData(Vetor *vec, int number, int pos);


Vetor* CriarVetor();

void ImprimeData(Vetor *vec);


void menu();

/** Manda para o ficheiro PreSort numeros aleatorios **/
int GerarNumero();

int LerFicheiro(Vetor *vec);
