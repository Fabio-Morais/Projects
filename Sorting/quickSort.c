#include "quickSort.h"



void quickSortIter(Vetor *vec, int left, int right)
{
    int i, j, tamanho = right-left+1;
    if(tamanho<2) /* com tamanho 0 ou 1 esta ordenado */
        return;
    else
    {
        int pos = rand()%tamanho + left; /* determina pivot */

        //swap(&v[pos], &v[right]); /* coloca pivot no fim */
        TrocaData(vec, pos, right); //igual ao swap
        i = left;
        j = right-1; /* passo de partição */
        while(1)
        {
            while (i < right && vec->data[i] <= vec->data[right])
                i++;
            while (j >= 0 && vec->data[right] <= vec->data[j])
                j--;
            if (i < j)
                TrocaData(vec, i, j); //Igual ao de baixo
                //swap(&v[i], &v[j]);
            else break;
        }
        TrocaData(vec,i, right );
        //swap(&v[i], &v[right]); /* repoe pivot */
        quickSortIter(vec, left, i-1);
        quickSortIter(vec, i+1, right);
    }
}

void quickSortIter2(Vetor *vec, int esq, int dir)
{
    int pivo = esq, i,ch,j;
    for(i=esq+1;i<=dir;i++){
        j = i;
        if(vec->data[j] < vec->data[pivo]){
            ch = vec->data[j];
            while(j > pivo){
                vec->data[j] = vec->data[j-1];
                j--;
            }
            vec->data[j] = ch;
            pivo++;
        }
    }
    if(pivo-1 >= esq){
        quickSortIter2(vec,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quickSortIter2(vec,pivo+1,dir);
    }
 }


/** EXEMPLO COM 2 PIVO**/
void DualPivotQuickSort(Vetor *arr, int low, int high)
{
    if (low < high) {
        // lp means left pivot, and rp means right pivot.
        int lp, rp;
        rp = Partition(arr, low, high, &lp);
        DualPivotQuickSort(arr, low, lp - 1);
        DualPivotQuickSort(arr, lp + 1, rp - 1);
        DualPivotQuickSort(arr, rp + 1, high);
    }
}
/** função auxiliar **/
int Partition(Vetor *vec, int low, int high, int* lp)
{
    if (vec->data[low] > vec->data[high])
        TrocaData(vec, low, high);
    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high - 1, k = low + 1, p = vec->data[low], q = vec->data[high];
    while (k <= g) {

        // if elements are less than the left pivot
        if (vec->data[k] < p) {
            TrocaData(vec, k, j);
            j++;
        }

        // if elements are greater than or equal
        // to the right pivot
        else if (vec->data[k] >= q) {
            while (vec->data[g] > q && k < g)
                g--;
            TrocaData(vec, k, g);
            g--;
            if (vec->data[k] < p) {
                TrocaData(vec, k, j);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;

    // bring pivots to their appropriate positions.
    TrocaData(vec, low, j);
    TrocaData(vec, high, g);


    // returning the indeces of the pivots.
    *lp = j; // because we cannot return two elements
             // from a function.

    return g;
}
