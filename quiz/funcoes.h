#include "tabdispersao.h"
#include "vetor.h"
#include "heap.h"

void encripta_string(char *string);

void desincripta_string(char *string);

void texto_centra();

void print_ajuda();

void mostra_erradas(vetor *perguntas, int *numero_erradas, char* alinea_correta);

int escolhe_perguntas(vetor *perguntas, int numero_da_pergunta);

void imprime_perguntas(vetor *perguntas, int nivel);

vetor* importa_perguntas(int *num_de_niveis);

void manda_pontu_ficheiro(int nivel);

heap* ler_pontu_ficheiro(int nivel);

void ler_para_tabela();

char imprime_top_score(heap *top_score1, heap *top_score2);



void menu_login_ou_registo();

void menu_print_nivel(int n);

void menu_print_inicial();

int menu_escolha_login_registo();

void menu_escolha_nivel(vetor* perguntas, int n);

void menu_escolha_incial();

void pedir_pass(char *pass);


int novo_jogador(tabela_dispersao *jogadores);

int valida_jogador(tabela_dispersao *jogadores);





