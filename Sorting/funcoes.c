#include "funcoes.h"
#include "heap.h"

Vetor* CriarVetor()
{
    Vetor *vetor= malloc(sizeof(Vetor));
    vetor->data=NULL;
    vetor->size=0;
    return vetor;
}
int ApagaData(Vetor *vec)
{
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
void inicial(){

printf("-Este programa ira imprimir os tempos de cada metodo de ordenacao, bastando \nselecionando de 1 a 7 qual o metodo que desejar\n\n");
printf("-O programa ira demorar tempo a ler o ficheiro, ordenar elementos e escrever elementos\n\n");
printf("-Os tempos apresentados em cada metodo sao os reais, mesmo parecendo que demoraram mais\n\n");
printf("-OE possivel alterar o numero de elementos pressionando a tecla 10, tendo nocao que\nse for um numero mais elevado ira demorar mais um pouco\n\n");
system("PAUSE");
system("cls");
}
void menu()
{
    int escolha, i, j, HeapTime=0, count, x=0, Max;
    double Tempo;
    clock_t Ticks[2];
    char name[25], nameaux[25], NameHeap[10][25], TimeHeap[10][25];
    heap *Top10N;
    heap *Top10T;

    change:
    Top10N= heap_nova(50);
    Top10T= heap_nova(50);
    system("cls");
    printf("Selecione a quantidade de elementos pretendida: \n");
    printf("1- 5000\n");
    printf("2- 500000\n");
    printf("3- 900000\n");
    printf("4- 1000000\n");
    printf("5- 3000000\n");
    scanf("%d", &Max);
    printf("POR FAVOR AGUARDE....");
    if(Max==1)
    Max=5000;
    else if(Max==2)
        Max=500000;
        else if(Max==3)
            Max=900000;
            else if(Max==4)
                Max= 1000000;
                else if(Max==5)
                    Max=3000000;

    GerarNumero(Max);
    Vetor *vec=CriarVetor();
    LerFicheiro(vec);

ciclo:
    system("cls");
    printf("\t\tQUANTIDADE DE ELEMENTOS: %d\n\n\n", Max);
    if(i==1)
        printf("Tempo gasto: %g ms -- %s\n\n", Tempo, name);
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
    printf("10-Mudar numero de elementos\n\n");
    count=0;

    if(x>0)
        printf("\n\tTOP 10 DOS ULTIMOS TEMPOS:\n");
    for(j=0; j<10 && (Top10N->tamanho>0); j++)
        {
        strcpy(NameHeap[j],heap_remove(Top10N));
        strcpy(TimeHeap[j],heap_remove(Top10T));
        printf("\t  -> %s - %s ms\n", NameHeap[j], TimeHeap[j]);
        count++;
        }
    for(j=0; j<count; j++)
       {
        heap_insere(Top10N, NameHeap[j], atoi(TimeHeap[j]));
        heap_insere(Top10T, TimeHeap[j], atoi(TimeHeap[j]));
       }
    scanf("%d", &escolha);
    system("cls");
    printf("POR FAVOR AGUARDE....");
    switch(escolha)
    {

    case 1:
        Ticks[0] = clock();
        InsertionSort(vec);
        Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        strcpy(name, "Insertion Sort");
        break;
    case 2:
         Ticks[0] = clock();
        SelectionSort(vec);
         Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        strcpy(name, "Selection Sort");
        break;
    case 3:
         Ticks[0] = clock();
        bubbleSort(vec);
         Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        strcpy(name, "BubbleSort");
        break;
    case 4:
         Ticks[0] = clock();
        QuickSort1(vec);
         Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        strcpy(name, "Quick Sort");
        break;
    case 5:
         Ticks[0] = clock();
        QuickSort2Pivot(vec);
         Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        strcpy(name, "Quick Sort 2 pivot");
        break;
    case 6:
         Ticks[0] = clock();
        Mergesort(vec);
         Ticks[1] = clock();
        Tempo= (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        strcpy(name, "Merge Sort");
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
    case 10:
        heap_apaga(Top10N);
        heap_apaga(Top10T);
        goto change;
        break;
    }x++;
    if(escolha>0 && escolha<7)
     {
         i=1;
        heap_insere(Top10N, name, (int)Tempo);
        sprintf(nameaux, "%d", (int)Tempo);
        heap_insere(Top10T, nameaux, (int)Tempo);
     }

    EscreverFicheiro(vec);

    ApagaData(vec);
    LerFicheiro(vec);
    goto ciclo;
sair:
    ApagaData(vec);
    free(vec);
    return;
}


int GerarNumero(int MAX)
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

/** METODOS DE ORDENAÇAO **/

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
        for(j=i+1; j<vec->size; j++) // começa sempre 1 posiçao à frente do i, i fica parado e o j procura
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
