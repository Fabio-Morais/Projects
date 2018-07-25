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
void mparldisponiveis(tparlamento parlamento[],int *n){//mostra a lista dos parlamentos desponiveis
int j,pos;
system("cls");
            printf("Existe os seguintes parlamentos na lista:  ");
            for(j=0;j<*n;j++)
            printf("  \n->%s\n", parlamento[j].pais);}      //mostrar os parlamentos que existe até ao n(numero de parlamentos)
void mpartdisponiveis(tparlamento parlamento[],int *n,int pot){//mostra lista de partidos disponiveis
int j;
system("cls");
printf("Existe os seguintes partidos na lista:  ");
for(j=0;j<parlamento[pot].quantpartidos;j++)
printf("  \n->%s\n", parlamento[pot].partidos[j].sigla);        //mostra lista de partidos disponiveis (a sigla)
}
void mdepudespo(tparlamento parlamento[],int pot){//mostra a lista de deputados
int j,i;
system("cls");
printf("Existe os seguintes deputados na lista:  ");
for (i=0;i<parlamento[pot].quantpartidos;i++)       //pot=posição do parlamento
{
    printf("\n================================\n");
    printf("%s\n",parlamento[pot].partidos[i].nome);
    printf("================================\n");
for(j=0;j<parlamento[pot].partidos[i].quantdeputados;j++)
    printf(" ->%s:---------------------%s\n", parlamento[pot].partidos[i].deputados[j].nome,parlamento[pot].partidos[i].deputados[j].codigo);    //mostra o nome dos deputados e o codigo
}}
void mostrar1(tparlamento parlamento[], int n,int pos){//mostra tudo o que tem num certo parlamento
    int i,j,k,n1,n2;
    i=pos;
        system("cls");
        printf("\n\t\t\t     Parlamento de %s\n\n\n",parlamento[i].pais);// mostra pais
        n1=parlamento[i].quantpartidos;//atribui a n1 a quantidade de partidosdo parlamento em questao
        for(j=0;j<n1;j++){      //mostra os partidos (nome,sigla,quantidade de deputados)
            printf("=======================================================================================");
            printf("\n-->Partido\n\tnome: %s ", parlamento[i].partidos[j].nome);
            printf("\tsigla: %s", parlamento[i].partidos[j].sigla);
            printf("\tnumero de deputados: %d\n ", parlamento[i].partidos[j].quantdeputados);
            printf("=======================================================================================");
            n2=parlamento[i].partidos[j].quantdeputados;//atribui a n2 a quantidade de deputados do parlamento
            for(k=0;k<n2;k++){      //mostra os deputados (nome,codigo,genero,circulo)
                printf("\t\nDeputados do %s\n\t%s",parlamento[i].partidos[j].sigla,parlamento[i].partidos[j].deputados[k].nome);
                printf("\tcodigo: %s", parlamento[i].partidos[j].deputados[k].codigo);
                printf("\t\tSexo: %c", parlamento[i].partidos[j].deputados[k].genero);
                printf("\t\tZona: %s\n", parlamento[i].partidos[j].deputados[k].circulo);}}}
void mostrar2(tparlamento parlamento[], int n,int pot,int pos){//mostra tudo de um certo partido
int i,j,k,n1,n2;
i=pot;
j=pos;
        system("cls");
        printf("\n----Parlamento de %s----\n",parlamento[i].pais);// mostra pais
        printf("=======================================================================================");
        printf("\n\tPartido\n\tnome: %s", parlamento[i].partidos[j].nome);
        printf("\tsigla:%s", parlamento[i].partidos[j].sigla);
        printf("\tnumero de deputados: %d\n", parlamento[i].partidos[j].quantdeputados);
        printf("=======================================================================================");
        n2=parlamento[i].partidos[j].quantdeputados;//atribui a n2 a quantidade de deputados do parlamento
        for(k=0;k<n2;k++){      //mostra os deputados
            printf("\t\nDeputados do %s\n\t     %s",parlamento[i].partidos[j].sigla,parlamento[i].partidos[j].deputados[k].nome);
            printf("\tcodigo: %s", parlamento[i].partidos[j].deputados[k].codigo);
            printf("\t\tSexo: %c", parlamento[i].partidos[j].deputados[k].genero);
            printf("\t\tZona: %s\n", parlamento[i].partidos[j].deputados[k].circulo);}}
void mostrar3(tparlamento parlamento[],int i,int j,int k){      //Mostra apenas informação dos deputados

printf("\t\nDeputados do %s\n\t%s",parlamento[i].partidos[j].sigla,parlamento[i].partidos[j].deputados[k].nome);
printf("\tcodigo: %s", parlamento[i].partidos[j].deputados[k].codigo);
printf("\t\tSexo: %c", parlamento[i].partidos[j].deputados[k].genero);
printf("\t\tZona: %s\n", parlamento[i].partidos[j].deputados[k].circulo);}

