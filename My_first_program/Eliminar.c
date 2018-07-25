#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <locale.h>
#define MAX1 10
#define MAX2 20
#define MAX3 30
#define MAX4 100

typedef struct deputados{//variavel deputados
char codigo[MAX1];
char nome[MAX3];
char genero;
char circulo[MAX2];
}tdeputados ;
typedef struct partidos{//variael partidos
char sigla [MAX1];
char nome[MAX3];
int quantdeputados;
int fe;
int ma;
tdeputados deputados[MAX4];
}tpartido;
typedef struct parlamento {//variavel parlamento tparlamento
char pais[MAX1];
int quantpartidos;
tpartido partidos[MAX4];
}tparlamento;
void eliminarparlamento(tparlamento parlamento[],int *n){
int q,pos;
char refe[MAX2];
mparldisponiveis(parlamento,n);     //vai mostrar os parlamentos disponiveis
printf("\n\nQual o parlamento que deseja eliminar  ");
scanf("%s",&refe);
pos=procurarparl(parlamento,*n,refe);
if(pos!=-1){        //se o valor returnado for diferente de -1 entra no if e vai com o valor da posição e que se encontra o parlamento
    for(q=pos;q<*n-1;q++)       //ex: se houver 2 parlamentos e quiser eliminar o 1º parlamento vai ficar o seguinte:
    {                           //q vai ficar q=1;q<1;q++
        parlamento[q]=parlamento[q+1];      // o primeiro parlamento vai ficar a ser o 2º parlamento, eliminando o primeiro parlamento
    }
    *n=*n-1;        // vai reduzir o numero de parlamentos, neste exemplo vai passar de 2 a 1.
}
else
    printf("\n\7Parlamento não encontrado\n");
}
void eliminarpartido(tparlamento parlamento[],int *n){
int pos,pot,j;
char refe[MAX2];
mparldisponiveis(parlamento,n);
printf("\n\nQual o nome do parlamento em que o partido se encontra ");
scanf("%s",&refe);
pot=procurarparl(parlamento,*n,refe);
if(pot!=-1){
    mpartdisponiveis(parlamento,n,pot);
    printf("\n\nQual o partido que deseja eliminar ");
    scanf("%s",&refe);
    strupr(refe);       //converte a string em maisculo
    pos=procurarpar2(parlamento,pot,refe);
    if(pos!=-1){    // se pos !=-1 vai entrar no if e vai com o valor da posição do partido
        for (j=0;j<parlamento[pos].quantpartidos;j++)   //j=0; j<quantidade de partidos; j++
            parlamento[pot].partidos[pos]=parlamento[pot].partidos[pos+1];// ex: o partido na posição n vai ficar com o partido da posição n+1, logo vai eliminar esse partido

        parlamento[pot].quantpartidos--;    // fora do ciclo for e vai reduzir a quantidade de partidos
    }
    else
        printf("\7\nPartido não encontrado\n");
}
else
    printf("\7\nParlamento não encontrado\n");
}
void eliminardeputado(tparlamento parlamento[],int *n){
int pos,pot,j,pog,l;
char refe[MAX2];
mparldisponiveis(parlamento,n);
printf("\n\nNome do parlamento em que o deputado se encontra ");
scanf("%s",&refe);
pot=procurarparl(parlamento,*n,refe);   // vai procurar a posição do parlamento
if(pot!=-1){
        mdepudespo(parlamento,pot);
        printf("\n\nQual o código deputado que deseja eliminar ");
        scanf("%s",&refe);
        strupr(refe);       //converte a string em maisculo
        pog=procurarpar3(parlamento,pot,&pos,refe); // vai procurar a posição do deputado e vai receber a posição do partido por parametro, como os codigos de deputados tem de ser diferentes dá para fazer desta maneira, poupando trabalho
        if(pog!=-1)
        {
            if(parlamento[pot].partidos[pos].deputados[pog].genero=='F')    //temos de ter em atenção o sexo do deputado, porque se eliminar um deputado temos de reduzir o numero do sexo
            {
                parlamento[pot].partidos[pos].fe--;
            }
            else
            {
                    parlamento[pot].partidos[pos].ma--;
            }
            for (j=pog;j<parlamento[pot].partidos[pos].quantdeputados;j++)
                parlamento[pot].partidos[pos].deputados[j]=parlamento[pot].partidos[pos].deputados[j+1];    // o deputado na posição n vai ser igual ao deputado da posição n+1, eliminando o da posição n
            parlamento[pot].partidos[pos].quantdeputados--; //o numero de deputados vai reduzir
        }
        else
            printf("\7\n\ncódigo errado\n");
        }
else
    printf("\7\n\nParlamento não encontrado\n");
}
