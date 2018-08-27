#include "funcoes.h"

Vetor* CriarVetor()
{
    Vetor *vetor= malloc(sizeof(Vetor));
    vetor->data=NULL;
    vetor->size=0;
    return vetor;
}
int ApagaData(Vetor *vec)
{
    int i, tamanho=vec->size;

    vec->size=0;
    vec->data=NULL;
    free(vec->data);
}
void ImprimeData(Vetor *vec)
{
    int i;
    printf("\t IMPRIME DATA\n");
    for(i=0; i<vec->size; i++)
        printf("%d\n", vec->data[i]);

}
int InserirData(Vetor *vec, int number, int pos)
{

    vec->data= (int *)realloc(vec->data, sizeof(vec->data)*((vec->size)+1));
    if(pos==-1)
        vec->data[vec->size]=number;
    else
        vec->data[pos]=number;

    vec->size++;
    return 1;
}
void ImprimePre(){
    int d;
    FILE *fp=fopen("PreSort.txt", "r");
    printf("\nPOR FAVOR, ESPERE ATE O FICHEIRO SER CARREGADO\n\n\n");
    while(fscanf(fp, "%d", &d)==1)
        printf("%d\n", d);
}

void ImprimePos(){
    int d;
    FILE *fp=fopen("PosSort.txt", "r");
    printf("\nPOR FAVOR, ESPERE ATE O FICHEIRO SER CARREGADO\n\n\n");
    while(fscanf(fp, "%d", &d)==1)
        printf("%d\n", d);
}
void menu()
{
    int escolha, i;
    double Tempo;
    clock_t Ticks[2];



    Vetor *vec=CriarVetor();
    LerFicheiro(vec);

ciclo:
    system("cls");
    if(i==1)
        printf("Tempo gasto: %g ms.\n\n", Tempo);
    i=0;
    printf("1-Insertion Sort\n");
    printf("2-Selection Sort\n");
    printf("3-BubbleSort\n");
    printf("4-Quick Sort\n");
    printf("5-Quick Sort 2 pivot\n");
    printf("6-Mergesort\n");
    printf("7-Imprimir Pre Sorting\n");
    printf("8-Imprimir Pos Sorting\n");
    printf("9-Sair\n");

    scanf("%d", &escolha);
    system("cls");
    switch(escolha)
    {

    case 1:
        Ticks[0] = clock();
        InsertionSort(vec);
        Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        break;
    case 2:
         Ticks[0] = clock();
        SelectionSort(vec);
         Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        break;
    case 3:
         Ticks[0] = clock();
        bubbleSort(vec);
         Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        break;
    case 4:
         Ticks[0] = clock();
        QuickSort1(vec);
         Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        break;
    case 5:
         Ticks[0] = clock();
        QuickSort2Pivot(vec);
         Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        break;
    case 6:
         Ticks[0] = clock();
        Mergesort(vec);
         Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        break;
    case 7:
        ImprimePre();
        system("PAUSE");
        break;
    case 8:
        ImprimePos();
        system("PAUSE");
        break;
    case 9:
        goto sair;
        break;
    }
    EscreverFicheiro(vec);
    if(escolha>0 && escolha<7)
        i=1;
    ApagaData(vec);
    LerFicheiro(vec);
    goto ciclo;
sair:
    return;
}


int GerarNumero()
{

    int i, x;
    FILE *fp= fopen("PreSort.txt", "w");

    for(i=0; i<MAX; i++)
    {
        x=rand() % MaxRando;
        fprintf(fp, "%d\n", x);

    }
    fclose(fp);
}



int LerFicheiro(Vetor *vec)
{
    int numero;
    FILE *fp=fopen("PreSort.txt", "r");

    while(fscanf(fp, "%d", &numero)==1)
        InserirData(vec, numero, -1);

    fclose(fp);
}

int EscreverFicheiro(Vetor *vec)
{
    int i;
    FILE *fp=fopen("PosSort.txt", "w");

    for(i=0; i<vec->size; i++)
        fprintf(fp, "%d\n",vec->data[i]);

    fclose(fp);

}


void TrocaData(Vetor *vec, int Pos1, int Pos2)
{
    int aux;
    aux=vec->data[Pos1];
    vec->data[Pos1]= vec->data[Pos2];
    vec->data[Pos2]=aux;
}

/** METODOS DE ORDENA�AO **/

int InsertionSort(Vetor *vec)
{
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



int SelectionSort(Vetor *vec)
{

    int i, j, min;

    for(i=0; i<vec->size-1; i++)
    {
        min=i;
        for(j=i+1; j<vec->size; j++) // come�a sempre 1 posi�ao � frente do i, i fica parado e o j procura
        {
            if(vec->data[j]<vec->data[min])
                min=j;
        }
        TrocaData(vec, i, min);
    }
}


/** EXEMPLO 1**/
int QuickSort1(Vetor *vec)
{
    quickSortIter(vec, 0, vec->size-1);
}
/** EXEMPLO 2**/
int QuickSort2(Vetor *vec)
{
    quickSortIter2(vec, 0, vec->size-1);
}
/** EXEMPLO com 2 pivot**/
int QuickSort2Pivot(Vetor *vec)
{
    DualPivotQuickSort(vec, 0, vec->size-1);
}
int bubbleSort(Vetor *vec)
{
    int i, j, n=vec->size;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++) // faz uma linha no fim
            if (vec->data[j] > vec->data[j+1])
                TrocaData(vec, j, j+1);
}

int Mergesort(Vetor *vec)
{
    mergeSort(vec, 0, vec->size-1);
}

void mergeSort(Vetor *vetor, int posicaoInicio, int posicaoFim)
{
    int i, j, k, metadeTamanho, *vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1)
    {
        if (i == metadeTamanho + 1 )
        {
            vetorTemp[k] = vetor->data[j];
            j++;
            k++;
        }
        else
        {
            if (j == posicaoFim + 1)
            {
                vetorTemp[k] = vetor->data[i];
                i++;
                k++;
            }
            else
            {
                if (vetor->data[i] < vetor->data[j])
                {
                    vetorTemp[k] = vetor->data[i];
                    i++;
                    k++;
                }
                else
                {
                    vetorTemp[k] = vetor->data[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++)
    {
        vetor->data[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}
