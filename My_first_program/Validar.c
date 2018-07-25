#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
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
void validarsexoecontarfm(tparlamento parlamento[],int *n,int pos,int ppart,int k){        //pos posiçao do parlamento, ppart posiçao do partido, k posiçao do deputado
char sx;
fflush(stdin);
sx=getchar();       //scanf próprio para caracteres
sx=toupper(sx);     //transforma em maiscula
while(sx != 'F' &&sx!='M')      //validação, não aceita letras diferentes de 'F' e 'M'
{
    fflush(stdin);
    printf("\7Opcão errada insira novamente: ");
    sx=getchar();
    sx=toupper(sx);     //transforma em maiuscula
}
if(sx=='F')     // se letra=F ---> aumenta o numero de mulheres
    parlamento[pos].partidos[ppart].fe++;
if(sx=='M')     // se letra?M ---> aumenta o numero de homens
    parlamento[pos].partidos[ppart].ma++;
parlamento[pos].partidos[ppart].deputados[k].genero=sx;     // vai colocar o sexo no vetor do genero em um determinado deputado
}
int detetarparlamentomenos3(tparlamento parlamento[],int *n,int *pos){ //recebe o endereço do n(numero de parlamento) e pos (variavel criada)
int i,flag=1;
for(i=0;i<*n&&flag;i++)
{
    if(parlamento[i].quantpartidos<3)       // se quantidade de partidos menor que 3 flag=0, vai avisar que precisa de mais partidos (há um ciclo "while" no main, se for ==0 vai mandar o utilizador inserir mais partidos)
    {
        flag=0;
        *pos=i;  // vai alterar o valor de pos
    }
}
return flag; // retorna o valor de 0 ou 1
}
int detetardepumenos4(tparlamento parlamento[],int *n,int *pos,int *pot){//recebe o endereço do n(numero de parlamento) e pos (variavel criada anteriormente já com um valor) e pot(variavel sem valor)
int i,j,flag=1;
for(i=0;i<*n&&flag;i++)
{
    for(j=0;j<parlamento[i].quantpartidos;j++)
    {
        if(parlamento[i].partidos[j].quantdeputados<4)  // se a quantidade de deputados for menor que 4 flag=0, para depois avisar o utiliador que precisa de mais deputados
        {
            flag=0;
            *pos=i;  //altera o valor de pos
            *pot=j;  //altera o valor de pot
        }
    }
}
return flag; //retorna o valor 0 ou 1
}

