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
void inserirparlamento(tparlamento parlamento[],int *n){
int j,k,pog,pos,pot;
char refe[MAX2];
printf("\nNome do parlamento\n");
scanf("%s",&parlamento[*n].pais);   // vai ler o parlamento e vai mandar para o parlamento.pais
fflush(stdin);
do{printf("\nNúmero de partidos (min.3):\n");
scanf("%d",&parlamento[*n].quantpartidos);}while(parlamento[*n].quantpartidos <3);  // fazer a validação, no minimo 3 partidos
for(j=0;j<parlamento[*n].quantpartidos;j++) //j=0; j menor que numero de partidos acima indicados
{
    printf("\nPartido\n\tnome: ");
    scanf("%s",&parlamento[*n].partidos[j].nome);   //começar com j=0, para inserir na primeira posição, em seguida na segunda...
    printf("\n\tSigla: ");
    scanf("%s",&refe);
    strupr(refe);       //converte a string em maisculo
    pog=procurarpar5(parlamento,*n,refe);       // verificar se já existe essa sigla
    while(pog!=-1)
    {
        printf("\7Já existe um partido com esta sigla\nInsira outra sigla ");
        scanf("%s",&refe);
        strupr(refe);       //converte a string em maisculo
        pog=procurarpar5(parlamento,*n,refe);
    }
    strcpy(parlamento[*n].partidos[j].sigla,refe);  // vai copiar o refe (sigla) para a zona da sigla nos partidos
    do{printf("\n\tNúmero de deputados (min.4): ");
    scanf("%d",&parlamento[*n].partidos[j].quantdeputados);}while(parlamento[*n].partidos[j].quantdeputados <4);
    fflush(stdin);
    for(k=0;k<parlamento[*n].partidos[j].quantdeputados;k++)
    {
        printf("\t\nDeputados do %s\n",parlamento[*n].partidos[j].sigla);   //vai mostrar a sigla do partido que estamos a inserir
        printf("\tNome: ");
        scanf("%s",&parlamento[*n].partidos[j].deputados[k].nome);
        fflush(stdin);
        printf("\n\tcodigo do deputado: ");
        scanf("%s",&refe);
        fflush(stdin);
        pot=procurarpar3(parlamento,*n,&pot,refe);  // vai procurar se ja existe esse codigo em algum deputado
        while(pot!=-1)
        {
            printf("\7**Já existe um deputado com esse código**\nInsira outro código  ");
            scanf("%s",&refe);
            fflush(stdin);
            pot=procurarpar3(parlamento,*n,&pot,refe);  //vai procurar de novo se existe o mesmo codigo
        }
        printf("\n\tSexo: ");
        validarsexoecontarfm(parlamento,n,*n,j,k);  //validar o sexo
        fflush(stdin);
        printf("\n\tZona: ");
        scanf("%s",&parlamento[*n].partidos[j].deputados[k].circulo);   // vai mandar a string para o circulo dos deputados
        strcpy(parlamento[*n].partidos[j].deputados[k].codigo,refe);    //copiar o código para o codigo dos deputados
    }
}
printf("\nParlamento de %s foi inserido com exito\n",&parlamento[*n].pais);
*n=*n+1;    // vai aumentar o numero de parlamentos
}
void inserirpartido(tparlamento parlamento[],int *n){
char refe[MAX2];
int pos,ppart,k,pog,l,por;
mparldisponiveis(parlamento,n); // vai mostrar o parlamentos disponiveis
printf("\n\nDigite o nome do parlamento em que deseja inserir partidos\n");
scanf("%s",&refe);
pos=procurarparl(parlamento,*n,refe);//procura o parlamento para ver a sua posição, se nao encontrar atribui o valor de -1 e nao entra no if
if(pos!=-1)
{
ppart=parlamento[pos].quantpartidos;// ppart é o numero de partidos do parlamento
printf("\nPartido\n\tnome: ");
scanf("%s",&parlamento[pos].partidos[ppart].nome);  //vai inserir na posição em que termina os outros partidos
printf("\n\tSigla: ");
scanf("%s",&refe);
strupr(refe);       //converte a string em maisculo
pog=procurarpar5(parlamento,pos,refe);  // vai procurar se já existe a sigla
while(pog!=-1)
{
    printf("\7Já existe um partido com esta sigla\nInsira outra sigla ");
    scanf("%s",&refe);
    strupr(refe);       //converte a string em maisculo
    pog=procurarpar5(parlamento,pos,refe);  //vai procurar de novo para verificar
}
strcpy(parlamento[pos].partidos[ppart].sigla,refe); //vai copiar a sigla para dentro das siglas dos partidos na posição que inseriu
do{printf("\n\tNúmero de deputados (min.4): ");
scanf("%d",&parlamento[pos].partidos[ppart].quantdeputados);}while(parlamento[pos].partidos[ppart].quantdeputados <4);
for(k=0;k<parlamento[pos].partidos[ppart].quantdeputados;k++)
{
    printf("\t\nDeputados do %s\n",parlamento[pos].partidos[ppart].sigla);
    fflush(stdin);
    printf("\tNome: ");
    scanf("%s",&parlamento[pos].partidos[ppart].deputados[k].nome);
    fflush(stdin);
    printf("\n\tCódigo do deputado: ");
    scanf("%s",&refe);
    por=procurarpar3(parlamento,pos,&l,refe);   //vai procurar se já existe esse código
    while(por!=-1)
    {
        fflush(stdin);
        printf("\7\nEste código já existe\nInsira outro código ");
        scanf("%s",&refe);
        por=procurarpar3(parlamento,pos,&l,refe);   //vai procurar de novo para verificar
    }
    fflush(stdin);
    printf("\n\tSexo: ");
    validarsexoecontarfm(parlamento,n,pos,ppart,k); // vai validar o sexo, se for valido vai inserir na posição que se quer
    fflush(stdin);
    printf("\n\tZona: ");
    scanf("%s",&parlamento[pos].partidos[ppart].deputados[k].circulo);
    strcpy(parlamento[pos].partidos[ppart].deputados[k].codigo,refe);   //vai copiar o codigo anteriormente escrito para a zona dos codigos dos deputados
}
printf("\n*Partido inserido com sucesso*\n");
parlamento[pos].quantpartidos=ppart+1;  //vai aumentar o numero de partidos, ppart era o numero de partidos, então vai aumentar 1
}
else
    printf("\7\n\nParlamento não encontrado\n");
}
void inserirdepu(tparlamento parlamento[],int *n){
mparldisponiveis(parlamento,n);
char refe[MAX2];
int pot,pos,pog,j,k,i;
printf("\n\nQual o nome do parlamento em que quer inserir o deputado ");
scanf("%s",&refe);
pot=procurarparl(parlamento,*n,refe);//da a posiçao do parlamento
if (pot!=-1)
{
    mpartdisponiveis(parlamento,n,pot);     // mostrar os partidos disponiveis
    printf("\n\nQual o partido que quer inserir o deputado ");
    scanf("%s",&refe);
    pos=procurarpar2(parlamento,pot,refe);  //vai procurar se existe esse partido
    if(pos!=-1)
    {
    k=parlamento[pot].partidos[pos].quantdeputados;     //vai returnar a posiçao desse partido para se poder utilizar
    printf("\t\nDeputados do %s\n",parlamento[pot].partidos[pos].sigla);        // mostra a sigla do partido
    fflush(stdin);
    printf("\tNome: ");
    scanf("%s",&parlamento[pot].partidos[pos].deputados[k].nome);
    fflush(stdin);
    printf("\n\tCódigo do deputado: ");
    scanf("%s",&refe);
    pog=procurarpar4(parlamento,pot,pos,refe);  // vai procurar se já existe esse codigo
    while(pog!=-1)  //se ja existir vai para o ciclo
    {
        fflush(stdin);
        printf("\7\nEste código já existe\n Insira outro código ");
        scanf("%s",&refe);
        pog=procurarpar4(parlamento,pot,pos,refe);      //vai verificar se ja existe novamente
    }
    fflush(stdin);
    printf("\n\tSexo: ");
    validarsexoecontarfm(parlamento,n,pot,pos,k);       //validar o sexo
    fflush(stdin);
    printf("\n\tZona: ");
    scanf("%s",&parlamento[pot].partidos[pos].deputados[k].circulo);
    strcpy(parlamento[pot].partidos[pos].deputados[k].codigo,refe); // vai copiar o codigo para a zona do codigo dos deputados
    parlamento[pot].partidos[pos].quantdeputados++;     // vai aumentar o numero de deputados
    }
    else
        printf("\7\nPartido não encontrado");
}
else
    printf("\7\nParlamento não encontrado");
}
void inserirpartidocasoerro(tparlamento parlamento[],int *n,int pos){   // vai inserir numa determinada posição, utilizadas no main, caso haja menos de 3 partidos
char refe[MAX2];  //código praticamente igual aos de cima, apenas já sabemos a posição em que temos de inserir num determinado parlamento
int ppart,k,pog,l,por;
ppart=parlamento[pos].quantpartidos;
printf("\nPartido\n\tnome: ");
scanf("%s",&parlamento[pos].partidos[ppart].nome);
printf("\n\tSigla: ");
scanf("%s",&refe);
strupr(refe);
pog=procurarpar5(parlamento,pos,refe);
while(pog!=-1)
{
    printf("\7\nJá existe um partido com esta sigla\nInsira outra ");
    scanf("%s",&refe);
    strupr(refe);
    pog=procurarpar5(parlamento,pos,refe);
}
strcpy(parlamento[pos].partidos[ppart].sigla,refe);
do{printf("\n\tNúmero de deputados (min.4): ");
    scanf("%d",&parlamento[pos].partidos[ppart].quantdeputados);}while(parlamento[pos].partidos[ppart].quantdeputados <4);
for(k=0;k<parlamento[pos].partidos[ppart].quantdeputados;k++)
{
    printf("\t\nDeputados do %s\n",parlamento[pos].partidos[ppart].sigla);
    fflush(stdin);
    printf("\tNome:" );
    scanf("%s",&parlamento[pos].partidos[ppart].deputados[k].nome);
    fflush(stdin);
    printf("\n\tCódigo do deputado: ");
    scanf("%s",&refe);
    por=procurarpar3(parlamento,pos,&l,refe);
    while(por!=-1)
    {
        fflush(stdin);
        printf("\7\nEste deputado já existe\nInsira outro ");
        scanf("%s",&refe);
        por=procurarpar3(parlamento,pos,&l,refe);
    }
    fflush(stdin);
    printf("\n\tSexo: ");
    validarsexoecontarfm(parlamento,n,pos,ppart,k);
    fflush(stdin);
    printf("\n\tZona: ");
    scanf("%s",&parlamento[pos].partidos[ppart].deputados[k].circulo);
    strcpy(parlamento[pos].partidos[ppart].deputados[k].codigo,refe);
}
printf("\n*Partido inserido com sucesso*\n");
parlamento[pos].quantpartidos=ppart+1;
}
void depucasoerro(tparlamento parlamento[],int *n,int pot,int pos){     // vai inserir numa determinada posição, utilizadas no main, caso haja menos de 4 deputados
char refe[MAX2];      // codigo igual aos de cima, apenas já sabemos a posição do partido que falta deputados
int pog,j,k,i;
    k=parlamento[pot].partidos[pos].quantdeputados;
    printf("\t\nDeputados do %s\n",parlamento[pot].partidos[pos].sigla);
    fflush(stdin);
    printf("\tNome: ");
    scanf("%s",&parlamento[pot].partidos[pos].deputados[k].nome);
    fflush(stdin);
    printf("\n\tCódigo do deputado: ");
    scanf("%s",&refe);
    pog=procurarpar4(parlamento,pot,pos,refe);
    while(pog!=-1)
    {
        fflush(stdin);
        printf("\7\nEste deputado já existe\nInsira outro ");
        scanf("%s",&refe);
        pog=procurarpar4(parlamento,pot,pos,refe);
    }
    fflush(stdin);
    printf("\n\tSexo: ");
    validarsexoecontarfm(parlamento,n,pot,pos,k);
    fflush(stdin);
    printf("\n\tZona: ");
    scanf("%s",&parlamento[pot].partidos[pos].deputados[k].circulo);
    strcpy(parlamento[pot].partidos[pos].deputados[k].codigo,refe);
    parlamento[pot].partidos[pos].quantdeputados++;
    }
