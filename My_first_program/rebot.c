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
void rebot(tparlamento parlamento[],int *n){//chama os menus e envia as respostas para a funçao concretizar
char op,nop;
system("cls");
op=menuprincipal();//Decide entre (parlamento, deputados e partidos) e vai retornar uma letra
nop=menuavaliarescolha1(op);//decide entre eliminar inserir ou mostrar (...) e vai retornar uma letra
concretizar(op,nop,parlamento,n); // função com os valores de cima, esta função vai decidir para que opção o utilizador quer ir
}
// função util para voltarmos ao menu principal sempre que quisermos
