#include "tabdispersao.h"
#include "vetor.h"
#include "heap.h"

void encripta_string(char *string);

vetor* importa_perguntas();

void desincripta_string(char *string);

void texto_centra();

void menu_login_ou_registo();

void imprime_perguntas(vetor *perguntas, int nivel);

int escolhe_perguntas(vetor *perguntas, int numero_da_pergunta);


int menu_escolha_login_registo();

void pedir_pass(char *pass);

void menu_print_inicial();

void menu_escolha_incial();

int novo_jogador(tabela_dispersao *jogadores);

int valida_jogador(tabela_dispersao *jogadores);
