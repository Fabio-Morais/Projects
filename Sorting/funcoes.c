#include "funcoes.h"

Vetor* CriarVetor()
{
    Vetor *vetor= malloc(sizeof(Vetor));
    vetor->data=NULL;
    vetor->size=0;
    return vetor;
}

void ImprimeData(Vetor *vec){
int i;
printf("\t IMPRIME DATA\n|1|\t|2|\t|3|\t|4|\t|5|\t|6|\t|7|\n");
for(i=0; i+3<vec->size; i+=7)
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", vec->data[i], vec->data[i+1], vec->data[i+2],vec->data[i+3],vec->data[i+4],vec->data[i+5],vec->data[i+6]);

}
int InserirData(Vetor *vec, int number, int pos){

    vec->data= realloc(vec->data, sizeof(int *)*vec->size+1);
    if(pos==-1)
        vec->data[vec->size]=number;
    else
        vec->data[pos]=number;

     vec->size++;
    return 1;
}

void menu(){
int escolha;

printf("1-Insertion Sort\n");
printf("2-Selection Sort\n");
printf("3-BubbleSort\n");
printf("4-Quick Sort\n");
printf("5-Mergesort\n");
printf("6-Shell Sort\n");
printf("7-Pesquisa Binárian");

switch(escolha){

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
    break;

}

}


int GerarNumero(){

int i, x;
    FILE *fp= fopen("PreSort.txt", "w");

    for(i=0; i<MAX; i++)
    {
        x=rand() % MaxRando;
        fprintf(fp, "%d\n", x);

    }
    fclose(fp);
}



int LerFicheiro(Vetor *vec){
int numero;
FILE *fp=fopen("PreSort.txt", "r");

while(fscanf(fp, "%d", &numero)==1)
    InserirData(vec, numero, -1);
}
