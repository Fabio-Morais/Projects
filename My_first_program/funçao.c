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
void totaldepu(tparlamento parlamento[],int pos,int *totalmu,int *soma){//total de deputados do partido
int i;
*soma=0;    // soma e totalmu a 0 para podermos preencher
*totalmu=0;
for(i=0;i<parlamento[pos].quantpartidos;i++)    // i=0;i menor que quantidade de partidos
{
    *soma=*soma+parlamento[pos].partidos[i].fe+parlamento[pos].partidos[i].ma;  // vai somar as raparigas com os rapazes, para sabermos qauntidade de deputados existentes
    *totalmu=*totalmu+parlamento[pos].partidos[i].fe;}} // vai somar o numero de mulheres
int maiormenor(tparlamento parlamento[],int pos,char menor[],char maior[]){ //retorna um valor 0 se tiver a quantidade iguais, ou 1 se forem diferentes, vai retornar por parametro os vetores menor e maior
int j,maio,meno,flag=1,s;
s=parlamento[pos].quantpartidos;
strcpy(maior,parlamento[pos].partidos[0].sigla);    // vai copiar sigla do 1º partido para a vairavel maior
strcpy(menor,parlamento[pos].partidos[0].sigla);    // vai copiar sigla do 1º partido para a vairavel menor
maio=parlamento[pos].partidos[0].quantdeputados;    // vai atribuir a quantidade de deputados do 1º partido para a vairavel maio
meno=parlamento[pos].partidos[s].quantdeputados;    // vai atribuir a quantidade de deputados do ultimo partido para a vairavel meno
for(j=0;j<parlamento[pos].quantpartidos&&flag;j++){ // i=0; i < quantidade de partidos e se flag =0 sai fora
if(maio<parlamento[pos].partidos[j].quantdeputados) //vai comparar 1 a 1 qual é o maior, vai começar com o 1º a comparar com o 2º, o 2º com o 3º...etc
{
    maio=parlamento[pos].partidos[j].quantdeputados;    // se um determinado partido tiver uma quantidade maior de deputados que o anterior vai atribuir de novo à variavel maio o novo valor
    strcpy(maior,parlamento[pos].partidos[j].sigla);    //vai copiar também a sigla para o vetor maior para ser mostrado mais tarde.
}
else
{if(meno>parlamento[pos].partidos[j].quantdeputados)    // repetir os passos inversos do anterir
    {


    meno=parlamento[pos].partidos[j].quantdeputados;
    strcpy(menor,parlamento[pos].partidos[j].sigla);
    }
    else
        if(meno==maio)  //se houver os mesmo partidos, vai atribir a flag o valor de 0, esta vai sair do ciclo
        flag=0;
}
}
return flag;        // e retorna o valor da flag, flag=1 se nao for igual, flag=0 se forem iguais
}
void mostrarquantparti(tparlamento parlamento[],int *n){//imprime a quantidade de partidos
int pot;
char refe[MAX2];
mparldisponiveis(parlamento,n); // mostra os parlamentos disponiveis
printf("\n\nQual o nome do parlamento em que se encontra o partido que deseja visualizar ");
scanf("%s",&refe);
fflush(stdin);
pot=procurarparl(parlamento,*n,refe);   //procura a posiçao do parlamento que o utilizador escreveu
if(pot!=-1)
    printf("\n\t\t\t***O parlamento de %s tem %d partidos***\n\n",parlamento[pot].pais,parlamento[pot].quantpartidos);
else
    printf("\7\n\nNão existe esse parlamento\n");
}
void mostrarpartmaisvot(tparlamento parlamento[],int *n){//partido mais e menos votado
char refe[MAX2],refe1[MAX2],refe2[MAX2];
int pot,flag;
mparldisponiveis(parlamento,n); //mostra os parlamentos disponiveis
printf("\n\nQual o nome do parlamento deseja visualizar ");
scanf("%s",&refe);
pot=procurarparl(parlamento,*n,refe);//procura a posiçao do parlamento
if (pot!=-1)
{
    flag=maiormenor(parlamento,pot,refe1,refe2);    // flag vai ter os valores de 0 caso empate, ou 1 se nao empatarem
    if(flag)    //se flag for diferente de 0
        printf("\n\t\tO partido menos votado foi o %s e o mais votado foi o %s \n\n",refe1,refe2);   //refe1=menos votado, refe2= mais votado
    else
        printf("\n\nOs partidos empataram");
}
else
    printf("\7\n\nParlamento não encontrado\n");
}
void precentdepu(tparlamento parlamento[],int *n){//imprime a percentagem de deputados do partido no parlamento
int j,pos,pot;
float soma=0,pre;
char refe[MAX2];
mparldisponiveis(parlamento,n); // vai mostrar os parlamentos disponiveis
printf("\n\nQual o nome do parlamento em que o partido se encontra ");
scanf("%s",&refe);
pos=procurarparl(parlamento,*n,refe);       //procura a posiçao do parlamento
if(pos!=-1){
    for (j=0;j<parlamento[pos].quantpartidos;j++)
        soma=soma+parlamento[pos].partidos[j].quantdeputados;
    mpartdisponiveis(parlamento,n,pos); //mostrar partidos disponiveis
    printf("\nQual o partido que deseja visualizar ");
    scanf("%s",&refe);
    strupr(refe);       //converte a string em maisculo
    pot=procurarpar2(parlamento,pos,refe);
    if(pot!=-1){
        pre=(parlamento[pos].partidos[pot].quantdeputados/soma)*100;
        printf("\n\tA percentagem de deputados do %s é de %.2f %%  \n",parlamento[pos].partidos[pot].sigla,pre);     //%.2f = arredondar 2 casas decimais
    }       // %% = inserir o simbolo de percentagem
    else
        printf("\7\nPartido não encontrado\n");
    }
else
    printf("\7\n\nParlamento não encontrado\n");
}
void mediadefeme(tparlamento parlamento[],int *n){  //media das raparigas
char refe[MAX2];
int pos,j,d;
float media,mul,total;
mparldisponiveis(parlamento,n); //mostra os parlamentos disponiveis
printf("\n\nQual o nome parlamento que deseja visualizar ");
scanf("%s",&refe);
pos=procurarparl(parlamento,*n,refe);//da a posiçao do parlamento
if(pos!=-1){
    media=0;    // j= total de mulheres, d= soma de deputados
    totaldepu(parlamento,pos,&j,&d);        //para termos valores inteiros
    totaldepu(parlamento,pos,&mul,&total);  // vai mandar por parametro as variaveis, para serem alteradas na função|| <- para termos valores em float
    media=(mul/total)*100;  //media em float
    printf("\n\tExiste %d mulheres no parlamento de %s \n\n",j,parlamento[pos].pais);
    printf("\n\tA média de deputados do sexo feminino do parlamento de %s é de %.2f%% \n ",parlamento[pos].pais,media);
}
else
    printf("\7\nParlamento não encontrado");
}
