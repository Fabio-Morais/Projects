/*****************************************************************/
/*          Biblioteca vetor | PROG2 | MIEEC | 2017/18           */
/*****************************************************************/

#include "vetor.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

vetor* vetor_novo()
{
	vetor* vec;

	/* aloca memoria para a estrutura vetor */
	vec = (vetor*)malloc(sizeof(vetor));
	if(vec == NULL)
	return NULL;

	vec->tamanho = 0;
	vec->capacidade = 0;
	vec->elementos = NULL;

	return vec;
}

void vetor_apaga(vetor* vec)
{
	int i;

	if(vec == NULL)
	return;

	/* liberta memoria de cada string */
	for (i = 0; i < vec->tamanho; i++)
	{
		free(vec->elementos[i].str);
		free(vec->elementos[i].alinea_a);
		free(vec->elementos[i].alinea_b);
		free(vec->elementos[i].alinea_c);
		free(vec->elementos[i].alinea_d);
	}

	/* liberta memoria dos apontares para as strings */
	free(vec->elementos);

	/* liberta memoria da estrutura vetor */
	free(vec);
}

//int vetor_atribui(vetor* vec, int pos, const char* valor)
//{
//	unsigned int len_valor;
//
//	if (vec == NULL || pos < 0 || pos >= vec->tamanho)
//	return -1;
//
//	len_valor = strlen(valor);
//
//	/* reserva mais espaco se necessario */
//	if(len_valor > strlen(vec->elementos[pos].str))
//	{
//		vec->elementos[pos].str = (char*)realloc(vec->elementos[pos].str, (len_valor+1)*sizeof(char));
//		if(vec->elementos[pos].str == NULL)
//		return -1;
//	}
//
//	/* copia valor */
//	strcpy(vec->elementos[pos].str, valor);
//
//	return pos;
//}

int vetor_tamanho(vetor* vec)
{
	if(vec == NULL)
	return -1;

	return vec->tamanho;
}



int vetor_insere(vetor* vec, const char* pergunta,const char* alinea_a,const char* alinea_b,const char* alinea_c,const char* alinea_d, int pos)
{
	int i;

	if(vec == NULL || pos < -1 || pos > vec->tamanho)
		return -1;

	/* aumenta elementos do vetor se capacidade nao for suficiente */
	if(vec->tamanho == vec->capacidade)
	{
		if(vec->capacidade == 0)
		vec->capacidade = 1;
		else
		vec->capacidade *= 2;

		vec->elementos = (v_elemento*)realloc(vec->elementos, vec->capacidade * sizeof(v_elemento));
		if(vec->elementos == NULL)
		return -1;
	}

	/* se pos=-1 insere no fim do vetor */
	if(pos == -1)
		pos = vec->tamanho;

	/* copia todos os elementos a partir da posicao pos ate' ao fim do vetor para pos+1 */
	for(i=vec->tamanho-1; i>=pos; i--)
	{
		vec->elementos[i+1] = vec->elementos[i];
	}

	/* aloca espaco para a nova string na posicao pos */
	vec->elementos[pos].str = (char*)calloc(strlen(pergunta)+1, sizeof(char));
	vec->elementos[pos].alinea_a = (char*)calloc(strlen(alinea_a)+1, sizeof(char));
	vec->elementos[pos].alinea_b = (char*)calloc(strlen(alinea_b)+1, sizeof(char));
	vec->elementos[pos].alinea_c = (char*)calloc(strlen(alinea_c)+1, sizeof(char));
	vec->elementos[pos].alinea_d = (char*)calloc(strlen(alinea_d)+1, sizeof(char));
	if(vec->elementos[pos].str == NULL || vec->elementos[pos].alinea_a==NULL || vec->elementos[pos].alinea_b==NULL || vec->elementos[pos].alinea_c==NULL || vec->elementos[pos].alinea_d==NULL)
	return -1;


        if(alinea_a[0]=='x')
       {
        vec->elementos[pos].alinea_correta = 'a';
        alinea_a=(alinea_a+1);
       }
        if(alinea_b[0]=='x')
       {
        vec->elementos[pos].alinea_correta = 'b';
        alinea_b=(alinea_b+1);
       }
        if(alinea_c[0]=='x')
       {
        vec->elementos[pos].alinea_correta = 'c';
        alinea_c=(alinea_c+1);
       }
        if(alinea_d[0]=='x')
       {
        vec->elementos[pos].alinea_correta = 'd';
        alinea_d=(alinea_d+1);
       }




	/* copia pergunta */
	strcpy(vec->elementos[pos].str, pergunta);
	strcpy(vec->elementos[pos].alinea_a, alinea_a);
	strcpy(vec->elementos[pos].alinea_b, alinea_b);
	strcpy(vec->elementos[pos].alinea_c, alinea_c);
	strcpy(vec->elementos[pos].alinea_d, alinea_d);


	vec->tamanho++;

	return pos;
}

//int vetor_remove(vetor* vec, int pos)
//{
//	int i;
//
//	if(vec == NULL || pos < 0 || pos >= vec->tamanho)
//	return -1;
//
//	/* liberta string na posicao a remover */
//	free(vec->elementos[pos].str);
//
//	/* copia todos os elementos a partir da posicao pos+1 ate' ao fim do vetor para pos */
//	for(i=pos+1; i<vec->tamanho; i++)
//	{
//		vec->elementos[i-1] = vec->elementos[i];
//	}
//
//	vec->tamanho--;
//
//	return 0;
//}

//int vetor_pesquisa(vetor* vec, const char* valor)
//{
//	int i;
//
//	if(vec == NULL)
//	return -1;
//
//	/* pesquisa sequencial */
//	for (i = 0; i < vec->tamanho; i++)
//	{
//		if (strcmp(vec->elementos[i].str, valor) == 0)
//		return i;
//	}
//
//	return -1;
//}

//int vetor_ordena(vetor* vec)
//{
//	int i, j;
//	char *tmp;
//
//	if(vec == NULL)
//	return -1;
//
//	/* ordenacao por insercao */
//	for (i = 1; i < vec->tamanho; i++)
//	{
//		tmp = vec->elementos[i].str;
//		for (j = i; j > 0 && strcmp(tmp, vec->elementos[j-1].str) < 0; j--)
//		{
//			vec->elementos[j] = vec->elementos[j-1];
//		}
//		vec->elementos[j].str = tmp;
//	}
//
//	return 0;
//}
