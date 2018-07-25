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
char menuprincipal(){//menu principal
    char op; // op= valor que vai ser introduzido pelo utilizador
    system("cls");
    system("color 0A");
    printf("\n\t\t\t**********************************************************\n");
    printf("\n\t\t\t*\tP= Se pretender aceder ao menu do parlamento\t*\n");
    printf("\n\t\t\t*\tA= Se pretender aceder ao menu dos partidos\t*\n");
    printf("\n\t\t\t*\tD= Se pretender aceder ao menu dos deputados\t*\n");
    printf("\n\t\t\t**********************************************************\n");
    fflush(stdin); //limpar o buffer
    op=getchar(); //mesma fun��o que o scanf, uma fun��o pr�pria para receber caracteres
    op=toupper(op); //Converte caracter min�sculo em mai�sculo
    system("cls");  // Limpa a tela
return op;}
char menuparlamento(){//menu
    char nop;
    printf("\n\t\t\t******************************************************************************\n");
    printf("\n\t\t\t*          I = Se pretender inserir informa��o do parlamento                  *\n");
    printf("\n\t\t\t*          M= Se pretender mostrar informa��o do parlamento                   *\n");
    printf("\n\t\t\t*          E= Se pretender eliminar informa��o do parlamento                  *\n");
    printf("\n\t\t\t*     T= Se pretender visualizar o total de partidos do parlamento            *\n");
    printf("\n\t\t\t*   P= Total e m�dia de deputados do sexo feminino existentes no parlamento   *\n");
    printf("\n\t\t\t*          V= Se pretender returnar ao menu principal                         *\n");
    printf("\n\t\t\t******************************************************************************\n");
    fflush(stdin);  //limpar o buffer
    nop=getchar(); //mesma fun��o que o scanf, uma fun��o pr�pria para receber caracteres
    nop=toupper(nop); //Converte caracter min�sculo em mai�sculo
    return nop;}
char menupartidos(){//menu
    char op; // op= valor que vai ser introduzido pelo utilizador
    printf("\n\t\t\t**************************************************************************\n");
    printf("\n\t\t\t*           I= Se pretender inserir informa��o do partido                *\n");
    printf("\n\t\t\t*           M= Se pretender mostrar informa��o do partido                *\n");
    printf("\n\t\t\t*           E= Se pretender eliminar informa��o do partido               *\n");
    printf("\n\t\t\t*  R= Mostrar a percentagem de deputados que tem um determinado partido  *\n");
    printf("\n\t\t\t*           L= Mostrar o partido mais votado e o menos votado            *\n");
    printf("\n\t\t\t*           V= Se pretender voltar ao menu principal                     *\n");
    printf("\n\t\t\t**************************************************************************\n");
    fflush(stdin);  //limpar o buffer
    op=getchar();  //mesma fun��o que o scanf, uma fun��o pr�pria para receber caracteres
    op=toupper(op);  //Converte caracter min�sculo em mai�sculo
return op;}
char menudeputados(){//menu
    char op; // op= valor que vai ser introduzido pelo utilizador
    printf("\n\t\t\t***************************************************************\n");
    printf("\n\t\t\t*         I = Se pretender inserir informa��o dos deputados   *\n");
    printf("\n\t\t\t*         M= Se pretender mostrar informa��o dos deputados    *\n");
    printf("\n\t\t\t*         E= Se pretender eliminar informa��o dos deputados   *\n");
    printf("\n\t\t\t*         V= Se pretender voltar ao menu principal            *\n");
    printf("\n\t\t\t***************************************************************\n");
    fflush(stdin);
    op=getchar();
    op=toupper(op);
return op;}

// a partir de agora vai pegar nas variaveis de cima para saber qual fun��o vai chamar

char menuavaliarescolha1(char op){//decide entre inserir eliminar e mostrar
char nop;
switch(op){  //fun��o mais simples para fazer um menu
    case 'P':{  // case, somente s�o aceites valores constantes
           nop=menuparlamento();
           break;} // termina a execu��o do switch e o programa continua a executar na instru��o seguinte
    case 'A':
        {
           nop=menupartidos();
            break;
        }
    case 'D':
        {
            nop=menudeputados();
            break;
        }


    default:
        printf("\n\7op��o errada!");
    }
    return nop;} // vai returnar um valor, que ser� utilizado na fun��o "concretizar"
void concretizar(char op,char nop,tparlamento parlamento[],int *n){//n - recebe o tamanho do vetor parlamento por parametro

switch(op){         // em cada case ir� decidir que fun��o vai chamar, dependendo das op��es introduzidas anteriormente
case 'P':       //ao longo desta fun��o vai chamar diferentes fun��o, de acordo com a letra que o utilizador escolhe
{
    switch(nop){
    case 'V':
        {
            rebot(parlamento,n);        //vai repetir o processo, vai voltar para o menu principal
            break;
        }
    case 'I':
        {
           inserirparlamento(parlamento,n);     //chama a fun��o inserir parlamento com o n por parametro(numero de partido)
           break;
        }
    case 'M':
        {
            selecionarparlamento(parlamento,n);
            break;
        }
    case 'E':
        {
            eliminarparlamento(parlamento,n);break;
        }
    case 'T':
        {
            mostrarquantparti(parlamento,n);break;
        }
    case 'P':
        {
            mediadefeme(parlamento,n);break;
        }
    default:
        printf("\n\7op��o errada!");

    }
    break;
}
case 'A':
    {
    switch(nop){
    case 'V':
        {
            rebot(parlamento,n);break;
        }
    case 'I':
        {
            inserirpartido(parlamento,n);break;
        }
    case 'M':
        {
            selecionarpartido(parlamento,n);break;
        }
    case 'E':
        {
            eliminarpartido(parlamento,n);break;
        }
    case 'R':
        {
            precentdepu(parlamento,n);break;
        }
    case 'L':
        {
            mostrarpartmaisvot(parlamento,n);break;
        }
    default:
        printf("\n\7op��o errada!");

    }
    break;
}
case 'D':
    {
        switch(nop){
        case 'V':
            {
               rebot(parlamento,n);break;
            }
        case 'I':
            {
                inserirdepu(parlamento,n);break;
            }
        case 'M':
            {
                selecionardeputado(parlamento,n);break;
            }
        case 'E':
            {
                eliminardeputado(parlamento,n);break;}
        default:
            printf("\n\7op��o errada!");
                }}
                }

    }
