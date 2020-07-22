#ifndef _TRAB_H
#define _TRAB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	Estrutura para armazenar as caixas
*/
typedef struct caixas {
	char *vectorBolas; // vetor para guardar o(s) nome(s) da(s) bola(s)
	int numBolas; // Guarda numero total de bolas que a caixa possui
	struct caixas *proximaCaixa; // ponteiro para a proxima caixa
} CAIXAS;

/*
	No cabeca 
*/
typedef struct node{
	CAIXAS *inicio; 
} NODE;

NODE *inicializaNode(int numBolas);

void programa(NODE *);

CAIXAS *preencheCaixa(int numBolas);

void novaCaixa(NODE *boxes, int numBolas);

void imprime(NODE *boxes);

int fatorial(int n);

void geraCombinacoes(NODE *boxes, CAIXAS *box);

void permute(NODE *inicio, CAIXAS *box, int i, int numBolas);

#endif