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
int procurarparl(tparlamento v[],int n,char text[]){    //vai procurar a posi�ao do parlamento que o utilizador inseriu
int i,pos,flag=1;
for(i=0;i<n && flag;i++){
    if(strcmp(v[i].pais,text)==0){      //strcmp = vai comparar se no parlamento.pais vai ter o parlamento que foi escrito num ciclo for
        flag=0;     // se for igual, vai atribuir a flag o valor de 0 e vai sair do ciclo for
        pos=i;}}
if (flag)       //se flag n�o for 0(o texto nao for igual ao parlamento.pais) vai returnar o -1
    return -1;
else
    return pos;}        // sen�o vai returnar o valor da posi��o em que o pais � igual ao que o utilizador escreveu
int procurarpar2(tparlamento v[],int pot,char text[]){  //vai procurar a posi��o da sigla que o utilizador inseriu
int i,pos,flag=1;
for(i=0;i<v[pot].quantpartidos && flag;i++){
    if(strcmp(v[pot].partidos[i].sigla,text)==0){   //strcmp = vai comparar se no parlamento.partidos.sigla vai ter a sigla que foi escrito num ciclo for
        flag=0;     //procedimento igual � fun��o de cima
        pos=i;}}
if (flag)
    return -1;
else
    return pos;}
int procurarpar3(tparlamento v[],int pos,int *pot,char text[]){ //vai procurar a posi�ao do codigo que o utilizador inseriu e vai returnar tambem a posi��o em que o partido se encontra
int i,j,pog,flag=1;
for(j=0;j<v[pos].quantpartidos&&flag;j++)
{
    for(i=0;i<v[pos].partidos[j].quantdeputados && flag;i++){
        if(strcmp(v[pos].partidos[j].deputados[i].codigo,text)==0){     //compara o codigo dos deputados com o codigo que o utilizador escreveu, dizendo se j� existe esse codigo ou nao
            *pot=j;
            flag=0;
            pog=i;}}
}
    if (flag)
        return -1;
    else{
        return pog;}}
int procurarpar4(tparlamento v[],int pos,int pot,char text[]){  //vai procurar a posi�ao do
int i,j,pog,flag=1;
    for(i=0;i<v[pos].partidos[pot].quantdeputados && flag;i++){
        if(strcmp(v[pos].partidos[pot].deputados[i].codigo,text)==0){   // vai comprar se o codigo dos deputados da struct � igual ao que o utilizador escreveu
            flag=0;
            pog=i;}}
    if (flag)
        return -1;
    else{
        return pog;}
}
int procurarpar5(tparlamento v[],int pos,char text[]){  //vai procurar a posi�ao da sigla do partido que o utilizador inseriu
int i,j,pog,flag=1;
for(j=0;j<v[pos].quantpartidos&&flag;j++)
{
    if(strcmp(v[pos].partidos[j].sigla,text)==0){       //vai comparar se a sigla dos partidos � igual � sigla que o utilizador escreveu
        flag=0;
        pog=j;}}
    if (flag)
        return -1;
    else{
        return pog;}}
