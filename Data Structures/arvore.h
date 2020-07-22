#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *esq;
    struct node *dir;
} ARVB;

ARVB* busca(ARVB* , int );
ARVB* cria(int);
void insere(ARVB** , int); 
void imprime(ARVB* );
void remover(ARVB**, int);
void substituiMenorADireita(ARVB** raiz, ARVB** sucessor);
int altura(ARVB* );
