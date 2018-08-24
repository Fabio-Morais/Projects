#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "vetor.h"
#include "heap.h"
#include "tabdispersao.h"
#include <locale.h>
tabela_dispersao *jogadores;
int main()
{
    system("mode con:cols=70 lines=20");
    int x, n=1;
    char ch,teclacodevl, senha[30]="123fabiotesteOLA14", tecla;
    jogadores =tabela_nova(30, hash_djbm);
    heap *top_score1,*top_score2;
    setlocale(LC_ALL,"");
    ler_para_tabela();


    menu_login_ou_registo();
    x=menu_escolha_login_registo();

    printf("\n->%d\n\n", x);
//    mostraTabela(jogadores);

    if(x!=1)
    {
        printf("\nerro\n");
        return 0;
    }
    do{
    system("mode con:cols=100 lines=20");
    menu_print_inicial();
    menu_escolha_incial();

    vetor *perguntas= importa_perguntas(&n);

   menu_print_nivel(n);
   menu_escolha_nivel(perguntas, n);
    imprime_perguntas(perguntas,1);

/** armazenar numero de niveis existentes numa variavel **/
    top_score1=ler_pontu_ficheiro(1);
    top_score2=ler_pontu_ficheiro(2);


    tecla=imprime_top_score(top_score1, top_score2);
    }while(tecla=='y');
    system("cls");
    printf("OBRIGADO POR JOGAR O JOGO\n\n\n\tRealizado por Fábio Morais\n\n\n");
    system("PAUSE");
    heap_apaga(top_score1);
    heap_apaga(top_score2);
//    vetor_apaga(perguntas);
//    tabela_apaga(jogadores);
    return 0;
}
