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
void selecionarparlamento(tparlamento parlamento[],int *n){
int pos;
char refe[MAX2];      //criamos um vetor
mparldisponiveis(parlamento,n);    //chama uma função que mostra os parlamentos existentes
printf("\nQual o parlamento que deseja visualizar:  ");
scanf("%s",&refe);      //scanf para o vetor que criamos para depois verificar se existe ou nao esse parlamento
pos=procurarparl(parlamento,*n,refe);       //verifica se existe ou não esse parlamento
if(pos!=-1)
    mostrar1(parlamento,n,pos);
else        //a função vai returnar um valor de -1, vai saltar a função if e i´ra ser mostrado a mensaghem seguinte
    printf("\7\nParlamento não encontrado\n");
}
void selecionarpartido(tparlamento parlamento[],int *n){//mostra o partido caso o utilizador escolha um parido existente
int pos,pot,i,j;
char refe[MAX2];
mparldisponiveis(parlamento,n);     //mostra os parlamentos existentes
printf("\n\nQual o nome parlamento do partido que deseja visualizar ");
scanf("%s",&refe);
pot=procurarparl(parlamento,*n,refe);//da a posiçao do parlamento
if (pot!=-1)
{
    mpartdisponiveis(parlamento,n,pot);     //mostra os partidos existentes
    printf("\n\nQual o partido que deseja visualizar  ");
    scanf("%s",&refe);
    strupr(refe);       //converte a string em maisculo
    pos=procurarpar2(parlamento,pot,refe);      //vai procurar a posição com pot=posição do parlamento, refe= partido que quer visualizar
    if(pos!=-1)     // se o valor returnado anteriormente pela função for diferente de -1
        mostrar2(parlamento,n,pot,pos);     //vai mostrar com pos= valor returnado pela função anterior
    else
        printf("\7\nPartido não encontrado\n");
}
else
    printf("\7\nParlamento não encontrado\n");
}
void selecionardeputado(tparlamento parlamento[],int *n){
char refe[MAX2];
int pot,pos,pog,x,c;
pos=0;
mparldisponiveis(parlamento,n);
printf("\n\nQual o nome do parlamento em que o deputado se encontra  ");
scanf("%s",&refe);
pot=procurarparl(parlamento,*n,refe);//da a posiçao do parlamento
if (pot!=-1)
{
    system("cls");
    mdepudespo(parlamento,pot);     // mostrar os deputados existentes | nome   codigo |
    printf("\t\n\nQuantos deputados deseja visualizar? ");
    scanf("%d",&c);
    for(x=0;x<c;x++){

        mdepudespo(parlamento,pot);     // mostrar os deputados existentes | nome   codigo |
        printf("\n\nQual o código do deputado que deseja visualizar  ");
        scanf("%s",&refe);
        pog=procurarpar3(parlamento,pot,&pos,refe);
        if(pog!=-1)
        {
            //printf("%d\t%d\t\n",pos,pog);//teste apenas para se der algum erro
            mostrar3(parlamento,pot,pos,pog);
            printf("\n\n\7************************************************************************\n\n");
            printf("Prima uma tecla para continuar a visualizar mais deputados ou para sair\n\n");
            printf("************************************************************************\n\n");
            }
        else
            printf("\n\7Deputado nao encontrado\n");
            system("PAUSE");

    }
}
else
    printf("\n\7Parlamento nao encontrado");
}

