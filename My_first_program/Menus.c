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
    op=getchar(); //mesma função que o scanf, uma função própria para receber caracteres
    op=toupper(op); //Converte caracter minúsculo em maiúsculo
    system("cls");  // Limpa a tela
return op;}
char menuparlamento(){//menu
    char nop;
    printf("\n\t\t\t******************************************************************************\n");
    printf("\n\t\t\t*          I = Se pretender inserir informação do parlamento                  *\n");
    printf("\n\t\t\t*          M= Se pretender mostrar informação do parlamento                   *\n");
    printf("\n\t\t\t*          E= Se pretender eliminar informação do parlamento                  *\n");
    printf("\n\t\t\t*     T= Se pretender visualizar o total de partidos do parlamento            *\n");
    printf("\n\t\t\t*   P= Total e média de deputados do sexo feminino existentes no parlamento   *\n");
    printf("\n\t\t\t*          V= Se pretender returnar ao menu principal                         *\n");
    printf("\n\t\t\t******************************************************************************\n");
    fflush(stdin);  //limpar o buffer
    nop=getchar(); //mesma função que o scanf, uma função própria para receber caracteres
    nop=toupper(nop); //Converte caracter minúsculo em maiúsculo
    return nop;}
char menupartidos(){//menu
    char op; // op= valor que vai ser introduzido pelo utilizador
    printf("\n\t\t\t**************************************************************************\n");
    printf("\n\t\t\t*           I= Se pretender inserir informação do partido                *\n");
    printf("\n\t\t\t*           M= Se pretender mostrar informação do partido                *\n");
    printf("\n\t\t\t*           E= Se pretender eliminar informação do partido               *\n");
    printf("\n\t\t\t*  R= Mostrar a percentagem de deputados que tem um determinado partido  *\n");
    printf("\n\t\t\t*           L= Mostrar o partido mais votado e o menos votado            *\n");
    printf("\n\t\t\t*           V= Se pretender voltar ao menu principal                     *\n");
    printf("\n\t\t\t**************************************************************************\n");
    fflush(stdin);  //limpar o buffer
    op=getchar();  //mesma função que o scanf, uma função própria para receber caracteres
    op=toupper(op);  //Converte caracter minúsculo em maiúsculo
return op;}
char menudeputados(){//menu
    char op; // op= valor que vai ser introduzido pelo utilizador
    printf("\n\t\t\t***************************************************************\n");
    printf("\n\t\t\t*         I = Se pretender inserir informação dos deputados   *\n");
    printf("\n\t\t\t*         M= Se pretender mostrar informação dos deputados    *\n");
    printf("\n\t\t\t*         E= Se pretender eliminar informação dos deputados   *\n");
    printf("\n\t\t\t*         V= Se pretender voltar ao menu principal            *\n");
    printf("\n\t\t\t***************************************************************\n");
    fflush(stdin);
    op=getchar();
    op=toupper(op);
return op;}

// a partir de agora vai pegar nas variaveis de cima para saber qual função vai chamar

char menuavaliarescolha1(char op){//decide entre inserir eliminar e mostrar
char nop;
switch(op){  //função mais simples para fazer um menu
    case 'P':{  // case, somente são aceites valores constantes
           nop=menuparlamento();
           break;} // termina a execução do switch e o programa continua a executar na instrução seguinte
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
        printf("\n\7opção errada!");
    }
    return nop;} // vai returnar um valor, que será utilizado na função "concretizar"
void concretizar(char op,char nop,tparlamento parlamento[],int *n){//n - recebe o tamanho do vetor parlamento por parametro

switch(op){         // em cada case irá decidir que função vai chamar, dependendo das opções introduzidas anteriormente
case 'P':       //ao longo desta função vai chamar diferentes função, de acordo com a letra que o utilizador escolhe
{
    switch(nop){
    case 'V':
        {
            rebot(parlamento,n);        //vai repetir o processo, vai voltar para o menu principal
            break;
        }
    case 'I':
        {
           inserirparlamento(parlamento,n);     //chama a função inserir parlamento com o n por parametro(numero de partido)
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
        printf("\n\7opção errada!");

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
        printf("\n\7opção errada!");

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
            printf("\n\7opção errada!");
                }}
                }

    }
