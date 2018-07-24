/*****************************************************************/
/*          Biblioteca vetor | PROG2 | MIEEC | 2017/18           */
/*****************************************************************/

#ifndef VETOR_H


/**
* registo para armazenar cada elemento (apenas uma string neste caso)
*/
typedef struct
{
  char *str;
  char *alinea_a;
  char *alinea_b;
  char *alinea_c;
  char *alinea_d;
  char alinea_correta;

} v_elemento;

/**
* este registo contem um vetor de elementos, um contador do tamanho e outro para a capacidade
*/
typedef struct
{
  /** numero de elementos do vetor */
  int tamanho;

  /** capacidade do vetor */
  int capacidade;

  /** array de elementos armazenados */
  v_elemento* elementos;

} vetor;

/**
*  cria um novo vetor com tamanho 0 e capacidade 0
*  retorno: apontador para o vetor criado
*  nota: se vetor nao foi criado retorna NULL
*/
vetor* vetor_novo();

/**
*  elimina um vetor, libertando toda a memoria ocupada
*  parametro: vec apontador para vetor
*  nota: se vec = NULL retorna sem fazer nada
*/
void vetor_apaga(vetor *vec);

/**
*  indica o o numero de elementos do vetor
*  parametro: vec apontador para vetor
*  retorno: -1 se ocorrer algum erro ou numero de elementos do vetor
*/
int vetor_tamanho(vetor *vec);



/**
*  insere um elemento na posicao especificada
*  parametro: vec apontador para vetor
*  parametro: valor string a inserir
*  parametro: pos indice do elemento onde se pretende inserir a string, se pos=tamanho ou pos=-1 insere no fim do vetor
*  retorno: -1 se ocorrer algum erro (p.ex. se valor pos indicar uma posicao invalida) ou o valor de pos se bem sucedido
*  nota: se a capacidade nao for suficiente para guardar novo elemento, devera ser aumentada para 2x em relacao a capacidade anterior; inicialmente aumenta para capacidade 1
*/
int vetor_insere(vetor* vec, const char* pergunta,const char* alinea_a,const char* alinea_b,const char* alinea_c,const char* alinea_d, int pos);

/**
*  remove o elemento da posicao especificada
*  parametro: vec apontador para vetor
*  parametro: pos posicao
*  retorno: -1 se ocorrer algum erro (p.ex. se valor pos indicar uma posicao invalida) ou 0 se bem sucedido
*/
//int vetor_remove(vetor* vec, int pos);

/**
*  atribui o valor especificado a uma posicao
*  parametro: vec apontador para vetor
*  parametro: pos posicao onde colocar elemento
*  parametro: str string pretendida
*  retorno: -1 se ocorrer algum erro (p.ex. se valor pos indicar uma posicao invalida) ou pos se bem sucedido
*/
//int vetor_atribui(vetor *vec, int pos, const char* str);

/**
*  devolve a posicao do elemento especificado
*  parametro: vec apontador para vetor
*  parametro: str string pretendida
*  retorno: posicao do elemento ou -1 se ocorrer algum erro ou nao encontrar elemento
*/
//int vetor_pesquisa(vetor *vec, const char* str);

/**
*  ordena um vetor por ordem alfabetica
*  parametro: vec apontador para vetor
*  retorno: -1 se ocorrer um erro ou 0 se for bem sucedido
*/
//int vetor_ordena(vetor *vec);

#define VETOR_H
#endif
