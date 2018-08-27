#include "funcoes.h"

Vetor* CriarVetor()
{
    Vetor *vetor= malloc(sizeof(Vetor));
    vetor->data=NULL;
    vetor->size=0;
    return vetor;
}
int ApagaData(Vetor *vec){
    int i, tamanho=vec->size;

    vec->size=0;
    vec->data=NULL;
    free(vec->data);
}
void ImprimeData(Vetor *vec){
int i;
printf("\t IMPRIME DATA\n");
for(i=0; i<vec->size; i++)
    printf("%d\n", vec->data[i]);

}
int InserirData(Vetor *vec, int number, int pos){

    vec->data= (int *)realloc(vec->data, sizeof(vec->data)*((vec->size)+1));
    if(pos==-1)
        vec->data[vec->size]=number;
    else
        vec->data[pos]=number;

     vec->size++;
    return 1;
}

void menu(Vetor *vec){
int escolha;
ciclo:
        ImprimeData(vec);

printf("1-Insertion Sort\n");
printf("2-Selection Sort\n");
printf("3-BubbleSort\n");
printf("4-Quick Sort\n");
printf("5-Quick Sort 2 pivot\n");
printf("6-Mergesort\n");
printf("7-Pesquisa Binárian\n");

scanf("%d", &escolha);
switch(escolha){

case 1:
    InsertionSort(vec);
    break;
case 2:
    SelectionSort(vec);
    break;
case 3:
    bubbleSort(vec);
    break;
case 4:
    QuickSort1(vec);
    break;
case 5:
    QuickSort2Pivot(vec);
    break;
case 6:
    Mergesort(vec);
    break;
case 7:
    break;

}goto ciclo;

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

fclose(fp);
}

int EscreverFicheiro(Vetor *vec){
int i;
FILE *fp=fopen("PosSort.txt", "w");

for(i=0; i<vec->size; i++)
    fprintf(fp, "%d\n" ,vec->data[i]);

fclose(fp);

}


void TrocaData(Vetor *vec, int Pos1, int Pos2){
int aux;
aux=vec->data[Pos1];
vec->data[Pos1]= vec->data[Pos2];
vec->data[Pos2]=aux;
}

/** METODOS DE ORDENAÇAO **/

int InsertionSort(Vetor *vec){
    int i, x, aux;
    for(i=1; i<vec->size; i++)
    {
        aux=vec->data[i];
        for(x=i-1; x>=0; x--)
        {
            if(aux< vec->data[x])
            {
                vec->data[x+1]= vec->data[x]; //corrigir isto
                vec->data[x]=aux;//corrigir isto
            }
            else
                break;
        }
    }

}



int SelectionSort(Vetor *vec){

    int i, j, min;

    for(i=0; i<vec->size-1; i++)
    {
        min=i;
        for(j=i+1; j<vec->size; j++) // começa sempre 1 posiçao à frente do i, i fica parado e o j procura
        {
            if(vec->data[j]<vec->data[min])
                min=j;
        }
        TrocaData(vec, i, min);
    }
}


/** EXEMPLO 1**/
int QuickSort1(Vetor *vec){
    quickSortIter(vec, 0, vec->size-1);
}
/** EXEMPLO 2**/
int QuickSort2(Vetor *vec){
    quickSortIter2(vec, 0, vec->size-1);
}
/** EXEMPLO com 2 pivot**/
int QuickSort2Pivot(Vetor *vec){
    DualPivotQuickSort(vec, 0 , vec->size-1);
}
int bubbleSort(Vetor *vec)
{
   int i, j, n=vec->size;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++) // faz uma linha no fim
           if (vec->data[j] > vec->data[j+1])
                TrocaData(vec, j, j+1);
}

int Mergesort(Vetor *vec){
mergeSort(vec, 0, vec->size-1);
}

void mergeSort(Vetor *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) {
            vetorTemp[k] = vetor->data[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor->data[i];
                i++;
                k++;
            }
            else {
                if (vetor->data[i] < vetor->data[j]) {
                    vetorTemp[k] = vetor->data[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor->data[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor->data[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}
